#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

//������ĳ�ʼ��
void SListInit(SListNode** ppList)
{
	//����
	assert(ppList);
	*ppList = NULL;
}
//�����������
void SListDestory(SListNode** ppList)
{
	//����
	assert(ppList);
	SListNode* cur = *ppList;
	while (cur)
	{
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*ppList = NULL;
}

//�������ͷ��
void SListPushFront(SListNode** ppList, SLDataType x)
{
	//����
	assert(ppList);
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = *ppList;
	*ppList = newNode;
}
//�������β��
void SListPushBack(SListNode** ppList, SLDataType x)
{
	//����
	assert(ppList);
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;
	if (*ppList == NULL)
	{
		*ppList = newNode;
	}
	else
	{
		SListNode* cur = *ppList;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}














//�������ӡ
void SListPrint(SListNode* pList)
{
	//����
	assert(pList);
	SListNode* cur = pList;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}