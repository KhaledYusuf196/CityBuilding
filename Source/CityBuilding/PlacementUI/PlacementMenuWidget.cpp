// Fill out your copyright notice in the Description page of Project Settings.


#include "PlacementMenuWidget.h"

#include "Components/Button.h"


bool UPlacementMenuWidget::Initialize()
{
	if(!Super::Initialize()) return false;
	
	if(!ensure(PlacementMenuList != nullptr)) return false;
	PlacementMenuList->Visibility = ESlateVisibility::Hidden;

	if(!ensure(PlacementMenuButton != nullptr)) return false;
	PlacementMenuButton->OnClicked.AddDynamic(this, &UPlacementMenuWidget::ShowPlacementMenuList);
	
	return true;
}

void UPlacementMenuWidget::AddPlacementMenuItem(UUserWidget* Item)
{
	PlacementMenuList->AddChild(Item);
}


void UPlacementMenuWidget::ShowPlacementMenuList()
{
	PlacementMenuList->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
}

void UPlacementMenuWidget::HidePlacementMenuList()
{
	PlacementMenuList->SetVisibility(ESlateVisibility::Hidden);
}
