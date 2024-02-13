//定义顺序表结构、要实现的接口/方法

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <Windows.h>
#include "Contact.h"

typedef Info SLDataType;

//静态顺序表
//#define N 100
//struct SeqList
//{
//	SLDataType arr[N];
//	int size;
//};

//动态顺序表
typedef struct SeqList
{
	SLDataType* arr;
	int capacity;	//记录顺序表空间大小
	int size;		//记录顺序表当前有效数据个数
} SL;

//初始化与销毁
//初始化
void SLInit(SL* psl);
//销毁
void SLDestory(SL* psl);
//打印顺序表
//void SLPrint(SL* psl);

//扩容顺序表
void SLCheckCapacity(SL* psl);

//头部/尾部插入与删除
//头部插入
void SLPushBack(SL* psl, SLDataType x);
//头部删除
void SLPopBack(SL* psl);
//尾部插入
void SLPushFront(SL* psl, SLDataType x);
//尾部删除
void SLPopFront(SL* psl);

//任意位置插入与删除
//任意位置插入
void SLInsert(SL* psl, int pos, SLDataType x);
//任意位置删除
void SLRemove(SL* psl, int pos);

//查找
//查找某个元素对应的下标
int SLFind(SL* psl, SLDataType x);

//修改
//修改某个下标对应的元素
void SLModifyByPos(SL* psl, int pos, SLDataType x);

//根据下标交换两个元素
void SLSwapByPos(SL* psl, int pos1, int pos2);

//冒泡排序
void SLBubbleSort(SL* psl);