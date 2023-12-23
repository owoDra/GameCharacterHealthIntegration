// Copyright (C) 2023 owoDra

#pragma once

#include "CharacterModifier.h"

#include "CharacterModifier_ApplyHealthData.generated.h"

class UHealthData;


/**
 * Modifier class to apply health data to Pawn
 */
UCLASS(meta = (DisplayName = "CM Apply Health Data"))
class UCharacterModifier_ApplyHealthData final : public UCharacterModifier
{
	GENERATED_BODY()
public:
	UCharacterModifier_ApplyHealthData();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "ApplyHealthData")
	TSoftObjectPtr<UHealthData> HealthData{ nullptr };

protected:
	virtual bool OnApply(APawn* Pawn) const override;

};
