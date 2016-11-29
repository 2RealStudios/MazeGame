// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ItemCollidable.h"
#include "Inventory.h"
#include "GameFramework/Character.h"
#include "MazePlayer.generated.h"

UCLASS()
class MAZEGAME_API AMazePlayer : public ACharacter, public ItemCollidable
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonCameraComponent;

public:
	// Sets default values for this character's properties
	AMazePlayer();

	bool hasItem(Item& item);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//handles moving forward/backward
	UFUNCTION()
		void MoveForward(float Val);
	//handles strafing
	UFUNCTION()
		void Strafe(float Val);
	
	UFUNCTION()
		void PadTurn(float Rate);

	UFUNCTION()
		void PadLookup(float Rate);

	virtual int OnItemCollide(Item& item, int amount) override;
		
private:
	Inventory PlayerInventory;
};
