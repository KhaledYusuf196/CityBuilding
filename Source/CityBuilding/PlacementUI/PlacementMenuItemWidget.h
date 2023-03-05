// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Engine/DataTable.h"
#include "PlacementMenuItemWidget.generated.h"


USTRUCT()
struct FBuildingPrototype : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UTexture2D* BuildingImage;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABuildingActor> BuildingActor;
};

/**
 * 
 */
UCLASS()
class CITYBUILDING_API UPlacementMenuItemWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (BindWidget))
	class UButton* ActivateButton;

	UPROPERTY(meta = (BindWidget))
	class UImage* BuildingImage;
	
	class IPlacementUIHandlerInterface* PlacementUIHandler;

	TSubclassOf<ABuildingActor> BuildingActorClass;

public:
	UFUNCTION()
	void OnActivateButtonClick();
	
	void SetupItem(class UPlacementMenuWidget* PlacementMenuWidget, FBuildingPrototype BuildingPrototype);
	
};



