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

//单链表的头插
void SListPushFront(SListNode** ppList, SLDataType x)
{
	//断言
	assert(ppList);
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = *ppList;
	*ppList = newNode;
}
//单链表的尾插
void SListPushBack(SListNode** ppList, SLDataType x)
{
	//断言
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