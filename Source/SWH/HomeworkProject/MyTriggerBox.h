// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MyTriggerBox.generated.h"


UCLASS()
class SWH_API AMyTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

	AMyTriggerBox();

public:
	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedComp, class AActor* OtherActor);

	UFUNCTION()
	void OnOverlapEnd(class AActor* OverlappedComp, class AActor* OtherActor);
};
