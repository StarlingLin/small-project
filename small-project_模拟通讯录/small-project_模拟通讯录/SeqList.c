//实现定义的接口/方法

#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"

//初始化与销毁
//初始化
void SLInit(SL* psl)
{
	//断言
	assert(psl);
	psl->arr = NULL;
	psl->size = psl->capacity = 0;
}
//销毁
void SLDestory(SL* psl)
{
	//断言
	assert(psl);
	free(psl->arr);
	psl->arr = NULL;
	psl->size = psl->capacity = 0;
}

//打印顺序表
//void SLPrint(SL* psl)
//{
//	//断言
//	assert(psl);
//	for (int i = 0; i < psl->size; ++i)
//	{
//		printf("%d ", psl->arr[i]);
//	}
//	printf("\n");
//}

//扩容顺序表
void SLCheckCapacity(SL* psl)
{
	//空间不够，扩容
	if (psl->capacity == psl->size)
	{
		int newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(psl->arr, sizeof(SLDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("扩容失败，程序终止！\n");
			exit(EXIT_FAILURE);
		}
		//扩容成功
		psl->arr = tmp;
		psl->capacity = newCapacity;
	}
}

//插入与删除
//尾部插入
void SLPushBack(SL* psl, SLDataType x)
{
	//断言
	assert(psl);
	//空间不够，扩容
	SLCheckCapacity(psl);
	//空间足够，插入
	psl->arr[psl->size++] = x;
}
//尾部删除
void SLPopBack(SL* psl)
{
	//断言
	assert(psl);
	//顺序表为空，无法删除
	if (!psl->size)
	{
		printf("顺序表为空，无法删除！\n");
		return;
	}
	//顺序表不为空，删除
	--psl->size;
}
//头部插入
void SLPushFront(SL* psl, SLDataType x)
{
	//断言
	assert(psl);
	//空间不够，扩容
	SLCheckCapacity(psl);
	//空间足够，插入
	for (int i = psl->size; i > 0; --i)
	{
		psl->arr[i] = psl->arr[i - 1];
	}
	psl->arr[0] = x;
	++psl->size;
}
//头部删除
void SLPopFront(SL* psl)
{
	//断言
	assert(psl);
	//顺序表为空，无法删除
	if (!psl->size)
	{
		printf("顺序表为空，无法删除！\n");
		return;
	}
	//顺序表不为空，删除
	for (int i = 0; i < psl->size - 1; ++i)
	{
		psl->arr[i] = psl->arr[i + 1];
	}
	--psl->size;
}

//任意位置插入与删除
//任意位置插入
void SLInsert(SL* psl, int pos, SLDataType x)
{
	//断言
	assert(psl);
	//位置不合法，插入失败
	if (pos < 0 || pos > psl->size)
	{
		printf("插入位置不合法，插入失败！\n");
		return;
	}
	//位置合法，插入
	//空间不够，扩容
	SLCheckCapacity(psl);
	//空间足够，插入
	for (int i = psl->size; i > pos; --i)
	{
		psl->arr[i] = psl->arr[i - 1];
	}
	psl->arr[pos] = x;
	++psl->size;
}
//任意位置删除
void SLRemove(SL* psl, int pos)
{
	//断言
	assert(psl);
	//位置不合法，删除失败
	if (pos < 0 || pos >= psl->size)
	{
		printf("删除位置不合法，删除失败！\n");
		return;
	}
	//位置合法，删除
	for (int i = pos; i < psl->size - 1; ++i)
	{
		psl->arr[i] = psl->arr[i + 1];
	}
	--psl->size;
}

//查找
//查找某个元素对应的下标
int SLFind(SL* psl, SLDataType x)
{
	//断言
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

//修改
//修改某个下标对应的元素
void SLModifyByPos(SL* psl, int pos, SLDataType x)
{
	//断言
	assert(psl);
	//位置不合法，修改失败
	if (pos < 0 || pos >= psl->size)
	{
		printf("修改位置不合法，修改失败！\n");
		return;
	}
	//位置合法，修改
	psl->arr[pos] = x;
}

//根据下标交换两个元素
void SLSwapByPos(SL* psl, int pos1, int pos2)
{
	//断言
	assert(psl);
	//位置不合法，交换失败
	if (pos1 < 0 || pos1 >= psl->size || pos2 < 0 || pos2 >= psl->size)
	{
		printf("交换位置不合法，交换失败！\n");
		return;
	}
	//位置合法，交换
	SLDataType tmp = psl->arr[pos1];
	psl->arr[pos1] = psl->arr[pos2];
	psl->arr[pos2] = tmp;
}

//冒泡排序
void SLBubbleSort(SL* psl)
{
	//断言
	assert(psl);
	//顺序表为空，无法排序
	if (!psl->size)
	{
		printf("顺序表为空，无法排序！\n");
		return;
	}
	//顺序表不为空，排序
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