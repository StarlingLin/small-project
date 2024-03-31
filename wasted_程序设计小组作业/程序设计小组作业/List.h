#pragma once
//�����ͷ�ļ�
#include "system.h"

//���������������
typedef Student ListDataType;

//��������ṹ��
typedef struct Node
{
	ListDataType *data;
	struct Node *next;
} Node;

//��ʼ������
void InitList(Node* pList);
//��������
void DestroyList(Node* pList);

//��ȡ������
int GetLength(Node* pList);

//ͷ��/β������
void PushFront(Node* pList, ListDataType* data);
void PushBack(Node* pList, ListDataType* data);
//ͷ��/β��ɾ��
void PopFront(Node* pList);
void PopBack(Node* pList);
//����λ�ò���/ɾ��
void Insert(Node* pList, int pos, ListDataType* data);
void Erase(Node* pList, int pos);

//����/��������
bool SaveData(Node* pList);
bool LoadData(Node* pList);
bool LoadDataBinary(Node* pList);

#define LoadList(head)							\
	Node* head = (Node*)malloc(sizeof(Node));	\
	InitList(head);								\
	if (!LoadData(head))						\
	{											\
		LoadDataBinary(head);					\
	}