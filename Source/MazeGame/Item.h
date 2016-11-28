// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class MAZEGAME_API Item
{
	public:
		Item(int idNum);
		~Item();
		const int ID;
};

struct hash_item {
	size_t operator()(const Item &item) const
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

