// Copyright (C) 2023 owoDra

#include "CharacterModifier_AddHealthComponent.h"

#include "GCHIntgLogs.h"

#include "HealthComponent.h"
#include "HealthData.h"

#include "GameFramework/Pawn.h"
#include "Net/UnrealNetwork.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterModifier_AddHealthComponent)


void UCharacterModifier_AddHealthComponent::OnApply(APawn* Pawn) const
{
	check(Pawn)

	UE_LOG(LogGCHI, Log, TEXT("[%s] On Instance Apply(%s)"),
		Pawn->HasAuthority() ? TEXT("SERVER") : TEXT("CLIENT"), *GetNameSafe(this));

	const auto* World{ Pawn->GetWorld() };
	const auto bIsServer{ World->GetNetMode() != NM_Client };

	UE_LOG(LogGCHI, Log, TEXT("Adding components for %s to world %s"), *GetPathNameSafe(Pawn), *World->GetDebugDisplayName());

	if (bIsServer)
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
}
