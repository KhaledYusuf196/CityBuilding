// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingActionComponent.h"

// Sets default values for this component's properties
UBuildingActionComponent::UBuildingActionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBuildingActionComponent::BeginPlay()
{
	Super::BeginPlay();

	MaterialInstance = UMaterialInstanceDynamic::Create(GetOwner()->FindComponentByClass<UStaticMeshComponent>()->GetMaterial(0), NULL);
	GetOwner()->FindComponentByClass<UStaticMeshComponent>()->SetMaterial(0, MaterialInstance);
	
}


// Called every frame
void UBuildingActionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBuildingActionComponent::OnSelected()
{
	MaterialInstance->SetVectorParameterValue(TEXT("Color"), FColor::Green);
}

void UBuildingActionComponent::OnDeselected()
{
	MaterialInstance->SetVectorParameterValue(TEXT("Color"), FColor::White);
}

