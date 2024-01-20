#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	CLEAR
};

void ContactMenu()
{
	printf("*******************************\n");
	printf("**********通讯录操作***********\n");
	printf("*******************************\n");
	printf("****  1. 添加     2. 删除  ****\n");
	printf("****  3. 搜索     4. 修改  ****\n");
	printf("****  5. 显示     6. 清空  ****\n");
	printf("****  0. 保存并退出        ****\n");
	printf("*******************************\n");
}

int main()
{
	int op = 0;	//用于记录用户的操作
	Contact con;	//定义通讯录
	InitContact(&con);	//初始化通讯录
	do {
		ContactMenu();
		printf("请选择操作:>");
		scanf("%d", &op);
		system("cls");
		switch (op)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			//DelContact();
			break;
		case SEARCH:
			//SearchContact();
			break;
		case MODIFY:
			//ModifyContact();
			break;
		case SHOW:
			//ShowContact();
			break;
		case CLEAR:
			//ClearContact();
			break;
		case EXIT:
			printf("退出通讯录。\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (op);
	DestroyContact(&con);	//销毁通讯录
	return EXIT_SUCCESS;
}

//int main()	//测试通讯录
//{
//	Contact con;
//	InitContact(&con);
//	AddContact(&con);
//	AddContact(&con);
//
//
//
//
//
//	DestroyContact(&con);
//	return EXIT_SUCCESS;
//}