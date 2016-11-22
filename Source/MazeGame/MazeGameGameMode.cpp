// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "MazeGameGameMode.h"
#include "MazePlayer.h"

AMazeGameGameMode::AMazeGameGameMode(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	DefaultPawnClass = AMazePlayer::StaticClass();

}


