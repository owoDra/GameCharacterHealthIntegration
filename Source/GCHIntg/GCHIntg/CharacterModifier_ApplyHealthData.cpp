// Copyright (C) 2023 owoDra

#include "CharacterModifier_ApplyHealthData.h"

#include "GCHIntgLogs.h"

#include "HealthFunctionLibrary.h"
#include "HealthComponent.h"
#include "HealthData.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterModifier_ApplyHealthData)


UCharacterModifier_ApplyHealthData::UCharacterModifier_ApplyHealthData()
{
	bOnlyApplyOnLocal = false;
	bApplyOnClient = false;
	bApplyOnServer = true;
}


bool UCharacterModifier_ApplyHealthData::OnApply(APawn* Pawn) const
{
	const auto bCanApply{ Super::OnApply(Pawn) };

	if (bCanApply)
	{
		if (auto* HC{ UHealthFunctionLibrary::GetHealthComponentFromActor(Pawn) })
		{
			auto* LoadedHealthData
			{
				HealthData.IsNull() ? nullptr :
				HealthData.IsValid() ? HealthData.Get() : HealthData.LoadSynchronous()
			};

			UE_LOG(LogGCHI, Log, TEXT("++HealthData (Name: %s)"), *GetNameSafe(LoadedHealthData));

			HC->SetHealthData(LoadedHealthData);
		}
	}

	return bCanApply;
}
