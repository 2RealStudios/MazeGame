// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <unordered_map>
#include <unordered_set>
#include "Item.h"


class MAZEGAME_API Inventory
{
public:
	Inventory();

	Inventory(int  MaxSize);
    
	~Inventory();
    
	/** Add item to inventory returns the amount that was not added */
    int AddItem(UItem &item, int amount);

	/** Remove item from inventory returns the amount that was removed*/
	int RemoveItem(UItem &item, int amount);

	/** Returns the amount of the item this inventory contains */
	int GetItemCount(UItem &item);
	
	//std::unordered_set<Item,int,hash_item, equal_item> getItems();
    
private:
    int MaxSize;
	TMap<UItemMapKey, uint32 > Items;
};






