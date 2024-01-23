#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

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
	if (newNode == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
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

//单链表指定位置后插入
void SListInsertAfter(SListNode* pos, SLDataType x)
{
	//断言
	assert(pos);
	SListNode* newNode = SListBuyNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}
//单链表指定位置前插入
void SListInsertBefore(SListNode** ppList, SListNode* pos, SLDataType x)
{
	//断言
	assert(ppList&&pos);
	if (*ppList == NULL || *ppList == pos)	//空链表或者pos为头节点
	{
		SListPushFront(ppList, x);
	}
	else
	{
		SListNode* cur = *ppList;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		SListNode* newNode = SListBuyNode(x);
		newNode->next = cur->next;
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

//单链表删除指定位置的节点
void SListErase(SListNode** ppList, SListNode* pos)
{
	//断言
	assert(ppList&&pos);
	if (*ppList == NULL)
	{
		return;
	}
	else if (*ppList == pos)
	{
		SListPopFront(ppList);
	}
	else
	{
		SListNode* cur = *ppList;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
	}
}
//单链表指定位置后删除
void SListEraseAfter(SListNode* pos)
{
	//断言
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = pos->next->next;
		free(pos->next);
		pos->next = next;
	}
}
//单链表指定位置前删除
void SListEraseBefore(SListNode** ppList, SListNode* pos)
{
	//断言
	assert(ppList&&pos);
	if (*ppList == NULL || *ppList == pos)	//空链表或者pos为头节点
	{
		return;
	}
	else if ((*ppList)->next == pos)	//pos为第二个节点
	{
		SListPopFront(ppList);
	}
	else
	{
		SListNode* cur = *ppList;
		while (cur->next->next != pos)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = pos;
	}
}

//单链表删除所有指定值的节点
void SListRemove(SListNode** ppList, SLDataType x)
{
	//断言
	assert(ppList);
	if (*ppList == NULL)
	{
		return;
	}
	else
	{
		SListNode* cur = *ppList;
		while (cur->next)
		{
			if (cur->next->data == x)
			{
				SListNode* next = cur->next->next;
				free(cur->next);
				cur->next = next;
			}
			else
			{
				cur = cur->next;
			}
		}
		if ((*ppList)->data == x)
		{
			SListPopFront(ppList);
		}
	}
}

//单链表查找
SListNode* SListFind(SListNode* pList, SLDataType x)
{
	//断言
	assert(pList);
	SListNode* cur = pList;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//单链表中间节点
SListNode* SListFindMidNode(SListNode* pList)
{
	//断言
	assert(pList);
	SListNode* fast = pList;
	SListNode* slow = pList;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

//单链表的长度
int SListSize(SListNode* pList)
{
	//断言
	assert(pList);
	int count = 0;
	SListNode* cur = pList;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
//单链表的判空
int SListEmpty(SListNode* pList)
{
	return pList == NULL ? 1 : 0;
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

//单链表逆序
void SListReverse(SListNode** ppList)
{
	//断言
	assert(ppList);
	if (*ppList == NULL || (*ppList)->next == NULL)
	{
		return;
	}
	else
	{
		SListNode* cur = *ppList;
		SListNode* next = cur->next;
		SListNode* nextNext = next->next;
		while (next)
		{
			next->next = cur;
			cur = next;
			next = nextNext;
			if (nextNext)
			{
				nextNext = nextNext->next;
			}
		}
		(*ppList)->next = NULL;
		*ppList = cur;
	}
}

//单链表冒泡排序
void SListBubbleSort(SListNode** pList)
{
	//断言
	assert(pList);
	if (*pList == NULL || (*pList)->next == NULL)
	{
		return;
	}
	else
	{
		SListNode* tail = NULL;	//尾节点
		while (tail != *pList)	//只有一个节点时，tail==*pList
		{
			SListNode* cur = *pList;	//当前节点
			SListNode* next = cur->next;	//下一个节点
			SListNode* prev = NULL;	//当前节点的前一个节点
			while (next != tail)	//只有两个节点时，next==tail
			{
				if (cur->data > next->data)	//交换
				{
					if (cur == *pList)	//头节点交换
					{
						cur->next = next->next;
						next->next = cur;
						*pList = next;
						prev = next;
						next = cur->next;
					}
					else
					{
						cur->next = next->next;
						next->next = cur;
						prev->next = next;
						prev = next;
						next = cur->next;
					}
				}
				else	//不交换
				{
					prev = cur;
					cur = next;
					next = next->next;
				}
			}
			tail = cur;
		}
	}
}