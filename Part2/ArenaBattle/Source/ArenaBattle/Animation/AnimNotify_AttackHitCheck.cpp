// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimNotify_AttackHitCheck.h"
//  의존성이 생기기때문에 캐릭터 클래스를 직접 참조하는건 바람직하지 않음
//#include "Character/ABCharacterBase.h"	
#include "Interface/ABAnimationAttackInterface.h"

void UAnimNotify_AttackHitCheck::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp)
	{
		IABAnimationAttackInterface* AtttackPawn = Cast<IABAnimationAttackInterface>(MeshComp->GetOwner());
		if(AtttackPawn)
		{
			AtttackPawn->AttackHitCheck();
		}
	}
}
