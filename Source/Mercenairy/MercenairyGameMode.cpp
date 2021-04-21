// Copyright Epic Games, Inc. All Rights Reserved.

#include "MercenairyGameMode.h"
#include "MercenairyPawn.h"

AMercenairyGameMode::AMercenairyGameMode()
{
	// set default pawn class to our flying pawn
	DefaultPawnClass = AMercenairyPawn::StaticClass();
}
