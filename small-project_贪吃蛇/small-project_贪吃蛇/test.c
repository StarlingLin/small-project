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
	//���䱾�����Ļ���
	setlocale(LC_ALL, "");
	
	//����
	test();

	return 0;
}