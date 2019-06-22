// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DLStealth.generated.h"

UCLASS()
class SHADOWGAME_API ADLStealth : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		class UDirectionalLightComponent* Source;

public:	
	// Sets default values for this actor's properties
	ADLStealth();

	class AMyPawn* Player;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool HitLast = false;
	float value = 0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
