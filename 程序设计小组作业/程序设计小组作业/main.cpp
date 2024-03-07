#define _CRT_SECURE_NO_WARNINGS

#include "UI.h"
#include "List.h"

#define CH (char*)

//程序状态定义在visual.h中

int main()
{
	enum State state = MENU;	//程序状态

	//数据结构的载入
	LoadList(head);

	//test
	char au1[MEMBER_MAX][NAME_MAX] = { "小明","小红","小黄","小绿","张三","李四","王五" };
	Thesis the1 = { "这是一个论文" };
	memcpy(the1.author, au1, sizeof(au1));
	strcpy(the1.periodical, "这是一个期刊");
	strcpy(the1.pagination, "这是页码");
	the1.publishDate = { 2019, 1, 1 };
	the1.grade = 'T';
	the1.score = 0.2f;
	Student* s1 = ModifyStudent(AddStudent(head), CH"张三", CH"男", NULL, NULL, NULL);
	AddThesis(s1, the1);

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
		}
	}

	//数据结构的保存
	SaveData(head);
	MessageBox(window_main.GetHandle(), L"保存成功", L"提示", MB_OK);

	return EXIT_SUCCESS;
}
