#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <locale.h>

#define KEY_ISPRESS(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)	//判断按键是否按下
#define KEY_PRESSED(vk_code) ((GetAsyncKeyState(vk_code) & 0x0001) ? 1 : 0)	//判断按键是否按过

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

	//SetPos(10, 10);
	//printf("hello world");

	//while (true)
	//{
	//	if (KEY_PRESSED(0x30))
	//		printf("0\n");
	//	if (KEY_PRESSED(0x31))
	//		printf("1\n");
	//	if (KEY_PRESSED(0x32))
	//		printf("2\n");
	//	if (KEY_PRESSED(0x33))
	//		printf("3\n");
	//	if (KEY_PRESSED(0x34))
	//		printf("4\n");
	//	if (KEY_PRESSED(0x35))
	//		printf("5\n");
	//	if (KEY_PRESSED(0x36))
	//		printf("6\n");
	//	if (KEY_PRESSED(0x37))
	//		printf("7\n");
	//	if (KEY_PRESSED(0x38))
	//		printf("8\n");
	//	if (KEY_PRESSED(0x39))
	//		printf("9\n");
	//	if (KEY_PRESSED(0x41))
	//		printf("A\n");
	//	if (KEY_PRESSED(0x42))
	//		printf("B\n");
	//	if (KEY_PRESSED(0x43))
	//		printf("C\n");
	//	if (KEY_PRESSED(0x44))
	//		printf("D\n");
	//	if (KEY_PRESSED(0x45))
	//		printf("E\n");
	//	if (KEY_PRESSED(0x46))
	//		printf("F\n");
	//	if (KEY_PRESSED(0x47))
	//		printf("G\n");
	//	if (KEY_PRESSED(0x48))
	//		printf("H\n");
	//	if (KEY_PRESSED(0x49))
	//		printf("I\n");
	//	if (KEY_PRESSED(0x4A))
	//		printf("J\n");
	//	if (KEY_PRESSED(0x4B))
	//		printf("K\n");
	//	if (KEY_PRESSED(0x4C))
	//		printf("L\n");
	//	if (KEY_PRESSED(0x4D))
	//		printf("M\n");
	//	if (KEY_PRESSED(0x4E))
	//		printf("N\n");
	//	if (KEY_PRESSED(0x4F))
	//		printf("O\n");
	//	if (KEY_PRESSED(0x50))
	//		printf("P\n");
	//	if (KEY_PRESSED(0x51))
	//		printf("Q\n");
	//	if (KEY_PRESSED(0x52))
	//		printf("R\n");
	//	if (KEY_PRESSED(0x53))
	//		printf("S\n");
	//	if (KEY_PRESSED(0x54))
	//		printf("T\n");
	//	if (KEY_PRESSED(0x55))
	//		printf("U\n");
	//	if (KEY_PRESSED(0x56))
	//		printf("V\n");
	//	if (KEY_PRESSED(0x57))
	//		printf("W\n");
	//	if (KEY_PRESSED(0x58))
	//		printf("X\n");
	//	if (KEY_PRESSED(0x59))
	//		printf("Y\n");
	//	if (KEY_PRESSED(0x5A))
	//		printf("Z\n");
	//	if (KEY_PRESSED(0x08))
	//		printf("Backspace\n");
	//	if (KEY_PRESSED(0x09))
	//		printf("Tab\n");
	//	if (KEY_PRESSED(0x0D))
	//		printf("Enter\n");
	//	if (KEY_PRESSED(0x1B))
	//		printf("Esc\n");
	//	if (KEY_PRESSED(0x20))
	//		printf("Space\n");
	//	if (KEY_PRESSED(0x2E))
	//		printf("Delete\n");
	//}

	char* str = setlocale(LC_ALL, "");
	wchar_t ch = L'中';
	wprintf(L"%c\n", ch);
	printf("%s\n", str);

	return 0;
}