#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>

#define WALL L'■'
#define BODY L'●'
#define HEAD L'◆'
#define FOOD L'★'
#define POS_X 24
#define POS_Y 5

//游戏状态
enum GAME_STATUS
{
	GAME_RUN,
	HIT_WALL,
	HIT_SELF,
	GAME_EXIT
};

//蛇移动方向
enum DIRECTION
{
	MOVE_UP = 1,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT
};

//蛇身与食物节点的定义
typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode* next;
} SnakeNode, * pSnakeNode;

//游戏相关信息结构体
typedef struct Snake
{
	pSnakeNode pSnake;	//维护整条蛇
	pSnakeNode pFood;	//食物指针
	int Score;	//当前分数
	int FoodWeight;	//每个食物的基准分数权重
	int MSPT;	//每游戏刻毫秒数
	enum GAME_STATUS status;	//游戏状态
	enum DIRECTION direction;	//蛇移动方向

} Snake, * pSnake;

void GameStart(pSnake ps);
void GameRun(pSnake ps);
void GameEnd(pSnake ps);

void SetPos(int x, int y);

void Welcome(void);
void PrintMap(void);
void InitSnake(pSnake ps);