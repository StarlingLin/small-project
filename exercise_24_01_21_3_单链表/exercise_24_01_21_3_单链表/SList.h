//����ͷ����ѭ������(single linked list)

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//������ڵ��ֵ����
typedef int SLDataType;

//������ڵ�
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
} SListNode;

//������ĳ�ʼ��
#define SListInit(pList) SListNode* pList = NULL

//�����������
void SListDestory(SListNode** ppList);

//�������ͷ��
void SListPushFront(SListNode** ppList, SLDataType x);
//�������β��
void SListPushBack(SListNode** ppList, SLDataType x);

//������ָ��λ�ú����
void SListInsertAfter(SListNode* pos, SLDataType x);
//������ָ��λ��ǰ����
void SListInsertBefore(SListNode** ppList, SListNode* pos, SLDataType x);

//�������ͷɾ
void SListPopFront(SListNode** ppList);
//�������βɾ
void SListPopBack(SListNode** ppList);

//������ɾ��ָ��λ�õĽڵ�
void SListErase(SListNode** ppList, SListNode* pos);
//������ָ��λ�ú�ɾ��
void SListEraseAfter(SListNode* pos);
//������ָ��λ��ǰɾ��
void SListEraseBefore(SListNode** ppList, SListNode* pos);

//������ɾ������ָ��ֵ�Ľڵ�
void SListRemove(SListNode** ppList, SLDataType x);

//���������
SListNode* SListFind(SListNode* pList, SLDataType x);
//�������м�ڵ�
SListNode* SListFindMidNode(SListNode* pList);

//������ĳ���
int SListSize(SListNode* pList);
//��������п�
int SListEmpty(SListNode* pList);

//�������ӡ
void SListPrint(SListNode* pList);

//����������
void SListReverse(SListNode** ppList);

//������ð������
void SListBubbleSort(SListNode** pList);