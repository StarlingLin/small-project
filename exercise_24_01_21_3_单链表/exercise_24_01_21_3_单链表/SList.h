#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//单链表节点的值类型
typedef int SLDataType;

//单链表节点
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
} SListNode;

//单链表的初始化
void SListInit(SListNode** ppList);
//单链表的销毁
void SListDestory(SListNode** ppList);

//单链表的头插
void SListPushFront(SListNode** ppList, SLDataType x);
//单链表的尾插
void SListPushBack(SListNode** ppList, SLDataType x);










//单链表打印
void SListPrint(SListNode* pList);