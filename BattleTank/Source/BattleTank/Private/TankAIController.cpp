// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller can't find player tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI found %s"), *(PlayerTank->GetName()));
	}
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		//TODO: Move towards the player
		//Aim towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//Fire when ready
	}
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerTank)
	{
		return nullptr;
	}
	else
	{
		return Cast<ATank>(PlayerTank);
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}



