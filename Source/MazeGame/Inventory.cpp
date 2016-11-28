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
}


int Inventory::AddItem(Item &item, int amount)
{
	if (Items.find(item) == Items.end())
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
	if (Items.find(item) != Items.end())
		return 0;
	int newSize = Items[item] - amount;
	int ret = amount;
	if (newSize > MaxSize)
	{
		ret = newSize - MaxSize;
		newSize = MaxSize;
	}
	Items[item] = newSize;
	if (Items[item] <= 0)
	{
		Items.erase(item);
		return newSize;
	}
	return ret;

}

int Inventory::GetItemCount(Item &item)
{
	if (Items.find(item) != Items.end())
		return Items[item];
	return 0;
}

//std::unordered_set<Item, char, hash_item, equal_item> getItems()

