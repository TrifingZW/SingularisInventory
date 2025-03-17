/* =====================================================================
 * InventoryWidget.h
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2024 TrifingZW <TrifingZW@gmail.com>
 * 
 * Copyright (c) 2024 TrifingZW
 * Licensed under MIT License
 * ===================================================================== */

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

class UBaseItem;

/**
 * 库存控件基类
 */
UCLASS(Abstract, Blueprintable)
class SINGULARISINVENTORY_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:
#pragma region 库存控件函数

	UFUNCTION(
		BlueprintCallable,
		Category="库存控件函数",
		meta = (
			DisplayName = "显示库存控件",
			ToolTip = "显示库存控件"
		)
	)
	void ShowWidget();

	UFUNCTION(
		BlueprintCallable,
		Category="库存控件函数",
		meta = (
			DisplayName = "隐藏库存控件",
			ToolTip = "隐藏库存控件"
		)
	)
	void HideWidget();

#pragma endregion

#pragma region 库存控件接口

	UFUNCTION(
		BlueprintImplementableEvent,
		BlueprintCallable,
		Category="库存控件接口",
		meta=(DisplayName="设置槽位控件数量",
			ToolTip = "设置槽位控件的数量"
		)
	)
	void SetSlotCount(int32 Count);

	UFUNCTION(
		BlueprintImplementableEvent,
		BlueprintCallable,
		Category="库存控件接口",
		meta=(DisplayName="设置选中槽位控件",
			ToolTip = "设置选中的槽位控件"
		)
	)
	void SetSlotSelect(int32 Index);

	UFUNCTION(
		BlueprintImplementableEvent,
		BlueprintCallable,
		Category="库存控件接口",
		meta = (
			DisplayName = "设置槽位控件物品",
			ToolTip = "根据索引设置指定槽位控件所显示的物品"
		)
	)
	void SetSlotItem(int32 Index, const UBaseItem* Item);

	UFUNCTION(
		BlueprintImplementableEvent,
		BlueprintCallable,
		Category="库存控件接口",
		meta = (
			DisplayName = "清空槽位控件物品",
			ToolTip = "根据索引清除指定槽位控件所显示的物品"
		)
	)
	void ClearSlotItem(int32 Index);

#pragma endregion
};
