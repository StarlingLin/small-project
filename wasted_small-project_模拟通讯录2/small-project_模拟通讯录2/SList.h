//����˳���ṹ��Ҫʵ�ֵĽӿ�/����

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <Windows.h>
#include "Contact.h"

typedef Info SLDataType;

//��̬˳���
//#define N 100
//struct SeqList
//{
//	SLDataType arr[N];
//	int size;
//};

//��̬˳���
typedef struct SeqList
{
	SLDataType* arr;
	int capacity;	//��¼˳���ռ��С
	int size;		//��¼˳���ǰ��Ч���ݸ���
} SL;

//��ʼ��������
//��ʼ��
void SLInit(SL* psl);
//����
void SLDestory(SL* psl);
//��ӡ˳���
//void SLPrint(SL* psl);

//����˳���
void SLCheckCapacity(SL* psl);

//ͷ��/β��������ɾ��
//ͷ������
void SLPushBack(SL* psl, SLDataType x);
//ͷ��ɾ��
void SLPopBack(SL* psl);
//β������
void SLPushFront(SL* psl, SLDataType x);
//β��ɾ��
void SLPopFront(SL* psl);

//����λ�ò�����ɾ��
//����λ�ò���
void SLInsert(SL* psl, int pos, SLDataType x);
//����λ��ɾ��
void SLRemove(SL* psl, int pos);

//����
//����ĳ��Ԫ�ض�Ӧ���±�
int SLFind(SL* psl, SLDataType x);

//�޸�
//�޸�ĳ���±��Ӧ��Ԫ��
void SLModifyByPos(SL* psl, int pos, SLDataType x);

//�����±꽻������Ԫ��
void SLSwapByPos(SL* psl, int pos1, int pos2);

//ð������
void SLBubbleSort(SL* psl);