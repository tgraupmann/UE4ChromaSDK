﻿// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "ChromaSDKPluginAnimation1DObject.h"
#include "ChromaSDKPluginBPLibrary.h"

UChromaSDKPluginAnimation1DObject::UChromaSDKPluginAnimation1DObject(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

#if WITH_EDITOR
void UChromaSDKPluginAnimation1DObject::PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent)
{
	UE_LOG(LogTemp, Log, TEXT("UChromaSDKPluginAnimation1DObject::PostEditChangeChainProperty"));
	for (int i = 0; i < Frames.Num(); ++i)
	{
		FChromaSDKColorFrame1D& frame = Frames[i];
		frame.Colors = UChromaSDKPluginBPLibrary::CreateRandomColors1D(Device);
	}
}
#endif
