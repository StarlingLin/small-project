//不带头单向不循环链表(single linked list)

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
#define SListInit(pList) SListNode* pList = NULL

//单链表的销毁
void SListDestory(SListNode** ppList);

//单链表的头插
void SListPushFront(SListNode** ppList, SLDataType x);
//单链表的尾插
void SListPushBack(SListNode** ppList, SLDataType x);

//单链表指定位置后插入
void SListInsertAfter(SListNode* pos, SLDataType x);
//单链表指定位置前插入
void SListInsertBefore(SListNode** ppList, SListNode* pos, SLDataType x);

//单链表的头删
void SListPopFront(SListNode** ppList);
//单链表的尾删
void SListPopBack(SListNode** ppList);

//单链表删除指定位置的节点
void SListErase(SListNode** ppList, SListNode* pos);
//单链表指定位置后删除
void SListEraseAfter(SListNode* pos);
//单链表指定位置前删除
void SListEraseBefore(SListNode** ppList, SListNode* pos);

//单链表删除所有指定值的节点
void SListRemove(SListNode** ppList, SLDataType x);

//单链表查找
SListNode* SListFind(SListNode* pList, SLDataType x);
//单链表中间节点
SListNode* SListFindMidNode(SListNode* pList);

//单链表的长度
int SListSize(SListNode* pList);
//单链表的判空
int SListEmpty(SListNode* pList);

//单链表打印
void SListPrint(SListNode* pList);

//单链表逆序
void SListReverse(SListNode** ppList);

//单链表冒泡排序
void SListBubbleSort(SListNode** pList);