#define _CRT_SECURE_NO_WARNINGS

#include "Snake.h"

void test()
{
	while (true)
	{
		Snake snake = { 0 };
		GameStart(&snake);
		GameRun(&snake);
		GameEnd(&snake);
	}
}

int main()
{
	//���䱾�����Ļ���
	setlocale(LC_ALL, "");
	
	//����
	test();

	return 0;
}