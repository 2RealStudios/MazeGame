// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <unordered_map>
#include <unordered_set>
#include "Item.h"

// Used by the unordered_map to create a hash of the Item (which is the ID)
struct hash_item {
    size_t operator()(const Item &item ) const
    {
        return std::hash<int>()(item.ID);
    }
};

// Used by the unordered_map to check the equality of two Items (which based on the IDs)
struct equal_item {
public:
    bool operator()(const Item& item, const Item& item2) const {
        return (item.ID == item2.ID);
    }
};

class MAZEGAME_API Inventory
{
public:
	Inventory(int  MaxSize);
    
	~Inventory();
    
    int addItem(Item &item, int amount);
    int removeItem(Item &item, int amount);
    int getItemCount(Item &item);
    std::unordered_set<Item,char,hash_item, equal_item> getItems();
    
private:
    int MaxSize;
    std::unordered_map<Item, char, hash_item, equal_item> grade_list;
};




