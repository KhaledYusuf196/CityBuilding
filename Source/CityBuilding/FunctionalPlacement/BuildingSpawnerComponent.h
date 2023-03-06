// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CityBuilding/PlacementUI/PlacementUIHandlerInterface.h"
#include "Components/ActorComponent.h"
#include "BuildingSpawnerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CITYBUILDING_API UBuildingSpawnerComponent : public UActorComponent, public IPlacementUIHandlerInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBuildingSpawnerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable)
	void SpawnBuilding(const FVector& BuildingLocation);

	virtual void ReceiveActiveBuilding(TSubclassOf<ABuildingActor> BuildingActorClass) override;

private:

	void SetupPlacementMenuWidget();
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UPlacementMenuWidget> PlacementMenuWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UPlacementMenuItemWidget> PlacementMenuItemWidgetClass;

	UPROPERTY(EditAnywhere)
	class UDataTable* BuildingsDataTable;

	TSubclassOf<ABuildingActor> ActiveActor;
};
