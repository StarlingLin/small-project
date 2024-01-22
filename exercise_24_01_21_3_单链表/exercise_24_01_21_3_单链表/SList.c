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

//�½ڵ�����
SListNode* SListBuyNode(SLDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//�������ͷ��
void SListPushFront(SListNode** ppList, SLDataType x)
{
	//����
	assert(ppList);
	SListNode* newNode = SListBuyNode(x);
	newNode->next = *ppList;
	*ppList = newNode;
}
//�������β��
void SListPushBack(SListNode** ppList, SLDataType x)
{
	//����
	assert(ppList);
	SListNode* newNode = SListBuyNode(x);
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

//�������ͷɾ
void SListPopFront(SListNode** ppList)
{
	//����
	assert(ppList);
	if (*ppList == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = (*ppList)->next;
		free(*ppList);
		*ppList = next;
	}
}
//�������βɾ
void SListPopBack(SListNode** ppList)
{
	//����
	assert(ppList);
	if (*ppList == NULL)
	{
		return;
	}
	else if ((*ppList)->next == NULL)
	{
		free(*ppList);
		*ppList = NULL;
	}
	else
	{
		SListNode* cur = *ppList;
		while (cur->next->next)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
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