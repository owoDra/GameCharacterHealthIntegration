// Copyright (C) 2024 owoDra

#pragma once

#include "CharacterModifier.h"

#include "CharacterModifier_AddHealthComponent.generated.h"

class UHealthComponent;
class UHealthData;


/**
 * Modifier class to add health component to Pawn
 */
UCLASS(meta = (DisplayName = "CM Add Health Component"))
class UCharacterModifier_AddHealthComponent final : public UCharacterModifier
{
	GENERATED_BODY()
public:
	UCharacterModifier_AddHealthComponent();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AddHealthComponent")
	TSoftClassPtr<UHealthComponent> ComponentClass{ nullptr };

	UPROPERTY(EditDefaultsOnly, Category = "AddHealthComponent")
	TSoftObjectPtr<UHealthData> HealthData{ nullptr };

protected:
	virtual bool OnApply(APawn* Pawn) const override;

};
