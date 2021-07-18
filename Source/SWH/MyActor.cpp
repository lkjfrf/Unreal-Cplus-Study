// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "SWH.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Log, TEXT("ConstructorLOL"));
	
	TotalDamage = 200;
	DamageTimeInSeconds = 100;
	str = TEXT("Testlol");
}

void AMyActor::CallFromCpp_Implementation()
{
	str.Append(TEXT("_Implementation"));
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	CallFromCpp();

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AMyActor::FunctionName()
{

}

void AMyActor::CalculateDPS()
{
	DamagePerSeconds = TotalDamage / DamageTimeInSeconds;
}

void AMyActor::PostInitProperties()
{
	Super::PostInitProperties();
	CalculateDPS();
}

void AMyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	CalculateDPS();
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

