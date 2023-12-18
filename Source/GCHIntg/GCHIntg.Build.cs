// Copyright (C) 2023 owoDra

using UnrealBuildTool;

public class GCHIntg : ModuleRules
{
	public GCHIntg(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[]
            {
                ModuleDirectory,
                ModuleDirectory + "/GCHIntg",
            }
        );


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
            }
        );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "GCExt",
                "GAHAddon",
            }
        );

        SetupIrisSupport(Target);
    }
}
