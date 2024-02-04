#define _CRT_SECURE_NO_WARNINGS

#include "Snake.h"

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
	//打印节点
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