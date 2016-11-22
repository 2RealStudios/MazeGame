// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MazePlayer.h"

class MAZEGAME_API PlayerInteractable
{
public:
	PlayerInteractable();

	virtual int onPlayerInteract(const AMazePlayer& player) = 0;
};
