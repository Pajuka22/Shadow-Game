// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPawn.h"
#include "PLStealth.generated.h"

UCLASS()
class SHADOWGAME_API APLStealth : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	class UPointLightComponent* Source;

public:	
	// Sets default values for this actor's properties
	APLStealth();

	class AMyPawn* Player;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool HitLast = false;
	AMyPawn::Visibility value;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
