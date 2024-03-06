#define _CRT_SECURE_NO_WARNINGS

#include "visual.h"
#include "List.h"

#define CH (char*)

//程序状态定义在visual.h中

int main()
{
	enum State state = MENU;	//程序状态

	//数据结构的载入
	LoadList(head);

	//test
	ModifyStudent(AddStudent(head), CH"张三", CH"男", NULL, NULL, NULL);

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
	SaveData(head);
	MessageBox(window_main.GetHandle(), L"保存成功", L"提示", MB_OK);

	return EXIT_SUCCESS;
}
