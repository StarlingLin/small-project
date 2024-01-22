#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

int main()	//测试代码
{
	SListInit(node);	//单链表的初始化
	SListPushBack(&node, 1);	//1->NULL
	SListPushBack(&node, 2);	//1->2->NULL
	SListPushBack(&node, 3);	//1->2->3->NULL
	SListPushBack(&node, 4);	//1->2->3->4->NULL
	SListPushBack(&node, 5);	//1->2->3->4->5->NULL
	SListPrint(node);
	SListPushBack(&node, 6);	//1->2->3->4->5->6->NULL
	SListPrint(node);
	SListPushFront(&node, 0);	//0->1->2->3->4->5->6->NULL
	SListPrint(node);
	SListPopBack(&node);	//0->1->2->3->4->5->NULL
	SListPrint(node);
	SListPopFront(&node);	//1->2->3->4->5->NULL
	SListPrint(node);
	SListInsertAfter(SListFind(node, 3), 7);	//1->2->3->7->4->5->NULL
	SListPrint(node);
	SListInsertBefore(&node, SListFind(node, 1), 8);	//8->1->2->3->7->4->5->NULL
	SListPrint(node);
	SListErase(&node, SListFind(node, 4));	//8->1->2->3->7->5->NULL
	SListPrint(node);
	SListEraseAfter(SListFind(node, 3));	//8->1->2->3->5->NULL
	SListPrint(node);
	SListEraseBefore(&node, SListFind(node, 2));	//8->2->3->5->NULL
	SListPrint(node);
	SListReverse(&node);	//5->3->2->8->NULL
	SListPrint(node);
	//SListBubbleSort(node);	//2->3->5->8->NULL
	//SListPrint(node);

	SListNode* FindRet = SListFind(node, 3);
	if (FindRet)
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}

	SListDestory(&node);


	return 0;
}