// Copyright (C) 2024 owoDra

#pragma once

#include "Recipe/CharacterRecipe.h"

#include "CharacterRecipe_ApplyHealthData.generated.h"

class UHealthData;


/**
 * Modifier class to apply health data to Pawn
 */
UCLASS()
class UCharacterRecipe_ApplyHealthData final : public UCharacterRecipe
{
	GENERATED_BODY()
public:
	UCharacterRecipe_ApplyHealthData();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "ApplyHealthData")
	TSoftObjectPtr<UHealthData> HealthData{ nullptr };

protected:
	virtual void StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const override;

};
