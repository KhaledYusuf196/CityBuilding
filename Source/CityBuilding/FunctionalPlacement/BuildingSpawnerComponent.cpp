// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingSpawnerComponent.h"

#include "Blueprint/UserWidget.h"
#include "CityBuilding/Buildings/BuildingActor.h"
#include "CityBuilding/PlacementUI/PlacementMenuWidget.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UBuildingSpawnerComponent::UBuildingSpawnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	if(ConstructorHelpers::FClassFinder<UPlacementMenuWidget> MenuWidgetFinder(
		TEXT("/Game/CityBuildingContent/PlacementUI/WBP_PlacementMenu"));
		MenuWidgetFinder.Succeeded())
	{
		PlacementMenuWidgetClass = MenuWidgetFinder.Class;
	}
	if(ConstructorHelpers::FClassFinder<UPlacementMenuItemWidget> MenuItemWidgetFinder(
		TEXT("/Game/CityBuildingContent/PlacementUI/WBP_PlacementMenuItem"));
		MenuItemWidgetFinder.Succeeded())
	{
		PlacementMenuItemWidgetClass = MenuItemWidgetFinder.Class;
	}
	if(ConstructorHelpers::FObjectFinder<UDataTable> BuildingsTableFinder(
		TEXT("/Game/CityBuildingContent/FunctionalPlacement/Table_BuildingPrototypes"));
		BuildingsTableFinder.Succeeded())
	{
		BuildingsDataTable = BuildingsTableFinder.Object;
	}
}


// Called when the game starts
void UBuildingSpawnerComponent::BeginPlay()
{
	Super::BeginPlay();

	SetupPlacementMenuWidget();
	
}

void UBuildingSpawnerComponent::SpawnBuilding(const FVector& BuildingLocation)
{
	GetWorld()->SpawnActor<ABuildingActor>(ActiveActor, BuildingLocation, FRotator::ZeroRotator);
}

void UBuildingSpawnerComponent::ReceiveActiveBuilding(TSubclassOf<ABuildingActor> BuildingActorClass)
{
	ActiveActor = BuildingActorClass;
}

void UBuildingSpawnerComponent::SetupPlacementMenuWidget()
{
	UPlacementMenuWidget* MenuWidget = CreateWidget<UPlacementMenuWidget>(GetWorld(), PlacementMenuWidgetClass);
	MenuWidget->PlacementUIHandler = this;
	MenuWidget->AddToViewport();
	const FString ContextString(TEXT("Buildings Table"));
	TArray<FBuildingPrototype*> AllBuildings;
	BuildingsDataTable->GetAllRows(ContextString, AllBuildings);
	for (const auto BuildingPrototype : AllBuildings)
	{
		if(!BuildingPrototype) continue;
		UPlacementMenuItemWidget* ItemWidget = CreateWidget<UPlacementMenuItemWidget>(GetWorld(), PlacementMenuItemWidgetClass);
		ItemWidget->SetupItem(MenuWidget, *BuildingPrototype);
		MenuWidget->AddPlacementMenuItem(ItemWidget);
	}
}

