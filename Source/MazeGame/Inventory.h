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
    
    int AddItem(Item &item, int amount);
    int RemoveItem(Item &item, int amount);
    int GetItemCount(Item &item);
   // std::unordered_set<Item,int,hash_item, equal_item> getItems();
    
private:
    int MaxSize;
    std::unordered_map<Item, int, hash_item, equal_item> Items;
};




