// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "SWH.h"

// Sets default values
AMyActor::AMyActor() : TotalDamage(200)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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

	UE_LOG(LogTemp, Log, TEXT("Log Message"));
	UE_LOG(LogTemp, Error, TEXT("Error Message"));
	UE_LOG(LogTemp, Display, TEXT("Display1121 Message"));
	//UE_LOG(MyLogCategorylolz, Warning, TEXT("meememm ewofjewoefaiwfejoiw"));


	FString CharacterName = TEXT("WooHyun");
	UE_LOG(LogTemp, Log, TEXT("Character Name = %s"), *CharacterName);
	bool isAttackable = true;
	int hp = 100;
	float Attackspeed = 1.0f;
	UE_LOG(LogTemp, Log, TEXT("okok : %s"), isAttackable ? TEXT("True") : TEXT("False"));
	UE_LOG(LogTemp, Log, TEXT("%d, %f, %s"), hp, Attackspeed, TEXT("Complite"));


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

