#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

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
	if (newNode == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
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

//������ָ��λ�ú����
void SListInsertAfter(SListNode* pos, SLDataType x)
{
	//����
	assert(pos);
	SListNode* newNode = SListBuyNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}
//������ָ��λ��ǰ����
void SListInsertBefore(SListNode** ppList, SListNode* pos, SLDataType x)
{
	//����
	assert(ppList&&pos);
	if (*ppList == NULL || *ppList == pos)	//���������posΪͷ�ڵ�
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

//������ɾ��ָ��λ�õĽڵ�
void SListErase(SListNode** ppList, SListNode* pos)
{
	//����
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
//������ָ��λ�ú�ɾ��
void SListEraseAfter(SListNode* pos)
{
	//����
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
//������ָ��λ��ǰɾ��
void SListEraseBefore(SListNode** ppList, SListNode* pos)
{
	//����
	assert(ppList&&pos);
	if (*ppList == NULL || *ppList == pos)	//���������posΪͷ�ڵ�
	{
		return;
	}
	else if ((*ppList)->next == pos)	//posΪ�ڶ����ڵ�
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

//������ɾ������ָ��ֵ�Ľڵ�
void SListRemove(SListNode** ppList, SLDataType x)
{
	//����
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

//���������
SListNode* SListFind(SListNode* pList, SLDataType x)
{
	//����
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
//�������м�ڵ�
SListNode* SListFindMidNode(SListNode* pList)
{
	//����
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

//������ĳ���
int SListSize(SListNode* pList)
{
	//����
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
//��������п�
int SListEmpty(SListNode* pList)
{
	return pList == NULL ? 1 : 0;
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

//����������
void SListReverse(SListNode** ppList)
{
	//����
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

//������ð������
void SListBubbleSort(SListNode** pList)
{
	//����
	assert(pList);
	if (*pList == NULL || (*pList)->next == NULL)
	{
		return;
	}
	else
	{
		SListNode* tail = NULL;	//β�ڵ�
		while (tail != *pList)	//ֻ��һ���ڵ�ʱ��tail==*pList
		{
			SListNode* cur = *pList;	//��ǰ�ڵ�
			SListNode* next = cur->next;	//��һ���ڵ�
			SListNode* prev = NULL;	//��ǰ�ڵ��ǰһ���ڵ�
			while (next != tail)	//ֻ�������ڵ�ʱ��next==tail
			{
				if (cur->data > next->data)	//����
				{
					if (cur == *pList)	//ͷ�ڵ㽻��
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
				else	//������
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