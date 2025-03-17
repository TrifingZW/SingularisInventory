// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SingularisInventory : ModuleRules
{
	public SingularisInventory(ReadOnlyTargetRules target) : base(target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			[
			]
		);
				
		
		PrivateIncludePaths.AddRange(
			[
			]
		);
			
		
		PublicDependencyModuleNames.AddRange(
			[
				"Core",
				"UMG",
				"Slate",
				"SlateCore",
				"InputCore",
				"EnhancedInput"
			]
		);
			
		
		PrivateDependencyModuleNames.AddRange(
			[
				"CoreUObject",
				"Engine"
			]
		);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			[
			]
		);
	}
}
