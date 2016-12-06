// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "DoorProp.h"
#include "MazePlayer.h"


// Sets default values
ADoorProp::ADoorProp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_DoorPropMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorPropMesh"));
	SM_DoorPropMesh->AttachToComponent(DoorPropRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	DoorPropRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DoorPropRoot"));
	RootComponent = DoorPropRoot;

	DoorPropBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DoorPropBox"));
	DoorPropBox->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	DoorPropBox->bGenerateOverlapEvents = true;
	DoorPropBox->OnComponentBeginOverlap.AddDynamic(this, &ADoorProp::OnPlayerInteract);
	DoorPropBox->AttachToComponent(DoorPropRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

// Called when the game starts or when spawned
void ADoorProp::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADoorProp::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// OnPlayerInteract
void ADoorProp::OnPlayerInteract(UPrimitiveComponent* OverlappedComponent, AMazePlayer* player, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	Destroy();
}
