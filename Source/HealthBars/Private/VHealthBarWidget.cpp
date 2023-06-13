// Fill out your copyright notice in the Description page of Project Settings.


#include "VHealthBarWidget.h"

#include "VHealthComponent.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UVHealthBarWidget::OnHealthChanged(int32 NewHealth, int32 MaxHealth)
{
	float Percentage = static_cast<float>(NewHealth)/MaxHealth;
	HealthProgressBar->SetPercent(Percentage);
	HealthTextBlock->SetText(FText::FromString(FString::Printf(TEXT("%d%%"), static_cast<int32>(Percentage*100))));
}

void UVHealthBarWidget::SetTargetHealthComponent(UVHealthComponent* NewHealthComponent)
{
	//Unregister from the old target health component
	if (TargetHealthComponent.IsValid())
	{
		TargetHealthComponent->OnHealthChanged.RemoveDynamic(this, &UVHealthBarWidget::OnHealthChanged);
	}
	
	TargetHealthComponent = NewHealthComponent;

	//Register to the new target health component
	if(TargetHealthComponent.IsValid())
	{
		TargetHealthComponent->OnHealthChanged.AddDynamic(this, &UVHealthBarWidget::OnHealthChanged);
	}
}
