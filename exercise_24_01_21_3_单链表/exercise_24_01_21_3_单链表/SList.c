#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"
















//µ¥Á´±í´òÓ¡
void SListPrint(SListNode* pList)
{
	//¶ÏÑÔ
	assert(pList);
	SListNode* cur = pList;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}