#define _CRT_SECURE_NO_WARNINGS

#include "Snake.h"

int MSPT_VAL[10] = { 0,1,2,3,4,5,6,7,8,9 };

void GameStart(pSnake ps)
{
	//设置控制台信息
	system("mode con cols=100 lines=26");
	system("title 骇害嗨，逝贪吃蛇");
	//隐藏光标
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOutput, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(hOutput, &CursorInfo);
	//打印初始界面
	Welcome();
	//绘制地图
	PrintMap();
	//初始化蛇
	InitSnake(ps);
	//打印节点
	PrintSnake(ps);
	//其他信息的初始化
	ps->Direction = MOVE_RIGHT;
	ps->FoodWeight = 10;
	ps->MSPT = MSPT_VAL[1];
	ps->pFood = NULL;
	ps->Score = 0;
	ps->Status = GAME_RUN;
	//创建食物
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
	//获得设备句柄
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置光标位置
	COORD pos = { x, y };
	SetConsoleCursorPosition(hOutput, pos);
}

void Welcome(void)
{
	SetPos(43, 10);
	printf("贪吃蛇，启动！");
	SetPos(42, 22);
	system("pause");
	system("cls");
	SetPos(32, 6);
	printf("使用↑、↓、←、→控制贪吃蛇的移动");
	SetPos(32, 9);
	printf("使用数字键1~9控制游戏速度（1慢9快）");
	SetPos(32, 12);
	printf("速度越高得分也越高，但是难度也越高");
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
	//创建5个蛇身的节点
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
		//头插
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
	//创建食物节点
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