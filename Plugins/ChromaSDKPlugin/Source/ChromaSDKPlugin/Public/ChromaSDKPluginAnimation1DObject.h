// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ChromaSDKPlugin.h"
#include "ChromaSDKPluginTypes.h"
#include "ChromaSDKPluginAnimation1DObject.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateChomaSDKOnComplete1D, UChromaSDKPluginAnimation1DObject*, animation);

UCLASS(Blueprintable, BlueprintType, Category = "Animation")
class CHROMASDKPLUGIN_API UChromaSDKPluginAnimation1DObject : public UObject, public FTickableGameObject
{
	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "Import")
	float OverrideFrameTime;

	UPROPERTY(EditAnywhere, Category = "Animation")
	FRuntimeFloatCurve Curve;

	UPROPERTY(EditAnywhere, Category = "Data")
	EChromaSDKDevice1DEnum Device;

	UPROPERTY(EditAnywhere, Category = "Data")
	TArray<FChromaSDKColorFrame1D> Frames;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Play", Keywords = "Play the animation"), Category = "ChromaSDK")
	void Play();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PlayWithOnComplete", Keywords = "Play the animation and fire the OnComplete event"), Category = "ChromaSDK")
	void PlayWithOnComplete(FDelegateChomaSDKOnComplete1D onComplete);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Stop", Keywords = "Stop the animation"), Category = "ChromaSDK")
	void Stop();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IsPlaying", Keywords = "Is the animation currently playing?"), Category = "ChromaSDK")
	bool IsPlaying();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Load", Keywords = "Load the effects before playing"), Category = "ChromaSDK")
	void Load();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IsLoaded", Keywords = "Check if the animation has loaded"), Category = "ChromaSDK")
	bool IsLoaded();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Unload", Keywords = "Unload the effects"), Category = "ChromaSDK")
	void Unload();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetFrames1D", Keywords = "Get two-dimensional animation frames"), Category = "ChromaSDK")
	TArray<FChromaSDKColorFrame1D>& GetFrames();

	/* Implements FTickableGameObject */
	void Tick(float DeltaTime) override;
	bool IsTickable() const override;
	bool IsTickableInEditor() const override;
	bool IsTickableWhenPaused() const override;
	TStatId GetStatId() const override;
	/* Implements FTickableGameObject */

#if WITH_EDITOR
	void Reset(EChromaSDKDevice1DEnum device);
	void RefreshColors();
	void RefreshCurve();
#endif

private:
	float GetTime(int index);

	// Callback when animation completes
	FDelegateChomaSDKOnComplete1D _mOnComplete;

	// Effects needs to be loaded before the animation can be played
	bool _mIsLoaded;

	bool _mIsPlaying;
	float _mTime;
	int _mCurrentFrame;
	TArray<FChromaSDKEffectResult> _mEffects;
};
