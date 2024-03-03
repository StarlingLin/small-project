#pragma once

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
//�������
void ClearList(Node* pList);

//��ȡ������
int GetLength(Node* pList);
//�ж������Ƿ�Ϊ��
int IsEmpty(Node* pList);

//ͷ��/β������
void PushFront(Node* pList, ListDataType* data);
void PushBack(Node* pList, ListDataType* data);
//ͷ��/β��ɾ��
void PopFront(Node* pList);
void PopBack(Node* pList);
//����λ�ò���/ɾ��
void Insert(Node* pList, int pos, ListDataType* data);
void Erase(Node* pList, int pos);

