// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraControlComponent.h"

// Sets default values for this component's properties
UCameraControlComponent::UCameraControlComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCameraControlComponent::BeginPlay()
{
	Super::BeginPlay();

	if(CameraRootComponent == nullptr)
	{
		CameraRootComponent = GetOwner()->GetRootComponent();
	}
}


// Called every frame
void UCameraControlComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	MoveCamera(MovementInput);
	RotateCamera(RotationInput);
	MovementInput = RotationInput = FVector2D::Zero();
}

void UCameraControlComponent::MoveCamera(FVector2D Direction) const
{
	AActor* Owner = GetOwner();
	const FVector MovementDirection = FVector(Direction.X, Direction.Y, 0);
	const FVector NewLocation = Owner->GetActorLocation() + Owner->GetTransform().TransformVector(MovementDirection);
	Owner->SetActorLocation(NewLocation);
}

void UCameraControlComponent::RotateCamera(FVector2D Rotation) const
{
	const FRotator YawRotation = FRotator(0,Rotation.X,0);
	const FRotator PitchRotation = FRotator(Rotation.Y,0,0);
	GetOwner()->GetRootComponent()->AddRelativeRotation(YawRotation);
	CameraRootComponent->AddLocalRotation(PitchRotation);
	
}

