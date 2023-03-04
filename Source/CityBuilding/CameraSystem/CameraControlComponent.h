// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraControlComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CITYBUILDING_API UCameraControlComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCameraControlComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	void MoveCamera(FVector2D Direction) const;
	
	void RotateCamera(FVector2D Direction) const;

	void SetCameraRoot(USceneComponent* SceneComponent) { CameraRootComponent = SceneComponent; }

	void SetMovementInput(FVector2D Input) { MovementInput = Input; }
	void SetRotationInput(FVector2D Input) { RotationInput = Input; }

private:
	FVector2D MovementInput;

	FVector2D RotationInput;

public:
	UPROPERTY()
	USceneComponent* CameraRootComponent;
};
