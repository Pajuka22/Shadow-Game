// Fill out your copyright notice in the Description page of Project Settings.


#include "DLStealth.h"
#include "Runtime/Engine/Classes/Components/DirectionalLightComponent.h"
#include "Runtime/Engine/Classes/Engine/Scene.h"
#include "Engine/World.h"
#include "MyPawn.h"

// Sets default values
ADLStealth::ADLStealth()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Source = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("Source"));
	Source->Intensity = 3;
}

// Called when the game starts or when spawned
void ADLStealth::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADLStealth::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Player = Cast<AMyPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (Player != nullptr) {
		if (HitLast) {
			Player->AddVis(-value);
		}
		value = Player->DStealth(GetActorForwardVector(), Source->Intensity, 5000);
		HitLast = value >= 0;
		Player->AddVis(value);
	}
}

