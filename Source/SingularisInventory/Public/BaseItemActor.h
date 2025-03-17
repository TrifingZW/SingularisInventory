/* =====================================================================
 * BaseItemActor.h
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2024 TrifingZW <TrifingZW@gmail.com>
 * 
 * Copyright (c) 2024 TrifingZW
 * Licensed under MIT License
 * ===================================================================== */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseItemActor.generated.h"

class UBaseItem;

/**
 * 基本物品表现类
 */
UCLASS(Abstract, Blueprintable)
class SINGULARISINVENTORY_API ABaseItemActor : public AActor
{
	GENERATED_BODY()

public:
#pragma region 基础物品表现属性
	UPROPERTY(EditAnywhere,
		BlueprintReadWrite,
		Category="物品属性|基本属性",
		meta=(DisplayName = "物品实例",
			ToolTip = "该物品表现的物品实例。"
		))
	UBaseItem* Item = nullptr;
#pragma endregion

	ABaseItemActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
