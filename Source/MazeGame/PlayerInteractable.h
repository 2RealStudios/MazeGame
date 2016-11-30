// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MazePlayer.h"
#include "PlayerInteractable.generated.h"

/**
 * 
 */
UINTERFACE(BlueprintType)
class MAZEGAME_API UPlayerInteractable : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class MAZEGAME_API IPlayerInteractable
{
	GENERATED_IINTERFACE_BODY()

public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="PlayerInteraction")
		bool OnPlayerInteract(AMazePlayer* player);

};
