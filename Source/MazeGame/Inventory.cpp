// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "Inventory.h"

Inventory::Inventory(int maxSize)
{
    this->MaxSize=maxSize;
    Item item(1);
    grade_list[item] = 0;
    
}

Inventory::~Inventory()
{
}
