// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "TP_ThirdPersonCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "MyTriggerBox.generated.h"


UCLASS()
class SWH_API AMyTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

	AMyTriggerBox();

public:
	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedComp, class AActor* OtherActor);

	UPROPERTY()
	USceneComponent* Root;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mesh")
	class UMeshComponent* TriggerMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mesh")
	class USkeletalMeshComponent* CopiedSkeletalMesh;


//	ATP_ThirdPersonCharacter* ThirdPersonCharacter = Cast<ATP_ThirdPersonCharacter>(ThirdPersonCharacter);
};

