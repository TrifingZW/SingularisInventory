/* =====================================================================
 * InventoryWidget.cpp
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2024 TrifingZW <TrifingZW@gmail.com>
 * 
 * Copyright (c) 2024 TrifingZW
 * Licensed under MIT License
 * ===================================================================== */

#include "InventoryWidget.h"

void UInventoryWidget::ShowWidget()
{
	SetVisibility(ESlateVisibility::Visible);
}

void UInventoryWidget::HideWidget()
{
	SetVisibility(ESlateVisibility::Hidden);
}
