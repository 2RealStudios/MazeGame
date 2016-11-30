// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "MazeGame.h"
#include "MazePlayer.h"
#include "PlayerInteractable.h"

// Sets default values
AMazePlayer::AMazePlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup Camera for proper HMD 
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Setup TraceParams for RayTracing
	TraceParams = FCollisionQueryParams(FName(TEXT("TraceParams")), false, this);
	TraceParams.bTraceComplex = false;
	TraceParams.bTraceAsyncScene = false;
	TraceParams.bReturnPhysicalMaterial = false;

	this->PlayerInventory = Inventory(1);
}

// Called when the game starts or when spawned
void AMazePlayer::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMazePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AActor* actor = FindFocusedActor(3000);
	IPlayerInteractable* inter = Cast<IPlayerInteractable>(actor);
	if (actor)
	{
		UE_LOG(LogTemp, Warning, TEXT("TETSTSRTSTD"));
		if (actor->GetClass()->ImplementsInterface(UPlayerInteractable::StaticClass()))
		{
			IPlayerInteractable::Execute_OnPlayerInteract(actor, this);
			UE_LOG(LogTemp, Warning, TEXT("I SEE YOU"));
		}
	}
	
}

// Called to bind functionality to input
void AMazePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMazePlayer::MoveForward);
	PlayerInputComponent->BindAxis("Strafe", this, &AMazePlayer::Strafe);
	InputComponent->BindAxis("Turn", this, &AMazePlayer::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AMazePlayer::AddControllerPitchInput);
	InputComponent->BindAxis("PadTurn", this, &AMazePlayer::PadTurn);
	InputComponent->BindAxis("PadLookUp", this, &AMazePlayer::PadLookup);
}

//handles moving forward/backward
void AMazePlayer::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in the forward direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

//handles strafing
void AMazePlayer::Strafe(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in the right direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

float BaseTurnRate = 45;
float BaseLookUpRate = 45;

void AMazePlayer::PadTurn(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMazePlayer::PadLookup(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

int AMazePlayer::OnItemCollide(Item& item, int amount)
{
	return this->PlayerInventory.AddItem(item, amount);
}

bool AMazePlayer::hasItem(Item& item)
{
	return this->PlayerInventory.GetItemCount(item) > 0;
}

AActor* AMazePlayer::FindFocusedActor(int distance)
{
	if (!Controller)
	{
		return nullptr;
	}

	FVector Location;
	FRotator Rotation;
	FHitResult Hit(ForceInit);

	Controller->GetPlayerViewPoint(Location, Rotation);

	FVector Start = Location;
	FVector End = Start + (Rotation.Vector() * distance);

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Camera, TraceParams, FCollisionResponseParams::DefaultResponseParam))
	{
		return Hit.GetActor();
	}

	return nullptr;
}

