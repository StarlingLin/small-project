#define _CRT_SECURE_NO_WARNINGS

#include "Snake.h"

void test()
{
	GameStart();
	GameRun();
	GameEnd();
}

int main()
{
	//适配本地中文环境
	setlocale(LC_ALL, "");
	
	//测试
	test();

	return 0;
}