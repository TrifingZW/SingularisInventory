/* =====================================================================
 * BaseItemActor.cpp
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2024 TrifingZW <TrifingZW@gmail.com>
 * 
 * Copyright (c) 2024 TrifingZW
 * Licensed under MIT License
 * ===================================================================== */


#include "BaseItemActor.h"

ABaseItemActor::ABaseItemActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseItemActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseItemActor::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

}

