#define _CRT_SECURE_NO_WARNINGS

#include "Snake.h"

void test()
{
	int ch = 0;
	do
	{
		Snake snake = { 0 };
		GameStart(&snake);
		GameRun(&snake);
		GameEnd(&snake);
		ch = getchar();
		scanf("%*[^\n]");
	} while (ch == 'Y' || ch == 'y');
}

int main()
{
	//适配本地中文环境
	setlocale(LC_ALL, "");
	
	//测试
	test();

	return 0;
}