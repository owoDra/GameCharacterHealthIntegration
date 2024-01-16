// Copyright (C) 2024 owoDra

#include "CharacterRecipe_AddHealthComponent.h"

#include "GCHIntgLogs.h"

#include "HealthComponent.h"
#include "HealthData.h"

#include "CharacterInitStateComponent.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterRecipe_AddHealthComponent)


UCharacterRecipe_AddHealthComponent::UCharacterRecipe_AddHealthComponent()
{
	InstancingPolicy = ECharacterRecipeInstancingPolicy::NonInstanced;
	NetExecutionPolicy = ECharacterRecipeNetExecutionPolicy::ServerOnly;
}


void UCharacterRecipe_AddHealthComponent::StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const
{
	auto* Pawn{ Info.Pawn.Get() };

	auto* LoadedComponentClass
	{
		ComponentClass.IsNull() ? nullptr :
		ComponentClass.IsValid() ? ComponentClass.Get() : ComponentClass.LoadSynchronous()
	};

	if (ComponentClass)
	{
		auto* NewHC{ NewObject<UHealthComponent>(Pawn, LoadedComponentClass) };
		NewHC->RegisterComponent();

		UE_LOG(LogGCHI, Log, TEXT("+Component (Name: %s, Class: %s)"), *GetNameSafe(NewHC), *GetNameSafe(LoadedComponentClass));

		auto* LoadedHealthData
		{
			HealthData.IsNull() ? nullptr :
			HealthData.IsValid() ? HealthData.Get() : HealthData.LoadSynchronous()
		};

		UE_LOG(LogGCHI, Log, TEXT("++HealthData (Name: %s)"), *GetNameSafe(LoadedHealthData));

		NewHC->SetHealthData(LoadedHealthData);
	}
}
