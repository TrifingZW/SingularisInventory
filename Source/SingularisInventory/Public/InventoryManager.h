/* =====================================================================
 * InventoryManager.h
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2024 TrifingZW <TrifingZW@gmail.com>
 * 
 * Copyright (c) 2024 TrifingZW
 * Licensed under MIT License
 * ===================================================================== */

#pragma once

#include <InputAction.h>
#include <InputMappingContext.h>

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryManager.generated.h"

class UInventoryWidget;
class UBaseItem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FOnSlotUpdatedDelegate,
	int32,
	SlotIndex
);

USTRUCT(BlueprintType)
struct SINGULARISINVENTORY_API FInventorySlot
{
	GENERATED_BODY()

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "库存插槽",
		meta = (
			DisplayName = "库存实例",
			ToolTip = "该库存物品的实例"
		)
	)
	UBaseItem* Item = nullptr;

	UPROPERTY(BlueprintReadOnly, meta=(EditHide))
	bool bIsEmpty = true;

	void Clear()
	{
		Item = nullptr;
		bIsEmpty = true;
	}

	void SetItem(UBaseItem* NewItem)
	{
		Item = NewItem;
		bIsEmpty = false;
	}
};

/**
 * 库存管理器
 */
UCLASS(Blueprintable, ClassGroup=("引力奇点库存系统"), meta=(BlueprintSpawnableComponent))
class SINGULARISINVENTORY_API UInventoryManager : public UActorComponent
{
	GENERATED_BODY()

public:
#pragma region 库存管理器持有实例

	UPROPERTY(BlueprintReadOnly, Category = "库存管理器持有实例", meta=(EditHide))
	UInventoryWidget* InventoryWidget; // 交互 UI 实例

#pragma endregion

#pragma region 库存管理器属性

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category="库存管理器|属性",
		meta = (
			DisplayName = "库存映射",
			ToolTip = "库存映射表，ItemID -> Slot"
		)
	)
	TArray<FInventorySlot> Slots;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category="库存管理器|属性",
		meta = (
			DisplayName = "选中的库存槽位",
			ToolTip = "选中的库存槽位索引"
		)
	)
	int32 SlotSelect;

#pragma endregion

#pragma region 库存管理器输入

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "库存管理器|输入",
		meta = (
			DisplayName = "库存管理器 IMC",
			ToolTip = "交互组件的输入映射上下文"
		)
	)
	UInputMappingContext* InventoryInputMappingContext = nullptr;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "库存管理器|输入",
		meta = (
			DisplayName = "库存1 IA",
			ToolTip = "给库存1快捷键绑定的输入动作"
		)
	)
	UInputAction* InventoryInputActionOne = nullptr;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "库存管理器|输入",
		meta = (
			DisplayName = "库存2 IA",
			ToolTip = "给库存2快捷键绑定的输入动作"
		)
	)
	UInputAction* InventoryInputActionTwo = nullptr;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "库存管理器|输入",
		meta = (
			DisplayName = "库存3 IA",
			ToolTip = "给库存3快捷键绑定的输入动作"
		)
	)
	UInputAction* InventoryInputActionThree = nullptr;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "库存管理器|输入",
		meta = (
			DisplayName = "库存4 IA",
			ToolTip = "给库存4快捷键绑定的输入动作"
		)
	)
	UInputAction* InventoryInputActionFour = nullptr;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "库存管理器|输入",
		meta = (
			DisplayName = "库存5 IA",
			ToolTip = "给库存5快捷键绑定的输入动作"
		)
	)
	UInputAction* InventoryInputActionFive = nullptr;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "库存管理器|输入",
		meta = (
			DisplayName = "库存6 IA",
			ToolTip = "给库存6快捷键绑定的输入动作"
		)
	)
	UInputAction* InventoryInputActionSix = nullptr;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "库存管理器|输入",
		meta = (
			DisplayName = "库存7 IA",
			ToolTip = "给库存7快捷键绑定的输入动作"
		)
	)
	UInputAction* InventoryInputActionSeven = nullptr;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "库存管理器|输入",
		meta = (
			DisplayName = "库存8 IA",
			ToolTip = "给库存8快捷键绑定的输入动作"
		)
	)
	UInputAction* InventoryInputActionEight = nullptr;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "库存管理器|输入",
		meta = (
			DisplayName = "库存9 IA",
			ToolTip = "给库存9快捷键绑定的输入动作"
		)
	)
	UInputAction* InventoryInputActionNine = nullptr;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "库存管理器|输入",
		meta = (
			DisplayName = "库存0 IA",
			ToolTip = "给库存0快捷键绑定的输入动作"
		)
	)
	UInputAction* InventoryInputActionZero = nullptr;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "库存管理器|输入",
		meta = (
			DisplayName = "输入优先级",
			ToolTip = "决定输入的先后顺序"
		)
	)
	int32 InputPriority = 0;

#pragma endregion

#pragma region 库存管理器子类引用

	UPROPERTY(
		EditDefaultsOnly,
		Category = "库存管理器|子类引用",
		meta = (
			DisplayName = "库存管理器UI类",
			ToolTip = "要绘制的库存管理器的UI类"
		)
	)
	TSubclassOf<UInventoryWidget> InventoryWidgetClass;

#pragma endregion

#pragma region 库存管理器委托

	UPROPERTY(
		BlueprintAssignable,
		Category = "库存管理器|委托",
		meta = (
			DisplayName = "库存更新时触发",
			ToolTip = "当库存物品更新时触发的事件。"
		)
	)
	FOnSlotUpdatedDelegate OnSlotUpdated;

#pragma endregion

#pragma region 常规

private:
	TWeakObjectPtr<APlayerController> PlayerController = nullptr;

public:
	UInventoryManager();

protected:
	virtual void BeginPlay() override;
	virtual void OnRegister() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

#pragma endregion

private:
#pragma region 库存管理器函数

	void CreateInteractionWidget();
	void InputFinder();
	static void LoadInputAction(UInputAction*& InputAction, const TCHAR* Path);

#pragma endregion

#pragma region 输入绑定函数

	void BindInputs();
	void HandleOne(const FInputActionValue& Value);
	void HandleTwo(const FInputActionValue& Value);
	void HandleThree(const FInputActionValue& Value);
	void HandleFour(const FInputActionValue& Value);
	void HandleFive(const FInputActionValue& Value);
	void HandleSix(const FInputActionValue& Value);
	void HandleSeven(const FInputActionValue& Value);
	void HandleEight(const FInputActionValue& Value);
	void HandleNine(const FInputActionValue& Value);
	void HandleZero(const FInputActionValue& Value);

#pragma endregion

#pragma region 库存管理器操作函数

public:
	UFUNCTION(
		BlueprintCallable,
		Category="库存管理器|操作函数",
		meta = (
			DisplayName = "尝试添加物品",
			ToolTip = "尝试添加物品到库存"
		)
	)
	bool TryAddItem(UBaseItem* Item);

	UFUNCTION(
		BlueprintCallable,
		Category="库存管理器|操作函数",
		meta = (
			DisplayName = "通过索引删除物品",
			ToolTip = "通过库存索引删除物品"
		)
	)
	bool RemoveItemByIndex(int32 SlotIndex);

	UFUNCTION(
		BlueprintCallable,
		Category="库存管理器|操作函数",
		meta = (
			DisplayName = "交换槽位物品",
			ToolTip = "通过索引交换两个槽位的物品"
		)
	)
	void SwapSlots(int32 FromIndex, int32 ToIndex);

	UFUNCTION(
		BlueprintCallable,
		Category="库存管理器|操作函数",
		meta = (
			DisplayName = "检查槽位是否为空",
			ToolTip = "通过索引检查指定槽位是否为空"
		)
	)
	bool IsSlotEmpty(int32 SlotIndex) const;

	UFUNCTION(
		BlueprintCallable,
		Category="库存管理器|操作函数",
		meta = (
			DisplayName = "获取槽位物品",
			ToolTip = "通过索引获取指定槽位的物品"
		)
	)
	UBaseItem* GetItemInSlot(int32 SlotIndex) const;

	UFUNCTION(
		BlueprintCallable,
		Category="库存管理器|操作函数",
		meta = (
			DisplayName = "获取选中槽位物品",
			ToolTip = "获取选中槽位的物品"
		)
	)
	UBaseItem* GetSelectItem() const;

	UFUNCTION(
		BlueprintCallable,
		Category="库存管理器|操作函数",
		meta = (
			DisplayName = "设置选中槽位索引",
			ToolTip = "设置选中槽位索引"
		)
	)
	void SetSlotSelect(int32 Index);

#pragma endregion
};
