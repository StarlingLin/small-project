#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

void SetPos(int x, int y)
{
	//����豸���
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ݾ�����ù��λ��
	COORD pos = { x, y };
	SetConsoleCursorPosition(handle, pos);
}

int main()
{
	////����豸���
	//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	////���ؿ���̨���
	//CONSOLE_CURSOR_INFO cursor_info = { 0 };
	//GetConsoleCursorInfo(handle, &cursor_info);
	//cursor_info.bVisible = false;
	//SetConsoleCursorInfo(handle, &cursor_info);
	SetPos(10, 10);
	printf("hello world");
	return 0;
}