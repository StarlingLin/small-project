#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//������ڵ��ֵ����
typedef int SLDataType;

//������ڵ�
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
} SListNode;

//������ĳ�ʼ��
void SListInit(SListNode** ppList);
//�����������
void SListDestory(SListNode** ppList);

//�������ͷ��
void SListPushFront(SListNode** ppList, SLDataType x);
//�������β��
void SListPushBack(SListNode** ppList, SLDataType x);

//�������ͷɾ
void SListPopFront(SListNode** ppList);
//�������βɾ
void SListPopBack(SListNode** ppList);








//�������ӡ
void SListPrint(SListNode* pList);