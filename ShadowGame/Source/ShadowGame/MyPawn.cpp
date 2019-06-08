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
	if (bBufferSprint) {
		Sprint();
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
	if (Cast<UCustomMovement>(MovementComp) && CheckGrounded()) {
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
		if (GetWorld()->LineTraceSingleByChannel(hitResultTrace, GetActorLocation(), GetActorLocation() - RootComponent->GetUpVector() * 100,
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
	if (CheckGrounded()) {
		bBufferSprint = false;
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
	else {
		bBufferSprint = true;
	}
}
void AMyPawn::StopSprinting() {
	bSprint = false;
	bBufferSprint = false;
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
float AMyPawn::PStealth(FVector location, float lumens) {
	float mult = 1;
	FHitResult outHit;
	FCollisionQueryParams CollisionParams;
	FVector Start;
	FVector End;
	UCapsuleComponent* Capsule = Cast<UCapsuleComponent>(RootComponent);
	if (Capsule != nullptr) {
		float capsuleHeight = currentHeight;
		float capsuleRadius = Capsule->GetScaledCapsuleRadius();
		for (float f = -capsuleHeight; f <= capsuleHeight; f += capsuleHeight) {
			Start = GetActorLocation() + FVector(0, 0, f);
			End = location;
			bool isHit = GetWorld()->LineTraceSingleByChannel(outHit, Start, End, ECC_Visibility, CollisionParams);
			if (outHit.bBlockingHit) {
				mult -= 0.2;
			}
			//DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 1);
		}
		for (float f = -capsuleRadius; f <= capsuleRadius; f += 2 * capsuleRadius) {
			Start = RootComponent->GetRightVector() * f + GetActorLocation();
			End = location;
			bool isHit = GetWorld()->LineTraceSingleByChannel(outHit, Start, End, ECC_Visibility, CollisionParams);
			if (outHit.bBlockingHit) {
				mult -= 0.2;
			}
			//DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 1);
		}
		//for the top bottom, left, right, and center of the player, do a line check. If there's something in the way subtract 0.2 from the multiplier cuz 5 points
		//if there's nothing in the don't do anything.
	}
	else {
		mult = 0;
	}
	return FMath::Sqrt(lumens * 10000/ (4 * PI * FMath::Pow((GetActorLocation() - location).Size(), 2))) * mult;
}
float AMyPawn::SStealth(FVector spotlight, float inner, float outer, FRotator spotAngle, float lumens) {
	float totalMult = 0;
	float mult;
	float value;
	float totalValue = 0;
	FVector vector = UKismetMathLibrary::CreateVectorFromYawPitch(spotAngle.Yaw, spotAngle.Pitch, 1.f);
	FHitResult outHit;
	FCollisionQueryParams CollisionParams;
	FVector Start;
	FVector End;
	FVector LVector;
	UCapsuleComponent* Capsule = Cast<UCapsuleComponent>(RootComponent);
	if (Capsule != nullptr) {
		float capsuleHeight = Capsule->GetScaledCapsuleHalfHeight();
		float capsuleRadius = Capsule->GetScaledCapsuleRadius();
		for (float f = -capsuleHeight; f <= capsuleHeight; f += capsuleHeight) {
			Start = spotlight;
			End = GetActorLocation();
			LVector = Start - End;
			float angle = -(acos((vector.X * LVector.X + vector.Y * LVector.Y + vector.Z * LVector.Z) / (vector.Size() * LVector.Size())) * 180 / PI - 180);
			//DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 1);
			if (angle <= outer && !outHit.bBlockingHit) {//if it is within the inner angle and there's nothing in the way
				if (angle <= inner) {
					mult = 0.2;//inner angle
				}
				else {
					mult = 0.2 * (angle - outer) / (angle - inner);//outer angle.
				}
			}
			else {
				mult = 0;
			}//if it is outside or there's something in the way
			value = lumens / (4 * PI * LVector.Size() * angle / 360);//calculate lumens
			totalValue += value;
			totalMult += mult;
		}
		//GEngine->AddOnScreenDebugMessage(-1, .1f, FColor::Green, FString::SanitizeFloat(angle));
		//DrawDebugLine(Get(), Start, End, FColor::Green, false, 1, 0, 1);
		for (float f = -capsuleRadius; f <= capsuleRadius; f += 2 * capsuleRadius) {
			Start = spotlight;
			End = GetActorLocation();
			LVector = Start - End;
			float angle = -(acos((vector.X * LVector.X + vector.Y * LVector.Y + vector.Z * LVector.Z) / (vector.Size() * LVector.Size())) * 180 / PI - 180);
			if (angle <= outer && !outHit.bBlockingHit) {
				if (angle <= inner) {
					mult = 0.2;
				}
				else {
					mult = 0.2 * (angle - inner) / (angle - inner);
				}
			}
			else {
				mult = 0;
			}
			//DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 1);
			value = lumens / (4 * PI * LVector.Size() * angle / 360);
			totalValue += value;
			totalMult += mult;
		}
		//GEngine->AddOnScreenDebugMessage(-1, .1f, FColor::Green, FString::SanitizeFloat(angle));
	}
	return totalValue;
}
void AMyPawn::AddVis(float value) {
	visibility += value;
}
