#define _CRT_SECURE_NO_WARNINGS

#include "Snake.h"

int MSPT_VAL[10] = { 0,1,2,3,4,5,6,7,8,9 };

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
	//��ӡ�ڵ�
	PrintSnake(ps);
	//������Ϣ�ĳ�ʼ��
	ps->Direction = MOVE_RIGHT;
	ps->FoodWeight = 10;
	ps->MSPT = MSPT_VAL[1];
	ps->pFood = NULL;
	ps->Score = 0;
	ps->Status = GAME_RUN;
	//����ʳ��
	CreateFood(ps);
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
		pcur = (pSnakeNode)malloc(sizeof(SnakeNode));
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
}

void PrintSnake(pSnake ps)
{
	pSnakeNode pcur = ps->pSnake;
	SetPos(pcur->x, pcur->y);
	wprintf(L"%lc", HEAD);
	pcur = pcur->next;
	while (pcur)
	{
		SetPos(pcur->x, pcur->y);
		wprintf(L"%lc", BODY);
		pcur = pcur->next;
	};
}

void CreateFood(pSnake ps)
{
	srand((unsigned int)time(NULL));
	int half_x = 0, y = 0;
	do
	{
		half_x = rand() % 27 + 1;
		y = rand() % 25 + 1;
	} while (PosInSnake(2*half_x, y, ps)); 
	//����ʳ��ڵ�
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(pSnakeNode));
	if (!pFood)
	{
		system("cls");
		SetPos(0, 0);
		perror("CreatFood()->malloc()");
		exit(EXIT_FAILURE);
	}
	pFood->x = 2 * half_x;
	pFood->y = y;
	ps->pFood = pFood;
	SetPos(2 * half_x, y);
	wprintf(L"%lc", FOOD);
}

_Bool PosInSnake(int x, int y, pSnake ps)
{
	pSnakeNode pcur = ps->pSnake;
	while (pcur)
	{
		if (x == pcur->x && y == pcur->y)
		{
			return true;
		}
		pcur = pcur->next;
	}
	return false;
}