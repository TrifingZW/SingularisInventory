/* =====================================================================
 * InventoryManager.cpp
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2024 TrifingZW <TrifingZW@gmail.com>
 * 
 * Copyright (c) 2024 TrifingZW
 * Licensed under MIT License
 * ===================================================================== */

#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <Blueprint/UserWidget.h>

#include "InventoryManager.h"
#include "InventoryWidget.h"

UInventoryManager::UInventoryManager()
{
	PrimaryComponentTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<UInventoryWidget> WidgetClassFinder(
		TEXT("/SingularisInventory/UserInterface/WBP_DefaultInventory")
	);
	if (WidgetClassFinder.Succeeded())
		InventoryWidgetClass = WidgetClassFinder.Class;

	InputFinder();
}

void UInventoryManager::BeginPlay()
{
	Super::BeginPlay();
	CreateInteractionWidget();
	BindInputs();
}

void UInventoryManager::OnRegister()
{
	Super::OnRegister();

	// 阶段1：基础验证
	if (!GetOwner())
	{
		UE_LOG(LogTemp, Fatal, TEXT("[%s] 组件必须附加到Actor!"), *GetFullName());
		return;
	}

	// 阶段2：类型安全验证
	PlayerController = Cast<APlayerController>(GetOwner());
	if (!PlayerController.IsValid())
	{
		const FString OwnerInfo = FString::Printf(
			TEXT("%s (Class: %s)"),
			*GetOwner()->GetName(),
			*GetOwner()->GetClass()->GetName()
		);

		// 增强错误报告
		ensureMsgf(
			false,
			TEXT("[%s] 必须附加到APlayerController! 当前附加到: %s"),
			*GetFullName(),
			*OwnerInfo
		);

		UE_LOG(
			LogTemp,
			Error,
			TEXT("[%s] 附加到非法对象 %s. 组件功能已禁用."),
			*GetFullName(),
			*OwnerInfo
		);

		// 彻底禁用
		SetComponentTickEnabled(false);
		PrimaryComponentTick.bCanEverTick = false;
		SetActive(false, true);

		return;
	}

	// 后置验证
	checkf(
		PlayerController->IsLocalController(),
		TEXT("库存组件只能用于本地控制者: %s"),
		*GetFullName()
	);

	// 初始化成功逻辑
	SetComponentTickEnabled(true);
}

void UInventoryManager::TickComponent(const float DeltaTime, const ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UInventoryManager::CreateInteractionWidget()
{
	InventoryWidget = CreateWidget<UInventoryWidget>(PlayerController.Get(), InventoryWidgetClass);

	if (InventoryWidget)
	{
		InventoryWidget->AddToViewport(10);
		InventoryWidget->SetSlotCount(Slots.Num());
		InventoryWidget->SetSlotSelect(SlotSelect);
	}
}

void UInventoryManager::InputFinder()
{
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> InputMappingContextFinder(TEXT("/SingularisInventory/Input/IMC_Inventory"));
	if (InputMappingContextFinder.Succeeded())
		InventoryInputMappingContext = InputMappingContextFinder.Object;

	LoadInputAction(InventoryInputActionOne, TEXT("/SingularisInventory/Input/Action/IA_ONE"));
	LoadInputAction(InventoryInputActionTwo, TEXT("/SingularisInventory/Input/Action/IA_TWO"));
	LoadInputAction(InventoryInputActionThree, TEXT("/SingularisInventory/Input/Action/IA_THREE"));
	LoadInputAction(InventoryInputActionFour, TEXT("/SingularisInventory/Input/Action/IA_FOUR"));
	LoadInputAction(InventoryInputActionFive, TEXT("/SingularisInventory/Input/Action/IA_FIVE"));
	LoadInputAction(InventoryInputActionSix, TEXT("/SingularisInventory/Input/Action/IA_SIX"));
	LoadInputAction(InventoryInputActionSeven, TEXT("/SingularisInventory/Input/Action/IA_SEVEN"));
	LoadInputAction(InventoryInputActionEight, TEXT("/SingularisInventory/Input/Action/IA_EIGHT"));
	LoadInputAction(InventoryInputActionNine, TEXT("/SingularisInventory/Input/Action/IA_NINE"));
	LoadInputAction(InventoryInputActionZero, TEXT("/SingularisInventory/Input/Action/IA_ZERO"));
}

void UInventoryManager::LoadInputAction(UInputAction*& InputAction, const TCHAR* Path)
{
	if (const ConstructorHelpers::FObjectFinder<UInputAction> InputActionFinder(Path); InputActionFinder.Succeeded())
		InputAction = InputActionFinder.Object;
}

#pragma region 输入绑定函数

void UInventoryManager::BindInputs()
{
	if (!InventoryInputMappingContext || !InventoryInputActionOne || !InventoryInputActionTwo || !InventoryInputActionThree || !
		InventoryInputActionFour
		|| !InventoryInputActionFive || !InventoryInputActionSix || !InventoryInputActionSeven || !InventoryInputActionEight || !
		InventoryInputActionNine
		|| !InventoryInputActionZero)
		return;

	// 添加输入映射上下文
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		PlayerController->GetLocalPlayer()
	))
		Subsystem->AddMappingContext(InventoryInputMappingContext, InputPriority);

	// 绑定输入动作
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
	{
		EnhancedInput->BindAction(InventoryInputActionOne, ETriggerEvent::Triggered, this, &UInventoryManager::HandleOne);
		EnhancedInput->BindAction(InventoryInputActionTwo, ETriggerEvent::Triggered, this, &UInventoryManager::HandleTwo);
		EnhancedInput->BindAction(InventoryInputActionThree, ETriggerEvent::Triggered, this, &UInventoryManager::HandleThree);
		EnhancedInput->BindAction(InventoryInputActionFour, ETriggerEvent::Triggered, this, &UInventoryManager::HandleFour);
		EnhancedInput->BindAction(InventoryInputActionFive, ETriggerEvent::Triggered, this, &UInventoryManager::HandleFive);
		EnhancedInput->BindAction(InventoryInputActionSix, ETriggerEvent::Triggered, this, &UInventoryManager::HandleSix);
		EnhancedInput->BindAction(InventoryInputActionSeven, ETriggerEvent::Triggered, this, &UInventoryManager::HandleSeven);
		EnhancedInput->BindAction(InventoryInputActionEight, ETriggerEvent::Triggered, this, &UInventoryManager::HandleEight);
		EnhancedInput->BindAction(InventoryInputActionNine, ETriggerEvent::Triggered, this, &UInventoryManager::HandleNine);
		EnhancedInput->BindAction(InventoryInputActionZero, ETriggerEvent::Triggered, this, &UInventoryManager::HandleZero);
	}
}

void UInventoryManager::HandleOne(const FInputActionValue& Value)
{
	SetSlotSelect(0);
}

void UInventoryManager::HandleTwo(const FInputActionValue& Value)
{
	SetSlotSelect(1);
}

void UInventoryManager::HandleThree(const FInputActionValue& Value)
{
	SetSlotSelect(2);
}

void UInventoryManager::HandleFour(const FInputActionValue& Value)
{
	SetSlotSelect(3);
}

void UInventoryManager::HandleFive(const FInputActionValue& Value)
{
	SetSlotSelect(4);
}

void UInventoryManager::HandleSix(const FInputActionValue& Value)
{
	SetSlotSelect(5);
}

void UInventoryManager::HandleSeven(const FInputActionValue& Value)
{
	SetSlotSelect(6);
}

void UInventoryManager::HandleEight(const FInputActionValue& Value)
{
	SetSlotSelect(7);
}

void UInventoryManager::HandleNine(const FInputActionValue& Value)
{
	SetSlotSelect(8);
}

void UInventoryManager::HandleZero(const FInputActionValue& Value)
{
	SetSlotSelect(9);
}

#pragma endregion

#pragma region 库存操作函数

bool UInventoryManager::TryAddItem(UBaseItem* Item)
{
	if (!Item) return false;

	for (int32 i = 0; i < Slots.Num(); ++i)
		if (Slots[i].bIsEmpty)
		{
			Slots[i].SetItem(Item);
			InventoryWidget->SetSlotItem(i, Item);
			OnSlotUpdated.Broadcast(i);
			return true;
		}
	return false;
}

bool UInventoryManager::RemoveItemByIndex(const int32 SlotIndex)
{
	if (!Slots.IsValidIndex(SlotIndex)) return false;

	Slots[SlotIndex].Clear();
	InventoryWidget->ClearSlotItem(SlotIndex);
	OnSlotUpdated.Broadcast(SlotIndex);
	return true;
}

void UInventoryManager::SwapSlots(const int32 FromIndex, const int32 ToIndex)
{
	if (!Slots.IsValidIndex(FromIndex) || !Slots.IsValidIndex(ToIndex)) return;

	Swap(Slots[FromIndex], Slots[ToIndex]);
	InventoryWidget->SetSlotItem(FromIndex, Slots[ToIndex].Item);
	InventoryWidget->SetSlotItem(ToIndex, Slots[FromIndex].Item);
	OnSlotUpdated.Broadcast(FromIndex);
	OnSlotUpdated.Broadcast(ToIndex);
}

bool UInventoryManager::IsSlotEmpty(const int32 SlotIndex) const
{
	return Slots.IsValidIndex(SlotIndex) && Slots[SlotIndex].bIsEmpty;
}

UBaseItem* UInventoryManager::GetItemInSlot(const int32 SlotIndex) const
{
	return Slots.IsValidIndex(SlotIndex) ? Slots[SlotIndex].Item : nullptr;
}

UBaseItem* UInventoryManager::GetSelectItem() const
{
	return GetItemInSlot(SlotSelect);
}

void UInventoryManager::SetSlotSelect(const int32 Index)
{
	// SlotSelect = FMath::Clamp(Index, 0, Slots.Num() - 1);
	if (Index == SlotSelect || !Slots.IsValidIndex(Index)) return;
	SlotSelect = Index;
	InventoryWidget->SetSlotSelect(SlotSelect);
	OnSlotUpdated.Broadcast(SlotSelect);
}

#pragma endregion
