#define _CRT_SECURE_NO_WARNINGS

#include "visual.h"
#include "List.h"

#define CH (char*)

//程序状态定义在visual.h中

int main()
{
	enum State state = MENU;	//程序状态

	hiex::Window window_main = _InitSysWindow(300, 300, L"素质类项目成绩管理系统");

	while (state)
	{
		switch (state)
		{
		case MENU:
			_DrawSysMenu(window_main, 300, 300);
			state = _GetSysMenu(window_main);
			break;
		case VIEW:
			break;
		case SEARCH:
			break;
		case ADD:
			break;
		case EXIT:
			break;
		default:
			break;
		}
	}

	return EXIT_SUCCESS;
}
