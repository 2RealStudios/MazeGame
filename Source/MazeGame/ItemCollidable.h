// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Item.h"
#include "ItemCollidable.generated.h"

/**
 * 
 */
UINTERFACE(BlueprintType)
class MAZEGAME_API UItemCollidable: public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class MAZEGAME_API IItemCollidable
{
	GENERATED_IINTERFACE_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ItemCollision")
		int OnItemCollide(class UItem* item, int amount);

};