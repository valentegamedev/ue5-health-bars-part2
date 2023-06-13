// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VHealthBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class HEALTHBARS_API UVHealthBarWidget : public UUserWidget
{
	GENERATED_BODY()
	
	TWeakObjectPtr<class UVHealthComponent> TargetHealthComponent;

	UFUNCTION()
	void OnHealthChanged(int32 NewHealth, int32 MaxHealth);
protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* HealthProgressBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* HealthTextBlock;

	
public:
	UFUNCTION(BlueprintCallable)
	void SetTargetHealthComponent(UVHealthComponent* NewHealthComponent);
};
