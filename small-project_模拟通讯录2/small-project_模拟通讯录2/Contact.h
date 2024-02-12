#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NAME_MAX 20
#define GENDER_MAX 10
#define TELE_MAX 15
#define ADDR_MAX 100
#define MAIL_MAX 50

//定义通讯录中的联系人结构体
typedef struct PersonInfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
	char mail[MAIL_MAX];
} Info;

//顺序表前置声明
struct SeqList;
typedef struct SeqList Contact;

//初始化通讯录
void InitContact(Contact* pc);
//销毁通讯录
void DestroyContact(Contact* pc);
//加载通讯录
void LoadContact(Contact* pc);
//保存通讯录
void SaveContact(Contact* pc);

//增删改查看清
//增
void AddContact(Contact* pc);
//删
void DelContact(Contact* pc);
//改
void ModifyContact(Contact* pc);
//查
void SearchContact(Contact* pc);
//看
void ShowContact(Contact* pc);
//清
void ClearContact(Contact* pc);