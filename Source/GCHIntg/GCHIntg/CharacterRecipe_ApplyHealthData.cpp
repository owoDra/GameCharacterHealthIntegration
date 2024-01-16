// Copyright (C) 2024 owoDra

#include "CharacterRecipe_ApplyHealthData.h"

#include "GCHIntgLogs.h"

#include "HealthFunctionLibrary.h"
#include "HealthComponent.h"
#include "HealthData.h"

#include "CharacterInitStateComponent.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterRecipe_ApplyHealthData)


UCharacterRecipe_ApplyHealthData::UCharacterRecipe_ApplyHealthData()
{
	InstancingPolicy = ECharacterRecipeInstancingPolicy::NonInstanced;
	NetExecutionPolicy = ECharacterRecipeNetExecutionPolicy::ServerOnly;
}


void UCharacterRecipe_ApplyHealthData::StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const
{
	auto* Pawn{ Info.Pawn.Get() };

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
