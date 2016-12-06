// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ItemCollidable.h"
#include "Inventory.h"
#include "Components/WidgetInteractionComponent.h"
#include "GameFramework/Character.h"
#include "MazePlayer.generated.h"

UCLASS()
class MAZEGAME_API AMazePlayer : public ACharacter, public IItemCollidable
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UWidgetInteractionComponent* WidgetInteraction;

	// Sets default values for this character's properties
	AMazePlayer();

	bool hasItem(UItem& item);

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

	/** Finds the first actor in front of the place in a given distance*/
	AActor* FindFocusedActor(int distance);

	//virtual int OnItemCollide(Item& item, int amount) override;
	
	UFUNCTION()
		void Interact();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ItemCollision")
		int OnItemCollide(UItem* item, int amount);
	virtual int OnItemCollide_Implementation(UItem* item, int amount) override;
	
private:

	Inventory PlayerInventory;
	FCollisionQueryParams TraceParams;
};
