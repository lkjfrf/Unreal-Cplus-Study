// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

#include "MyTriggerBox.h"
#include "DrawDebugHelpers.h"

AMyTriggerBox::AMyTriggerBox()
{
	SetActorHiddenInGame(false);
	OnActorBeginOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapBegin);

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	CopiedSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CopiedSkeletalMesh"));
	//ConstructorHelpers::FObjectFinder<UStaticMesh>Piramid(TEXT("/Game/StarterContent/Shapes/Shape_QuadPyramid"));

	CopiedSkeletalMesh->SetupAttachment(RootComponent);
	
}

void AMyTriggerBox::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this)) {
		// print to screen using above defined method when actor enters trigger box
		print("Overlap Begin");
		printFString("Overlapped Actor = %s", *OverlappedActor->GetName());
		printFString("Other Actor = %s", *OtherActor->GetName());
		
		ATP_ThirdPersonCharacter* third = Cast<ATP_ThirdPersonCharacter>(OtherActor);
		printFString("third = %s", *third->GetName());

		UMeshComponent* thirdMesh = third->GetMesh();
		printFString("thirdMesh = %s", *thirdMesh->GetName());
		
		CopiedSkeletalMesh = third->ThirdPersonSkeletal;
		printFString("CopiedMesh = %s", *CopiedSkeletalMesh->GetName());
		
		CopiedSkeletalMesh->SetupAttachment(RootComponent);
	}
}
