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












//单链表打印
void SListPrint(SListNode* pList);