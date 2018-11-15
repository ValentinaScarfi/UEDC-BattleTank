// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward movement, +1 is max upward movement
	void ElevateBarrel(float RelativeSpeed);
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 5; // Sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40.0;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0.0;

};
