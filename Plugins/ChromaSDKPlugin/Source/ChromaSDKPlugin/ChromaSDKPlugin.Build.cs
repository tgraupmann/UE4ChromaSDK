// Some copyright should be here...

using UnrealBuildTool;

public class ChromaSDKPlugin : ModuleRules
{
#if WITH_FORWARDED_MODULE_RULES_CTOR
    public ChromaSDKPlugin(ReadOnlyTargetRules Target) : base(Target) // 4.16 or better
#else
    public ChromaSDKPlugin(TargetInfo Target) //4.15 or lower
#endif
    {
#if WITH_FORWARDED_MODULE_RULES_CTOR
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
#endif
		
		PublicIncludePaths.AddRange(
			new string[] {
				"ChromaSDKPlugin/Public",				
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"ChromaSDKPlugin/Private",
				
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",

				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
