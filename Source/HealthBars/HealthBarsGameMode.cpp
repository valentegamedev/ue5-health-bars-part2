// Copyright Epic Games, Inc. All Rights Reserved.

#include "HealthBarsGameMode.h"
#include "HealthBarsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHealthBarsGameMode::AHealthBarsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
