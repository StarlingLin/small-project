#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

int main()	//²âÊÔ´úÂë
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
	SListDestory(&node1);


	return 0;
}