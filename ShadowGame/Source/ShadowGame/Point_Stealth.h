// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Point_Stealth.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHADOWGAME_API UPoint_Stealth : public UActorComponent
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		class USpotlightComponent* Source;

public:	
	// Sets default values for this component's properties
	UPoint_Stealth();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
