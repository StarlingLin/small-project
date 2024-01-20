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
	printf("请输入联系人年龄:>");
	scanf("%d", &info.age);
	printf("请输入联系人性别:>");
	scanf("%s", info.gender);
	printf("请输入联系人电话:>");
	scanf("%s", info.tele);
	printf("请输入联系人地址:>");
	scanf("%s", info.addr);
	printf("请输入联系人邮箱:>");
	scanf("%s", info.mail);

	//保存到通讯录中
	SLPushBack(pc, info);
	printf("添加联系人成功！\n");
	Sleep(1000);
	system("cls");
}