#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

void SetPos(int x, int y)
{
	//获得设备句柄
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//根据句柄设置光标位置
	COORD pos = { x, y };
	SetConsoleCursorPosition(handle, pos);
}

int main()
{
	////获得设备句柄
	//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	////隐藏控制台光标
	//CONSOLE_CURSOR_INFO cursor_info = { 0 };
	//GetConsoleCursorInfo(handle, &cursor_info);
	//cursor_info.bVisible = false;
	//SetConsoleCursorInfo(handle, &cursor_info);
	SetPos(10, 10);
	printf("hello world");
	return 0;
}