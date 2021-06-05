// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class SWH_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();


	UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Damage")
	int32 TotalDamage;

	UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Damage")
	float DamageTimeInSeconds;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category = "Damage")
	float DamagePerSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	FString str;

	UFUNCTION(BlueprintNativeEvent, Category = "Damage")
	void CallFromCpp();
	virtual void CallFromCpp_Implementation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void FunctionName();
	
	UFUNCTION(BlueprintCallable, Category = "Damage")
	void CalculateDPS();

	virtual void PostInitProperties() override;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;


};
