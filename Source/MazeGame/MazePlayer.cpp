// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "MazePlayer.h"


// Sets default values
AMazePlayer::AMazePlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->PlayerInventory = Inventory(1);
}

// Called when the game starts or when spawned
void AMazePlayer::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMazePlayer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

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
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		// Limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

//handles strafing
void AMazePlayer::Strafe(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
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


