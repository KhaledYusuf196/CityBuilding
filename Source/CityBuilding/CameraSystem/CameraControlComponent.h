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

	void MoveCamera(FVector2D Direction, float DeltaTime) const;

	void RotateCamera(FVector2D Direction, float DeltaTime) const;

	void SetCameraRoot(class USpringArmComponent* SceneComponent) { CameraRootComponent = SceneComponent; }

	void SetMovementInput(FVector2D Input) { MovementInput = Input; }
	void SetRotationInput(FVector2D Input) { RotationInput = Input; }
	void SetZoomInput(float Input) { ZoomInput = Input; }

	void ZoomCamera(float Zoom) const;

private:
	FVector2D MovementInput;

	FVector2D RotationInput;

	float ZoomInput;

	UPROPERTY(EditAnywhere)
	float MovementSpeed = 10;

	UPROPERTY(EditAnywhere)
	float RotationSpeed = 180;

	UPROPERTY(EditAnywhere)
	float ZoomDistanceStep = 10;

	UPROPERTY(EditAnywhere)
	float MaxZoomDistance = 600;

	UPROPERTY(EditAnywhere)
	float MinZoomDistance = 300;

public:
	UPROPERTY()
	class USpringArmComponent* CameraRootComponent;
};
