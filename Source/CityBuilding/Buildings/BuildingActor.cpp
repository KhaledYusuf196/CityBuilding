// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingActor.h"

#include "BuildingActionComponent.h"

// Sets default values
ABuildingActor::ABuildingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	BuildingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuildingMesh"));

	RootComponent = Root;
    BuildingMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABuildingActor::BeginPlay()
{
	Super::BeginPlay();
	BuildingActionComponent = FindComponentByClass<UBuildingActionComponent>();
}


void ABuildingActor::SelectBuilding() const
{
	if(!ensure(BuildingActionComponent != nullptr)) return;
	BuildingActionComponent->OnSelected();
}

void ABuildingActor::DeselectBuilding() const
{
	if(!ensure(BuildingActionComponent != nullptr)) return;
	BuildingActionComponent->OnDeselected();
}

