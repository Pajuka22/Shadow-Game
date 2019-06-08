// Fill out your copyright notice in the Description page of Project Settings.


#include "Point_Stealth.h"

// Sets default values for this component's properties
UPoint_Stealth::UPoint_Stealth()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPoint_Stealth::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPoint_Stealth::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	
}

