// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraControlComponent.h"

#include "GameFramework/SpringArmComponent.h"

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
		UE_LOG(LogTemp, Error, TEXT("CameraRootComponent not found"));
	}
}


// Called every frame
void UCameraControlComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	MoveCamera(MovementInput, DeltaTime);
	RotateCamera(RotationInput, DeltaTime);
	ZoomCamera(ZoomInput);
	MovementInput = RotationInput = FVector2D::Zero();
	ZoomInput = 0;
}

void UCameraControlComponent::MoveCamera(FVector2D Direction, float DeltaTime) const
{
	AActor* Owner = GetOwner();
	const FVector MovementDirection = FVector(Direction.X, Direction.Y, 0);
	const FVector NewLocation = Owner->GetActorLocation() + Owner->GetTransform().TransformVector(MovementDirection) * MovementSpeed * DeltaTime;
	Owner->SetActorLocation(NewLocation);
}

void UCameraControlComponent::RotateCamera(FVector2D Rotation, float DeltaTime) const
{

	double Pitch = Rotation.Y * RotationSpeed * DeltaTime + CameraRootComponent->GetRelativeRotation().Pitch;
	Pitch = FMath::Clamp(Pitch, -60.0, -30.0);
	const FRotator PitchRotation = FRotator(Pitch,0,0);
	CameraRootComponent->SetRelativeRotation(PitchRotation);

	const FRotator YawRotation = FRotator(0,Rotation.X * RotationSpeed * DeltaTime,0);
	GetOwner()->GetRootComponent()->AddRelativeRotation(YawRotation);
	
}

void UCameraControlComponent::ZoomCamera(const float Zoom) const
{
	CameraRootComponent->TargetArmLength = FMath::Clamp(CameraRootComponent->TargetArmLength + Zoom * ZoomDistanceStep, MinZoomDistance, MaxZoomDistance);
}

