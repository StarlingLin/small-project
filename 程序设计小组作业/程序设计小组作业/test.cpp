#define _CRT_SECURE_NO_WARNINGS

#include <graphics.h>	// EasyX
#include "List.h"

int main()
{
	Node* head = (Node*)malloc(sizeof(Node));
	InitList(head);
	DestroyList(head);

	return EXIT_SUCCESS;
}
