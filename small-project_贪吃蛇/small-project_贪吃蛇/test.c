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
	//���䱾�����Ļ���
	setlocale(LC_ALL, "");
	
	//����
	test();

	return 0;
}