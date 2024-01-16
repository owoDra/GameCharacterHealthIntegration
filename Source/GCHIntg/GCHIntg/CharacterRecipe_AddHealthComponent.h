// Copyright (C) 2024 owoDra

#pragma once

#include "Recipe/CharacterRecipe.h"

#include "CharacterRecipe_AddHealthComponent.generated.h"

class UHealthComponent;
class UHealthData;


/**
 * Modifier class to add health component to Pawn
 */
UCLASS()
class UCharacterRecipe_AddHealthComponent final : public UCharacterRecipe
{
	GENERATED_BODY()
public:
	UCharacterRecipe_AddHealthComponent();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AddHealthComponent")
	TSoftClassPtr<UHealthComponent> ComponentClass{ nullptr };

	UPROPERTY(EditDefaultsOnly, Category = "AddHealthComponent")
	TSoftObjectPtr<UHealthData> HealthData{ nullptr };

protected:
	virtual void StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const override;

};
