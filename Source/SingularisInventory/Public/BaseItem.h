/* =====================================================================
 * BaseItemData.h
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2024 TrifingZW <TrifingZW@gmail.com>
 * 
 * Copyright (c) 2024 TrifingZW
 * Licensed under MIT License
 * ===================================================================== */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseItem.generated.h"

class ABaseItemActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FOnItemUseDelegate,
	APlayerController*,
	PlayerController
);

/**
 * 基本物品类
 */
UCLASS(Abstract, Blueprintable)
class SINGULARISINVENTORY_API UBaseItem : public UObject
{
	GENERATED_BODY()

public:
#pragma region 物品属性

	UPROPERTY(
		EditDefaultsOnly,
		BlueprintReadOnly,
		Category="物品|属性",
		meta = (
			DisplayName = "物品ID",
			ToolTip = "该物品的ID，警告！每个物品的ID都是唯一的。"
		)
	)
	int32 ItemID;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "物品|属性",
		meta = (
			DisplayName = "物品显示名称",
			ToolTip = "该物品在游戏中显示的名称。"
		)
	)
	FText DisplayName = FText::FromString(TEXT("物品"));

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category="物品|属性",
		meta=(DisplayName = "物品图标",
			ToolTip = "该物品在库存管理器中的图标。",
			AllowedClasses="Texture2D,MaterialInterface"
		)
	)
	TSoftObjectPtr<UObject> IconAsset; // 支持纹理或材质

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "物品|属性",
		meta = (
			DisplayName = "物品价值",
			ToolTip = "该物品在游戏中的价值。"
		)
	)
	float ItemValue = 0.0f;

#pragma endregion

#pragma region 物品|子类引用

	UPROPERTY(
		EditDefaultsOnly,
		BlueprintReadOnly,
		Category="物品|子类引用",
		meta = (
			DisplayName = "物品表现类",
			ToolTip = "当物品生成于世界时，该物品表现出的形态。该类必须是抽象类AItemVisualActor的子类。"
		)
	)
	TSubclassOf<ABaseItemActor> VisualActorClass;

#pragma endregion

#pragma region 物品用途属性

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "物品|用途属性",
		meta = (
			DisplayName = "消耗品",
			ToolTip = "设置为 True 则该物品为可消耗的物品，使用后会触发 OnItemUse 事件，并且物品会消失。"
		)
	)
	bool bConsumable = false;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "物品|用途属性",
		meta = (
			DisplayName = "佩戴物品",
			ToolTip = "设置为 True 则该物品为可佩戴"
		)
	)
	bool bAccessory = false;

#pragma endregion

#pragma region 物品委托

	UPROPERTY(
		BlueprintAssignable,
		Category = "物品|委托",
		meta = (
			DisplayName = "物品使用时触发",
			ToolTip = "当物品被玩家使用事，物品会消失并触发该事件。"
		)
	)
	FOnItemUseDelegate OnItemUse{};

#pragma endregion
};
