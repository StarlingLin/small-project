#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>

//��Ϸ״̬
enum GAME_STATUS
{
	GAME_RUN,
	HIT_WALL,
	HIT_SELF,
	GAME_EXIT
};

//���ƶ�����
enum DIRECTION
{
	MOVE_UP = 1,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_DOWN
};

//������ʳ��ڵ�Ķ���
typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode* next;
} SnakeNode, * pSnakeNode;

//��Ϸ�����Ϣ�ṹ��
typedef struct Snake
{
	pSnakeNode pSnake;	//ά��������
	pSnakeNode pFood;	//ʳ��ָ��
	int Score;	//��ǰ����
	int FoodWeight;	//ÿ��ʳ��Ļ�׼����Ȩ��
	int MSPT;	//ÿ��Ϸ�̺�����
	enum GAME_STATUS status;	//��Ϸ״̬
	enum DIRECTION direction;

};

void GameStart();
void GameRun();
void GameEnd();