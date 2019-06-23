// Fill out your copyright notice in the Description page of Project Settings.


#include "SLStealth.h"
#include "Runtime/Engine/Classes/Components/SpotLightComponent.h"
#include "Runtime/Engine/Classes/Engine/Scene.h"
#include "Engine/World.h"
#include "MyPawn.h"
// Sets default values
ASLStealth::ASLStealth()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Source = CreateDefaultSubobject<USpotLightComponent>(TEXT("Light"));
	Source->IntensityUnits = ELightUnits::Lumens;
	Source->Intensity = 5000;
}

// Called when the game starts or when spawned
void ASLStealth::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASLStealth::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AMyPawn* Player = Cast<AMyPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (HitLast) {
		Player->SubVis(value);
	}
	value = Player->SStealth(GetActorLocation(), Source->InnerConeAngle, Source->OuterConeAngle, Source->AttenuationRadius, GetActorForwardVector(), Source->Intensity);
	HitLast = value.Vis >= 0;
	Player->AddVis(value);
}

