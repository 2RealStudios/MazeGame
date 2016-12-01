// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Item.generated.h"

/**
 * 
 */
UCLASS()
class MAZEGAME_API UItem : public UObject
{
	GENERATED_BODY()
	
	public:

		UItem(const class FObjectInitializer& ObjectInitializer);
		//Item(int idNum);
		~UItem();
		int ID;
};

struct UItemMapKey
{
	TWeakObjectPtr<UItem> Item;
	UItemMapKey(const UItem* inItem) : Item(inItem) {}

	bool operator==(const struct UItemMapKey& item) const
	{
		return Item.Get()->ID == item.Item.Get()->ID;
	}

	friend FORCEINLINE uint32 GetTypeHash(const UItemMapKey& item)
	{
		return item.Item.Get()->ID;
	}

};

/*inline bool operator==(const UItemMapKey& KeyA, const UItemMapKey& KeyB)
{
	UItem* ItemA = KeyA.Item.Get();
	UItem* ItemB = KeyB.Item.Get();
	if (ItemA == nullptr)
	{
		return (ItemB != nullptr);
	}
	else if (ItemB == nullptr)
	{
		return false;
	}
	return ItemB->ID == ItemA->ID;
}
inline uint32 GetTypeHash(const UItemMapKey& Key)
{
	return GetTypeHash(Key.Item.Get()->ID);
}*/


