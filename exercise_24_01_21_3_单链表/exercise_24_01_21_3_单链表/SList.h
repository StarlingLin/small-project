#pragma once

#include <stdio.h>
#include <stdlib.h>

//������ڵ��ֵ����
typedef int SLDataType;

//������ڵ�
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
} SListNode;

