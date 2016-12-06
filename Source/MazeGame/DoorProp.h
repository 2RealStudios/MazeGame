// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PlayerInteractable.h"
#include "GameFramework/Actor.h"
#include "DoorProp.generated.h"

UCLASS()
class MAZEGAME_API ADoorProp : public AActor, public PlayerInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoorProp();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Static Mesh for DoorProp
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SM_DoorPropMesh;

	// Scene
	UPROPERTY(EditAnywhere)
		USceneComponent* DoorPropRoot;

	UPROPERTY(EditAnywhere)
		UShapeComponent* DoorPropBox;

	UFUNCTION()
		void OnPlayerInteract(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
