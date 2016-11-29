// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#ifndef __PLAYERINTERACTABLE_H__   // if x.h hasn't been included yet...
//#define __PLAYERINTERACTABLE_H__   //   #define this so the compiler knows it has been included


#include "MazePlayer.h"

class MAZEGAME_API PlayerInteractable
{
public:
	PlayerInteractable();

	virtual int OnPlayerInteract(AMazePlayer& player) = 0;
};

//#endif 