#define _CRT_SECURE_NO_WARNINGS

#include "Snake.h"

void test()
{
	Snake snake = { 0 };
	GameStart(&snake);
	GameRun(&snake);
	GameEnd(&snake);
}

int main()
{
	//���䱾�����Ļ���
	setlocale(LC_ALL, "");
	
	//����
	test();
	getchar();

	return 0;
}