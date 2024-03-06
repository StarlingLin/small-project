#define _CRT_SECURE_NO_WARNINGS

#include "visual.h"
#include "List.h"

#define CH (char*)

int main()
{
	hiex::Window window_main = _InitSysWindow(400, 500, L"素质类项目成绩管理系统");
	_DrawSysMenu(window_main, 400, 500);

	system("pause");
	return EXIT_SUCCESS;
}
