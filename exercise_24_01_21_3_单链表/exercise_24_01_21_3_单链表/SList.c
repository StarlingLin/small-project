#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"
















//�������ӡ
void SListPrint(SListNode* pList)
{
	//����
	assert(pList);
	SListNode* cur = pList;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}