#define _CRT_SECURE_NO_WARNINGS

#include "visual.h"
#include "List.h"

#define CH (char*)

int main()
{
	hiex::Window window_main = _InitSysWindow(400, 500, L"��������Ŀ�ɼ�����ϵͳ");
	_DrawSysMenu(window_main, 400, 500);

	system("pause");
	return EXIT_SUCCESS;
}
