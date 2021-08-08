// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

#include "MyTriggerBox.h"
#include "DrawDebugHelpers.h"

AMyTriggerBox::AMyTriggerBox()
{
	SetActorHiddenInGame(false);
	OnActorBeginOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapBegin);
}

void AMyTriggerBox::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this)) {
		// print to screen using above defined method when actor enters trigger box
		print("Overlap Begin");
		printFString("Overlapped Actor = %s", *OverlappedActor->GetName());
		printFString("Other Actor = %s", *OtherActor->GetName());

		//UStaticMeshComponent* MeshComponent = *OtherActor->Get;
		
		//AttachToComponent(this, );

	}
}

void AMyTriggerBox::OnOverlapEnd(AActor* OverlappedComp, AActor* OtherActor)
{
}
