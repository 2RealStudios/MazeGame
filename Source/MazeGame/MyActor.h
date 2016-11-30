// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PlayerInteractable.h"
#include "MazePlayer.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MAZEGAME_API AMyActor : public AActor, public IPlayerInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "PlayerInteraction")
		bool OnPlayerInteract(AMazePlayer* player);
	virtual bool OnPlayerInteract_Implementation(AMazePlayer* player) override;
	
};
