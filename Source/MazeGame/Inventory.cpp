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
	Items.Empty();
}

int Inventory::AddItem(UItem &item, int amount)
{
	UItem *ptr;
	ptr = &item;
	UItemMapKey key = UItemMapKey(ptr);
	if (Items.Contains(key) || amount < 0)
		Items[key] = 0;
	int newSize = Items[key] + amount;
	int ret = 0;
	if (newSize > MaxSize) 
	{
		ret = newSize - MaxSize;
		newSize = MaxSize;
	}
	Items.Add(key, newSize);
	if (Items[key] <= 0)
	{
		Items.Remove(key);
		return amount;
	}

	return ret;
}

int Inventory::RemoveItem(UItem &item, int amount)
{
	UItem *ptr;
	ptr = &item;
	UItemMapKey key = UItemMapKey(ptr);

	if (Items.Contains(key) || amount < 0)
		return 0;

	int currentCount = Items[key];
	
	if (currentCount <= amount)
	{
		Items.Remove(key);
		return currentCount;
	}

	Items.Add(key, currentCount - amount);
	
	return amount;

}

int Inventory::GetItemCount(UItem &item)
{
	UItem *ptr;
	ptr = &item;
	UItemMapKey key = UItemMapKey(ptr);
	if (Items.Contains(key))
		return Items[key];
	return 0;
}

//std::unordered_set<UItem, char, hash_UItem, equal_UItem> getItems()

