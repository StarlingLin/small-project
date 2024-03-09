#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include "UI.h"

#define CH (char*)

//程序状态定义在visual.h中

int main()
{
	setlocale(LC_ALL, "chs");

	enum State state = MENU;	//程序状态

	//登录界面
	_LoginUI(200, 150, L"登录");	//登录界面

	//数据结构的载入
	LoadList(head);

	//test
	//char au1[MEMBER_MAX][NAME_MAX] = { "小明","小红","小黄","小绿","张三","李四","王五" };
	//Student* s1 = ModifyStudent(AddStudent(head), CH"张三", CH"男", NULL, NULL, NULL);
	//AddThesis(s1, CreateThesis(CH"这是一个论文", au1, CH"这是一个期刊", CH"这是页码", { 2019, 1, 1 }, 'T', 0.2f));
	//AddProject(s1, CreateProject(CH"这是一个项目", au1, 114514, { 2018, 1, 1 }, { 2019, 1, 1 }));
	//Student* s2 = ModifyStudent(AddStudent(head), CH"李四", CH"男", NULL, NULL, NULL);
	//AddThesis(s2, CreateThesis(CH"这是一个论文", au1, CH"这是一个期刊", CH"这是页码", { 2019, 1, 1 }, 'T', 0.2f));
	//AddProject(s2, CreateProject(CH"这是一个项目", au1, 114514, { 2018, 1, 1 }, { 2019, 1, 1 }));

	//UI
	hiex::Window window_main = _InitSysWindow(300, 300, L"素质类项目成绩管理系统");

	while (state)
	{
		if (window_main.IsAlive() == false)
		{
			exit(EXIT_FAILURE);
		}
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
			_AddStudentUI(head);
			state = MENU;
			break;
		}
	}

	//数据结构的保存
	SaveData(head);
	MessageBox(window_main.GetHandle(), L"保存成功", L"提示", MB_OK);

	return EXIT_SUCCESS;
}

////test sth
//
//#define BUFFER_SIZE 50
//
//int main()
//{
//	size_t ret;
//	char* MB = (char*)malloc(BUFFER_SIZE);
//	wchar_t* WC = (wchar_t*)L"http://www.w3cschool.cc";
//
//	/* 转换宽字符字符串 */
//	ret = wcstombs(MB, WC, BUFFER_SIZE);
//
//	printf("要转换的字符数 = %u\n", ret);
//	printf("多字节字符 = %s\n\n", MB);
//
//	return(0);
//}
