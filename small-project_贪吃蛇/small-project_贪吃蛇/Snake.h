#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>
#include <time.h>
#include <math.h>

#define WALL L'■'
#define BODY L'●'
#define HEAD L'◆'
#define FOOD L'★'
#define POS_X 24
#define POS_Y 5

#define KEY_PRESSED(VK) ( (GetAsyncKeyState(VK) & 0x1) ? 1 : 0 )

//游戏状态
enum GAME_STATUS
{
	GAME_RUN,
	HIT_WALL,
	HIT_SELF,
	GAME_EXIT,
	FINISH_ALL
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
	long double Score;	//当前分数
	long double HighScore;	//最高分
	long double FoodWeight;	//每个食物的基准分数权重
	int FoodEaten;	//已吃食物数量
	int MSPT;	//每游戏刻毫秒数等级
	enum GAME_STATUS Status;	//游戏状态
	enum DIRECTION Direction;	//蛇移动方向

} Snake, * pSnake;

void GameStart(pSnake ps);
void GameRun(pSnake ps);
void GameEnd(pSnake ps);

void SetPos(int x, int y);

long double GetHighScore(void);
void SetHighScore(long double score);

void Welcome(void);
void PrintMap(void);
void InitSnake(pSnake ps);
void PrintSnake(pSnake ps);
void PrintInfo(pSnake ps);
void CreateFood(pSnake ps);
void PauseGame(pSnake ps);
void SnakeMove(pSnake ps);
void HitWall(pSnake ps);
void HitSelf(pSnake ps);
_Bool HeadInSelf(pSnake ps);
void EatFood(pSnake ps, pSnakeNode pNext);
void MoveForward(pSnake ps, pSnakeNode pNext);
long double CalcFoodM(int m);
_Bool PosInSnake(int x, int y, pSnake ps);
_Bool PosIsFood(pSnakeNode pNext, pSnake ps);