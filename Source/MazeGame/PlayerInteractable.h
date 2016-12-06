// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MazePlayer.h"

class MAZEGAME_API PlayerInteractable
{
public:
	PlayerInteractable();

	virtual void OnPlayerInteract(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
