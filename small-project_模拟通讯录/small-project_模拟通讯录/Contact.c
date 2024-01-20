#define _CRT_SECURE_NO_WARNINGS

#include "Contact.h"
#include "SeqList.h"

//初始化通讯录
void InitContact(Contact* pc)
{
	//断言
	assert(pc);
	SLInit(pc);
}
//销毁通讯录
void DestroyContact(Contact* pc)
{
	//断言
	assert(pc);
	SLDestory(pc);
}

//增删改查看清
//增
void AddContact(Contact* pc)
{
	//断言
	assert(pc);
	//创建联系人结构体变量
	Info info;
	printf("正在添加联系人...\n");
	//初始化
	printf("请输入联系人姓名:>");
	scanf("%s", info.name);
	printf("请输入联系人性别:>");
	scanf("%s", info.gender);
	printf("请输入联系人年龄:>");
	scanf("%d", &info.age);
	printf("请输入联系人电话:>");
	scanf("%s", info.tele);
	printf("请输入联系人地址:>");
	scanf("%s", info.addr);
	printf("请输入联系人邮箱:>");
	scanf("%s", info.mail);

	//保存到通讯录中
	SLPushBack(pc, info);
	printf("添加联系人成功！\n");
	system("pause");
	system("cls");
}
//删
void DelContact(Contact* pc)
{
	//断言
	assert(pc);
	//删除联系人
	printf("请输入要删除的联系人姓名:>");
	char name[NAME_MAX];
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的联系人不存在！\n");
	}
	else
	{
		SLRemove(pc, pos);
		printf("删除联系人成功！\n");
	}
	system("pause");
	system("cls");
}
//改
void ModifyContact(Contact* pc)
{
	//断言
	assert(pc);
	//修改联系人
	printf("请输入要修改的联系人姓名:>");
	char name[NAME_MAX];
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的联系人不存在！\n");
	}
	else
	{
		Info temp;
		system("cls");
		printf("请输入更改后联系人姓名:>");
		scanf("%s", temp.name);
		printf("请输入更改后联系人性别:>");
		scanf("%s", temp.gender);
		printf("请输入更改后联系人年龄:>");
		scanf("%d", &temp.age);
		printf("请输入更改后联系人电话:>");
		scanf("%s", temp.tele);
		printf("请输入更改后联系人地址:>");
		scanf("%s", temp.addr);
		printf("请输入更改后联系人邮箱:>");
		scanf("%s", temp.mail);
		SLModifyByPos(pc, pos, temp);
		printf("修改联系人成功！\n");
	}
	system("pause");
	system("cls");
}
//查

//看
void ShowContact(Contact* pc)
{
	//断言
	assert(pc);
	printf("正在打印联系人...\n");
	Sleep(1000);
	system("cls");
	printf("*******************************\n");
	printf("**********联系人信息***********\n");
	printf("*******************************\n");
	for (int i = 0; i < pc->size; ++i)
	{
		printf("姓名：%s\n", pc->arr[i].name);
		printf("性别：%s\n", pc->arr[i].gender);
		printf("年龄：%d\n", pc->arr[i].age);
		printf("电话：%s\n", pc->arr[i].tele);
		printf("地址：%s\n", pc->arr[i].addr);
		printf("邮箱：%s\n", pc->arr[i].mail);
		printf("*******************************\n");
	}
	printf("*******************************\n");
	printf("打印完成。\n");
	system("pause");
	system("cls");
}
//清


//通过姓名查找联系人
int FindByName(Contact* pc, char* name)
{
	//断言
	assert(pc);
	//遍历通讯录
	for (int i = 0; i < pc->size; ++i)
	{
		if (strcmp(pc->arr[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}