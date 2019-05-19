// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPawn.h"
#include "Components/InputComponent.h"
#include "Runtime/HeadMountedDisplay/Public/MotionControllerComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/CapsuleComponent.h"
#include "CustomMovement.h"
#include "Runtime/Engine/Classes/GameFramework/FloatingPawnMovement.h"
#include "ConstructorHelpers.h"
#include "Runtime/Core/Public/Math/Vector.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"
#include "Runtime/Core/Public/Math/TransformNonVectorized.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	UCapsuleComponent* Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Root Comp"));
	RootComponent = Capsule;
	Capsule->SetCollisionProfileName(TEXT("Pawn"));

	VisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisibleComponent->SetupAttachment(RootComponent);

	MyCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	MyCamera->SetupAttachment(RootComponent);
	MyCamera->SetRelativeLocation(FVector(0, 0, 50));
	MyCamera->SetRelativeRotation(FRotator(0, 0, 0));
		

	MovementComp = CreateDefaultSubobject<UCustomMovement>(TEXT("Movement"));
	MovementComp->UpdatedComponent = RootComponent;


	ForwardVel = 0;
	RightVel = 0;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	RootComponent->SetRelativeRotation(FRotator(0, 0, 0));
	SetActorRotation(FRotator(0, 0, 0));
	cameraRot = 0;

	startHeight = normalHeight;
	endHeight = normalHeight;
	currentHeight = startHeight;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*if (!CurrentVelocity.IsZero()) {
		SetActorLocation(GetActorLocation() + CurrentVelocity * DeltaTime);
	}*/

	MovementComp->Velocity = FVector();
	SetActorRotation(GetActorRotation() + FRotator(0, 0, 0));
	//DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + 100 * RootComponent->GetUpVector(), FColor::Red, false, 5.f, 0, 1);
	if (Jumping && !CheckGrounded()) {
		EndJump = true;
	}
	if (EndJump && CheckGrounded()) {
		Jumping = false;
		EndJump = false;
		MovementComp->JumpVel = FVector(0, 0, 0);
	}
	//GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Yellow, CheckGrounded() ? "true" : "false");
	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Red, FString::SanitizeFloat(currentHeight));
	//GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Green, GetActorLocation().ToString());
	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Red, ShadowSneak ? "true" : "false");
	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Green, bCrouch ? "true" : "false");
	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Blue, bSprint ? "true" : "false");
	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Yellow, FString::SanitizeFloat(endHeight));
	UCapsuleComponent* Capsule = Cast<UCapsuleComponent>(RootComponent);
	if (Capsule != nullptr && currentHeight != endHeight) {
		currentHeight += addHeight * DeltaTime;
		if (currentHeight == endHeight || addHeight > 0 ? currentHeight + addHeight * DeltaTime > endHeight : currentHeight + addHeight * DeltaTime < endHeight) {
			currentHeight = endHeight;
			addHeight = 0;
		}
		else {
			Capsule->SetCapsuleHalfHeight(currentHeight);
			MyCamera->SetRelativeLocation(FVector(0, 0, currentHeight / 2));
		}
		RootComponent = Capsule;
		MovementComp->AddInputVector(RootComponent->GetUpVector() * addHeight);
	}
	if (!CheckGrounded() && ShadowSneak) {
		StartEndSneak();
	}
	if (Cast<UCustomMovement>(MovementComp)) {
		if (ShadowSneak) {
			MovementComp->MovementSpeed = SneakSpeed;
		}
		else {
			if (bCrouch) {
				MovementComp->MovementSpeed = CrouchSpeed;
			}
			else {
				if (bSprint) {
					MovementComp->MovementSpeed = SprintSpeed;
				}
				else {
					MovementComp->MovementSpeed = NormalSpeed;
				}
			}
		}
		GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Green, FString::SanitizeFloat(MovementComp->MovementSpeed));
	}
	if (ShadowSneak) {
		FHitResult hitResultTrace;
		FCollisionQueryParams queryParams;

		queryParams.AddIgnoredActor(this);

		FVector under;
		FVector Start = GetActorLocation();
		FVector End = Start + GetVelocity();
		if (GetWorld()->LineTraceSingleByChannel(hitResultTrace, Start + GetActorUpVector() * 400.0f, Start - GetActorUpVector() * 2000.0f,
			ECC_Visibility, queryParams))
		{
			if (hitResultTrace.GetComponent() != nullptr) {
				if (!hitResultTrace.GetActor()->IsRootComponentMovable()) {
					under = hitResultTrace.ImpactPoint;
					FVector newUp = hitResultTrace.ImpactNormal;
					FVector newForward = FVector::CrossProduct(RootComponent->GetRightVector(), newUp);
					FVector newRight = FVector::CrossProduct(newUp, newForward);
					//Build the new transform!
					FTransform newTransform = FTransform(newForward, newRight, newUp, GetActorLocation());
					RootComponent->SetWorldRotation(FMath::Lerp(RootComponent->GetComponentRotation().Quaternion(), newTransform.GetRotation(), .05));
				}
			}
			else {
				under = hitResultTrace.ImpactPoint;
				FVector newUp = FVector(0, 0, 1);
				FVector newForward = FVector::CrossProduct(RootComponent->GetRightVector(), newUp);
				FVector newRight = FVector::CrossProduct(newUp, newForward);
				//Build the new transform!
				FTransform newTransform = FTransform(newForward, newRight, newUp, GetActorLocation());
				RootComponent->SetWorldRotation(FMath::Lerp(RootComponent->GetComponentRotation().Quaternion(), newTransform.GetRotation(), .05));
			}
		}
	}
	else {
		if (RootComponent->GetUpVector() != FVector(0, 0, 1)) {
			FVector newUp = FVector(0, 0, 1);
			FVector newForward = FVector::CrossProduct(RootComponent->GetRightVector(), newUp);
			FVector newRight = FVector::CrossProduct(newUp, newForward);
			//Build the new transform!
			FTransform newTransform = FTransform(newForward, newRight, newUp, GetActorLocation());
			RootComponent->SetWorldRotation(FMath::Lerp(RootComponent->GetComponentRotation().Quaternion(), newTransform.GetRotation(), .05));
		}
	}
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPawn::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AMyPawn::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyPawn::LookUpAtRate);
	
	PlayerInputComponent->BindAction("Sneaky", IE_Pressed, this, &AMyPawn::StartEndSneak);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyPawn::Jump);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMyPawn::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AMyPawn::StopSprinting);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AMyPawn::CrouchControl);
}
UPawnMovementComponent* AMyPawn::GetMovementComponent() const
{
	return MovementComp;
}
void AMyPawn::MoveForward(float val) {
	if (MovementComp && MovementComp->UpdatedComponent == RootComponent) {
		MovementComp->LateralVel += (GetActorForwardVector() * val * MovementComp->MovementSpeed);
	}
}
void AMyPawn::MoveRight(float val) {
	if (MovementComp && MovementComp->UpdatedComponent == RootComponent) {
		MovementComp->LateralVel += (GetActorRightVector() * val * MovementComp->MovementSpeed);
	}
}
void AMyPawn::TurnAtRate(float rate) {
	//GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, FString::SanitizeFloat(rate));
	FVector newRight = RootComponent->GetRightVector().RotateAngleAxis(5 * rate, RootComponent->GetUpVector());
	FVector newForward = RootComponent->GetForwardVector().RotateAngleAxis(5 * rate, RootComponent->GetUpVector());
	RootComponent->SetWorldTransform(FTransform(newForward, newRight, RootComponent->GetUpVector(), GetActorLocation()));
}
void AMyPawn::LookUpAtRate(float rate) {
	//MyCamera->SetRelativeRotation(MyCamera->RelativeRotation + FRotator(-rate, 0, 0));
	float addrot = 5 * rate;

	if (FMath::Acos(FVector::DotProduct(MyCamera->GetForwardVector(), RootComponent->GetUpVector())) < FMath::Abs(5 * rate * PI / 180) && addrot < 0) {
		addrot = FMath::Acos(FVector::DotProduct(MyCamera->GetForwardVector(), RootComponent->GetUpVector()));
	}
	if (FMath::Acos(FVector::DotProduct(MyCamera->GetForwardVector(), RootComponent->GetUpVector() * -1)) < FMath::Abs(5 * rate * PI / 180) && addrot > 0) {
		addrot = FMath::Acos(FVector::DotProduct(MyCamera->GetForwardVector(), -RootComponent->GetUpVector()));
	}
	//start standard working.
	FVector newUp = MyCamera->GetUpVector().RotateAngleAxis(addrot, MyCamera->GetRightVector());
	FVector newForward = MyCamera->GetForwardVector().RotateAngleAxis(addrot, MyCamera->GetRightVector());
	MyCamera->SetWorldTransform(FTransform(newForward, MyCamera->GetRightVector(), newUp, MyCamera->GetComponentLocation()));
	//end standard working

	
	//MyCamera->SetRelativeRotation(FRotator(FMath::ClampAngle(MyCamera->RelativeRotation.Pitch - 5 * rate, -90, 90), MyCamera->RelativeRotation.Yaw, MyCamera->RelativeRotation.Roll));
}
void AMyPawn::StartEndSneak() {
	ShadowSneak = !ShadowSneak;
	bCrouch = false;
	startHeight = currentHeight;
	if (ShadowSneak) {
		endHeight = sneakHeight;
		StopSprinting();
	}
	else {
		endHeight = bCrouch ? crouchHeight : normalHeight;
	}
	GetAddHeight();
	MovementComp->Shadow = ShadowSneak;
}
void AMyPawn::Sprint() {
	bSprint = true;
	startHeight = currentHeight;
	endHeight = normalHeight;
	GetAddHeight();
	if (ShadowSneak) {
		StartEndSneak();
	}
	if (bCrouch) {
		StopCrouching();
	}
}
void AMyPawn::StopSprinting() {
	bSprint = false;
}
void AMyPawn::CrouchControl() {
	if (bCrouch) {
		StopCrouching();
	}
	else {
		Crouch();
	}
}
void AMyPawn::Crouch() {
	StopSprinting();
	bCrouch = true;
	startHeight = currentHeight;
	endHeight = crouchHeight;
	ShadowSneak = false;
	GetAddHeight();
}
void AMyPawn::StopCrouching() {
	bCrouch = false;
	if (ShadowSneak) {
		StartEndSneak();
	}
	startHeight = currentHeight;
	endHeight = ShadowSneak ? sneakHeight : normalHeight;
	GetAddHeight();
}
void AMyPawn::Jump() {
	if (CheckGrounded()) {
		MovementComp->JumpVel += RootComponent->GetUpVector() * 1000;
		if (ShadowSneak) {
			StartEndSneak();
		}
		Jumping = true;
		EndJump = false;
	}
}
void AMyPawn::StopJumping() {

}
bool AMyPawn::CheckGrounded() {
	UCapsuleComponent* a  = Cast<UCapsuleComponent>(RootComponent);
	FVector Start = GetActorLocation();
	FVector End = GetActorLocation() - RootComponent->GetUpVector() * (a->GetScaledCapsuleHalfHeight() * 1.25 + 5);
	//DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 5.f, 0, 1);
	FCollisionQueryParams Params;
	FHitResult Hit;
	Params.AddIgnoredActor(this);
	bool IsHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params);
	return Hit.bBlockingHit;
}
void AMyPawn::GetAddHeight() {
	addHeight = (endHeight - startHeight) / HeightInterpTime;
}
