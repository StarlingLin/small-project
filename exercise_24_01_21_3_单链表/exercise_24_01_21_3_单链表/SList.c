#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

//单链表的初始化
void SListInit(SListNode** ppList)
{
	//断言
	assert(ppList);
	*ppList = NULL;
}
//单链表的销毁
void SListDestory(SListNode** ppList)
{
	//断言
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

//新节点申请
SListNode* SListBuyNode(SLDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//单链表的头插
void SListPushFront(SListNode** ppList, SLDataType x)
{
	//断言
	assert(ppList);
	SListNode* newNode = SListBuyNode(x);
	newNode->next = *ppList;
	*ppList = newNode;
}
//单链表的尾插
void SListPushBack(SListNode** ppList, SLDataType x)
{
	//断言
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

//单链表的头删
void SListPopFront(SListNode** ppList)
{
	//断言
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
//单链表的尾删
void SListPopBack(SListNode** ppList)
{
	//断言
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










//单链表打印
void SListPrint(SListNode* pList)
{
	//断言
	assert(pList);
	SListNode* cur = pList;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}