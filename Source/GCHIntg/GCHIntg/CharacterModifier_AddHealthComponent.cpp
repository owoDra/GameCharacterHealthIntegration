// Copyright (C) 2024 owoDra

#include "CharacterModifier_AddHealthComponent.h"

#include "GCHIntgLogs.h"

#include "HealthComponent.h"
#include "HealthData.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterModifier_AddHealthComponent)


UCharacterModifier_AddHealthComponent::UCharacterModifier_AddHealthComponent()
{
	bOnlyApplyOnLocal = false;
	bApplyOnClient = false;
	bApplyOnServer = true;
}


bool UCharacterModifier_AddHealthComponent::OnApply(APawn* Pawn) const
{
	const auto bCanApply{ Super::OnApply(Pawn) };

	if (bCanApply)
	{
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

	return bCanApply;
}
