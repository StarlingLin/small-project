#define _CRT_SECURE_NO_WARNINGS

#include "Snake.h"

void GameStart(pSnake ps)
{
	//���ÿ���̨��Ϣ
	system("mode con cols=100 lines=26");
	system("title �����ˣ���̰����");
	//���ع��
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOutput, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(hOutput, &CursorInfo);
	//��ӡ��ʼ����
	Welcome();
	//���Ƶ�ͼ
	PrintMap();
	//��ʼ����
	InitSnake(ps);

}

void GameRun(pSnake ps)
{

}

void GameEnd(pSnake ps)
{

}

void SetPos(int x, int y)
{
	//����豸���
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ù��λ��
	COORD pos = { x, y };
	SetConsoleCursorPosition(hOutput, pos);
}

void Welcome(void)
{
	SetPos(43, 10);
	printf("̰���ߣ�������");
	SetPos(42, 22);
	system("pause");
	system("cls");
	SetPos(32, 6);
	printf("ʹ�á�����������������̰���ߵ��ƶ�");
	SetPos(32, 9);
	printf("ʹ�����ּ�1~9������Ϸ�ٶȣ�1��9�죩");
	SetPos(32, 12);
	printf("�ٶ�Խ�ߵ÷�ҲԽ�ߣ������Ѷ�ҲԽ��");
	SetPos(42, 22);
	system("pause");
	system("cls");
}

void PrintMap(void)
{
	SetPos(0, 0);
	for (int i = 0; i <= 28; ++i)
		wprintf(L"%lc", WALL);
	SetPos(0, 25);
	for (int i = 0; i <= 28; ++i)
		wprintf(L"%lc", WALL);
	for (int i = 1; i <= 24; ++i)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}
	for (int i = 1; i <= 24; ++i)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}
}

void InitSnake(pSnake ps)
{
	pSnakeNode pcur = NULL;
	//����5������Ľڵ�
	for (int i = 0; i < 5; ++i)
	{
		pcur = (pSnake)malloc(sizeof(SnakeNode));
		if (!pcur)
		{ 
			system("cls");
			SetPos(0, 0);
			perror("InitSnake()->malloc()");
			exit(EXIT_FAILURE);
		}
		pcur->x = POS_X + 2 * i;
		pcur->y = POS_Y;
		pcur->next = NULL;
		//ͷ��
		if (!ps->pSnake)
		{
			ps->pSnake = pcur;
		}
		else
		{
			pcur->next = ps->pSnake;
			ps->pSnake = pcur;
		}
	}
	//��ӡ�ڵ�
	pcur = ps->pSnake;
	do
	{
		SetPos(pcur->x, pcur->y);
		wprintf(L"%lc", BODY);
		pcur = pcur->next;
	} while (pcur->next);
	SetPos(pcur->x, pcur->y);
	wprintf(L"%lc", HEAD);
}