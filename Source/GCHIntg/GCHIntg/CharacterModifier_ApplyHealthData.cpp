// Copyright (C) 2023 owoDra

#include "CharacterModifier_ApplyHealthData.h"

#include "GCHIntgLogs.h"

#include "HealthFunctionLibrary.h"
#include "HealthComponent.h"
#include "HealthData.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterModifier_ApplyHealthData)


void UCharacterModifier_ApplyHealthData::OnApply(APawn* Pawn) const
{
	check(Pawn)

	UE_LOG(LogGCHI, Log, TEXT("[%s] On Instance Apply(%s)"),
		Pawn->HasAuthority() ? TEXT("SERVER") : TEXT("CLIENT"), *GetNameSafe(this));

	const auto* World{ Pawn->GetWorld() };
	const auto bIsServer{ World->GetNetMode() != NM_Client };

	if (bIsServer)
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
}
