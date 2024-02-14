//ʵ�ֶ���Ľӿ�/����

#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"

//��ʼ��������
//��ʼ��
void SLInit(SL* psl)
{
	//����
	assert(psl);
	psl->arr = NULL;
	psl->size = psl->capacity = 0;
}
//����
void SLDestory(SL* psl)
{
	//����
	assert(psl);
	free(psl->arr);
	psl->arr = NULL;
	psl->size = psl->capacity = 0;
}

//��ӡ˳���
//void SLPrint(SL* psl)
//{
//	//����
//	assert(psl);
//	for (int i = 0; i < psl->size; ++i)
//	{
//		printf("%d ", psl->arr[i]);
//	}
//	printf("\n");
//}

//����˳���
void SLCheckCapacity(SL* psl)
{
	//�ռ䲻��������
	if (psl->capacity == psl->size)
	{
		int newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(psl->arr, sizeof(SLDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("����ʧ�ܣ�������ֹ��\n");
			exit(EXIT_FAILURE);
		}
		//���ݳɹ�
		psl->arr = tmp;
		psl->capacity = newCapacity;
	}
}

//������ɾ��
//β������
void SLPushBack(SL* psl, SLDataType x)
{
	//����
	assert(psl);
	//�ռ䲻��������
	SLCheckCapacity(psl);
	//�ռ��㹻������
	psl->arr[psl->size++] = x;
}
//β��ɾ��
void SLPopBack(SL* psl)
{
	//����
	assert(psl);
	//˳���Ϊ�գ��޷�ɾ��
	if (!psl->size)
	{
		printf("˳���Ϊ�գ��޷�ɾ����\n");
		return;
	}
	//˳���Ϊ�գ�ɾ��
	--psl->size;
}
//ͷ������
void SLPushFront(SL* psl, SLDataType x)
{
	//����
	assert(psl);
	//�ռ䲻��������
	SLCheckCapacity(psl);
	//�ռ��㹻������
	for (int i = psl->size; i > 0; --i)
	{
		psl->arr[i] = psl->arr[i - 1];
	}
	psl->arr[0] = x;
	++psl->size;
}
//ͷ��ɾ��
void SLPopFront(SL* psl)
{
	//����
	assert(psl);
	//˳���Ϊ�գ��޷�ɾ��
	if (!psl->size)
	{
		printf("˳���Ϊ�գ��޷�ɾ����\n");
		return;
	}
	//˳���Ϊ�գ�ɾ��
	for (int i = 0; i < psl->size - 1; ++i)
	{
		psl->arr[i] = psl->arr[i + 1];
	}
	--psl->size;
}

//����λ�ò�����ɾ��
//����λ�ò���
void SLInsert(SL* psl, int pos, SLDataType x)
{
	//����
	assert(psl);
	//λ�ò��Ϸ�������ʧ��
	if (pos < 0 || pos > psl->size)
	{
		printf("����λ�ò��Ϸ�������ʧ�ܣ�\n");
		return;
	}
	//λ�úϷ�������
	//�ռ䲻��������
	SLCheckCapacity(psl);
	//�ռ��㹻������
	for (int i = psl->size; i > pos; --i)
	{
		psl->arr[i] = psl->arr[i - 1];
	}
	psl->arr[pos] = x;
	++psl->size;
}
//����λ��ɾ��
void SLRemove(SL* psl, int pos)
{
	//����
	assert(psl);
	//λ�ò��Ϸ���ɾ��ʧ��
	if (pos < 0 || pos >= psl->size)
	{
		printf("ɾ��λ�ò��Ϸ���ɾ��ʧ�ܣ�\n");
		return;
	}
	//λ�úϷ���ɾ��
	for (int i = pos; i < psl->size - 1; ++i)
	{
		psl->arr[i] = psl->arr[i + 1];
	}
	--psl->size;
}

//����
//����ĳ��Ԫ�ض�Ӧ���±�
int SLFind(SL* psl, SLDataType x)
{
	//����
	assert(psl);
	for (int i = 0; i < psl->size; ++i)
	{
		if (memcmp(&psl->arr[i], &x, sizeof(Info)))
		{
			return i;
		}
	}
	return -1;
}

//�޸�
//�޸�ĳ���±��Ӧ��Ԫ��
void SLModifyByPos(SL* psl, int pos, SLDataType x)
{
	//����
	assert(psl);
	//λ�ò��Ϸ����޸�ʧ��
	if (pos < 0 || pos >= psl->size)
	{
		printf("�޸�λ�ò��Ϸ����޸�ʧ�ܣ�\n");
		return;
	}
	//λ�úϷ����޸�
	psl->arr[pos] = x;
}

//�����±꽻������Ԫ��
void SLSwapByPos(SL* psl, int pos1, int pos2)
{
	//����
	assert(psl);
	//λ�ò��Ϸ�������ʧ��
	if (pos1 < 0 || pos1 >= psl->size || pos2 < 0 || pos2 >= psl->size)
	{
		printf("����λ�ò��Ϸ�������ʧ�ܣ�\n");
		return;
	}
	//λ�úϷ�������
	SLDataType tmp = psl->arr[pos1];
	psl->arr[pos1] = psl->arr[pos2];
	psl->arr[pos2] = tmp;
}

//ð������
void SLBubbleSort(SL* psl)
{
	//����
	assert(psl);
	//˳���Ϊ�գ��޷�����
	if (!psl->size)
	{
		printf("˳���Ϊ�գ��޷�����\n");
		return;
	}
	//˳���Ϊ�գ�����
	for (int i = 0; i < psl->size - 1; ++i)
	{
		for (int j = 0; j < psl->size - 1 - i; ++j)
		{
			if (memcmp(&psl->arr[j], &psl->arr[j + 1], sizeof(Info)) > 0)
			{
				SLSwapByPos(psl, j, j + 1);
			}
		}
	}
}