#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	char mine[IROW][ICOL];
	char show[IROW][ICOL];
	char fakebool[IROW][ICOL];
	InitBoard(mine, IROW, ICOL, '0');
	InitBoard(show, IROW, ICOL, '*');
	//��һ��α����ֵ�����ڱ����Щ����Ӧ�ñ���ʾ����
	InitBoard(fakebool, IROW, ICOL, '0');
	DisplayBoard(show, IROW, ICOL);
	//DisplayBoard(mine, IROW, ICOL);
	SetMine(mine, show, fakebool);
	//DisplayBoard(show, IROW, ICOL);
	//DisplayBoard(mine, IROW, ICOL);
	FindMine(show, mine, fakebool);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		system("CLS");
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1: system("CLS"); game(); break;
		case 0: system("CLS"); break;
		default: system("CLS"); printf("ѡ������ֵ\n"); break;
		}
	} while (input);
	return 0;
}