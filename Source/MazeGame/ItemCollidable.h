// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Item.h"  
 
class MAZEGAME_API ItemCollidable
{
public:
	ItemCollidable();

	virtual int OnItemCollide(Item& item, int amount) = 0;

};
