#define _CRT_SECURE_NO_WARNINGS
//ʵ������ͷ�ļ��Ľӿ�
#include "List.h"

//��ʼ������
void InitList(Node* pList)
{
	//����
	assert(pList != NULL);
	pList->data = NULL;
	pList->next = NULL;
}
//��������
void DestroyList(Node* pList)
{
	//����
	assert(pList != NULL);
	Node* p = pList->next;
	Node* q = NULL;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	pList->next = NULL;
}

//��ȡ������
int GetLength(Node* pList)
{
	//����
	assert(pList != NULL);
	int n = 0;
	Node* p = pList->next;
	while (p != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}

//ͷ��/β������
void PushFront(Node* pList, ListDataType* data)
{
	//����
	assert(pList != NULL);
	Node* pNew = (Node*)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		printf("�ڴ����ʧ�ܣ�\n");
		exit(EXIT_FAILURE);
	}
	pNew->data = data;
	pNew->next = pList->next;
	pList->next = pNew;
}
void PushBack(Node* pList, ListDataType* data)
{
	//����
	assert(pList != NULL);
	Node* p = pList;
	while (p->next != NULL)
	{
		p = p->next;
	}
	Node* pNew = (Node*)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		printf("�ڴ����ʧ�ܣ�\n");
		exit(EXIT_FAILURE);
	}
	pNew->data = data;
	pNew->next = NULL;
	p->next = pNew;
}
//ͷ��/β��ɾ��
void PopFront(Node* pList)
{
	//����
	assert(pList != NULL);
	Node* p = pList->next;
	if (p != NULL)
	{
		pList->next = p->next;
		free(p);
	}
}
void PopBack(Node* pList)
{
	//����
	assert(pList != NULL);
	Node* p = pList;
	while (p->next->next != NULL)
	{
		p = p->next;
	}
	Node* q = p->next;
	p->next = NULL;
	free(q);
}
//����λ�ò���/ɾ��
void Insert(Node* pList, int pos, ListDataType* data)
{
	//����
	assert(pList != NULL);
	Node* p = pList;
	int i = 0;
	while (p != NULL && i < pos)
	{
		p = p->next;
		i++;
	}
	if (p != NULL)
	{
		Node* pNew = (Node*)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			printf("�ڴ����ʧ�ܣ�\n");
			exit(EXIT_FAILURE);
		}
		pNew->data = data;
		pNew->next = p->next;
		p->next = pNew;
	}
}
void Erase(Node* pList, int pos)
{
	//����
	assert(pList != NULL);
	Node* p = pList;
	int i = 0;
	while (p != NULL && i < pos)
	{
		p = p->next;
		i++;
	}
	if (p != NULL && p->next != NULL)
	{
		Node* q = p->next;
		p->next = q->next;
		free(q);
	}
}