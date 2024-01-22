#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

int main()	//测试代码
{
	SListNode* node1 = (SListNode*)malloc(sizeof(SListNode));
	SListNode* node2 = (SListNode*)malloc(sizeof(SListNode));
	SListNode* node3 = (SListNode*)malloc(sizeof(SListNode));
	SListNode* node4 = (SListNode*)malloc(sizeof(SListNode));
	SListNode* node5 = (SListNode*)malloc(sizeof(SListNode));
	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;
	node5->data = 5; 
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	SListPrint(node1);
	SListPushBack(&node1, 6);
	SListPrint(node1);
	SListPushFront(&node1, 0);
	SListPrint(node1);
	SListPopBack(&node1);
	SListPrint(node1);
	SListPopFront(&node1);
	SListPrint(node1);
	SListInsertAfter(node3, 7);
	SListPrint(node1);
	SListInsertBefore(&node1, node1, 8);
	SListPrint(node1);
	SListErase(&node1, node4);
	SListPrint(node1);
	SListEraseAfter(node3);
	SListPrint(node1);
	SListEraseBefore(&node1, node2);
	SListPrint(node1);

	SListNode* FindRet = SListFind(node1, 3);
	if (FindRet)
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}






	SListDestory(&node1);


	return 0;
}