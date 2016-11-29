// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "Inventory.h"

Inventory::Inventory() : Inventory(16)
{
}

Inventory::Inventory(int maxSize)
{
	this->MaxSize = maxSize;
}

Inventory::~Inventory()
{
	Items.clear();
}

int Inventory::AddItem(Item &item, int amount)
{
	if (Items.find(item) == Items.end() || amount < 0)
		Items[item] = 0;
	int newSize = Items[item] + amount;
	int ret = 0;
	if (newSize > MaxSize) 
	{
		ret = newSize - MaxSize;
		newSize = MaxSize;
	}
	Items[item] = newSize;
	if (Items[item] <= 0)
	{
		Items.erase(item);
		return amount;
	}

	return ret;
}

int Inventory::RemoveItem(Item &item, int amount)
{
	if (Items.find(item) != Items.end() || amount < 0)
		return 0;

	int currentCount = Items[item];
	
	if (currentCount <= amount)
	{
		Items.erase(item);
		return currentCount;
	}

	Items[item] = currentCount - amount;
	
	return amount;

}

int Inventory::GetItemCount(Item &item)
{
	if (Items.find(item) != Items.end())
		return Items[item];
	return 0;
}

//std::unordered_set<Item, char, hash_item, equal_item> getItems()

