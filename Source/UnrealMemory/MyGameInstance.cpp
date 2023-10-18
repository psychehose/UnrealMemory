﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Student.h"
#include "StudentManager.h"


void CheckUObjectIsValid(const UObject* InObject, const FString& InTag)
{
	if (InObject->IsValidLowLevel()) 
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 유효한 언리얼 프로젝트"), *InTag);
	}
	else 
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 유효하지 않은 언리얼 프로젝트"), *InTag);
	}
}

void CheckUObjectIsNull(const UObject* InObject, const FString& InTag)
{
	if (InObject == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 널 포인터 언리얼 프로젝트"), *InTag);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 널 포인터가 아닌 언리얼 프로젝트"), *InTag);
	}
}

void UMyGameInstance::Init()
{
	Super::Init();

	NonPropStudent = NewObject<UStudent>();
	PropStudent = NewObject<UStudent>();

	NonPropStudents.Add(NewObject<UStudent>());
	PropStudents.Add(NewObject<UStudent>());

	StudentManager = new FStudentManager(NewObject<UStudent>());

}

void UMyGameInstance::Shutdown()
{
	Super::Shutdown();


	const UStudent* StudentInManger = StudentManager->GetStudent();


	delete StudentManager;
	StudentManager = nullptr;

	CheckUObjectIsNull(StudentInManger, TEXT("StudentInManger"));
	CheckUObjectIsValid(StudentInManger, TEXT("StudentInManger"));



	CheckUObjectIsNull(NonPropStudent, TEXT("NonPropStudent"));
	CheckUObjectIsValid(NonPropStudent, TEXT("NonPropStudent"));

	CheckUObjectIsNull(PropStudent, TEXT("PropStudent"));
	CheckUObjectIsValid(PropStudent, TEXT("PropStudent"));
}
