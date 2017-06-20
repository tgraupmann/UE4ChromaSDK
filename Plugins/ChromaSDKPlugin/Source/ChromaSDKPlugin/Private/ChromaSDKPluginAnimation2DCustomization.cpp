﻿// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "ChromaSDKPluginAnimation2DCustomization.h"
#include "SlateFontInfoCustomization.h"

#define LOCTEXT_NAMESPACE "ChromaAnimation2DDetails"

TSharedRef<IPropertyTypeCustomization> FChromaSDKPluginAnimation2DCustomization::MakeInstance()
{
	return MakeShareable(new FChromaSDKPluginAnimation2DCustomization);
}

void FChromaSDKPluginAnimation2DCustomization::CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
}

void FChromaSDKPluginAnimation2DCustomization::CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder& StructBuilder, IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	//Create further customization here
}

#undef LOCTEXT_NAMESPACE