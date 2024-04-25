// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimNotify_AttackHitCheck.h"
//  �������� ����⶧���� ĳ���� Ŭ������ ���� �����ϴ°� �ٶ������� ����
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
