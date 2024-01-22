// Copyright (C) 2024 owoDra

#include "CharacterRecipe_AddHealthComponent.h"

#include "HealthComponent.h"
#include "HealthData.h"

#include "CharacterInitStateComponent.h"
#include "GCExtLogs.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterRecipe_AddHealthComponent)


UCharacterRecipe_AddHealthComponent::UCharacterRecipe_AddHealthComponent()
{
	InstancingPolicy = ECharacterRecipeInstancingPolicy::NonInstanced;
	NetExecutionPolicy = ECharacterRecipeNetExecutionPolicy::ServerOnly;

#if WITH_EDITOR
	StaticClass()->FindPropertyByName(FName{ TEXTVIEW("InstancingPolicy") })->SetPropertyFlags(CPF_DisableEditOnTemplate);
	StaticClass()->FindPropertyByName(FName{ TEXTVIEW("NetExecutionPolicy") })->SetPropertyFlags(CPF_DisableEditOnTemplate);
#endif
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

		UE_LOG(LogGameExt_CharacterRecipe, Log, TEXT("+Component (Name: %s, Class: %s)"), *GetNameSafe(NewHC), *GetNameSafe(LoadedComponentClass));

		auto* LoadedHealthData
		{
			HealthData.IsNull() ? nullptr :
			HealthData.IsValid() ? HealthData.Get() : HealthData.LoadSynchronous()
		};

		UE_LOG(LogGameExt_CharacterRecipe, Log, TEXT("++HealthData (Name: %s)"), *GetNameSafe(LoadedHealthData));

		NewHC->SetHealthData(LoadedHealthData);
	}
}
