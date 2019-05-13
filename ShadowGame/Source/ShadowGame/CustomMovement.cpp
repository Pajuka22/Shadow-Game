#include "CustomMovement.h"
#include "CoreMinimal.h"
#include "Runtime/Engine/Public/CollisionQueryParams.h"
#include "Components/CapsuleComponent.h"

void UCustomMovement::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Make sure that everything is still valid, and that we are allowed to move.
	if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
	{
		return;
	}

	// Get (and then clear) the movement vector that we set in ACollidingPawn::Tick
	FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * 300.0f;
	downVel += UpdatedComponent->GetUpVector() * -300 * DeltaTime;
	GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Green, FString::SanitizeFloat(downVel.Size()));
	FHitResult outHit;
	FVector Start = GetActorLocation();
	FVector End = GetActorLocation() + UpdatedComponent->GetUpVector() * -100;
	UCapsuleComponent* capsule = Cast<UCapsuleComponent>(UpdatedComponent);
	if (capsule != nullptr) {
		End = GetActorLocation() + UpdatedComponent->GetUpVector() * -1.5 * capsule->GetScaledCapsuleHalfHeight();

	}
	FCollisionQueryParams CollisionParams;
	bool isHit = GetWorld()->LineTraceSingleByChannel(outHit, Start, End, ECC_Visibility, CollisionParams);
	if (isHit && outHit.bBlockingHit) {
		float angle = FMath::Acos(FVector::DotProduct(UpdatedComponent->GetUpVector(), outHit.ImpactNormal));
		GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Yellow, FString::SanitizeFloat(angle * 180 / PI));
		downVel = FVector(0, 0, 0);
	}
	DesiredMovementThisFrame += downVel;
	if (!DesiredMovementThisFrame.IsNearlyZero())
	{	
		//FHitResult Hit = FHitResult(ForceInit);
		SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, outHit);

		// If we bumped into something, try to slide along it
		if (outHit.IsValidBlockingHit())
		{
			//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "U SUCK");
			SlideAlongSurface(DesiredMovementThisFrame, 1.f - outHit.Time, outHit.Normal, outHit);
		}
	}
};