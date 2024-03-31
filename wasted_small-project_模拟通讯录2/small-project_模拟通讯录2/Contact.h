#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NAME_MAX 20
#define GENDER_MAX 10
#define TELE_MAX 15
#define ADDR_MAX 100
#define MAIL_MAX 50

//����ͨѶ¼�е���ϵ�˽ṹ��
typedef struct PersonInfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
	char mail[MAIL_MAX];
} Info;

//˳���ǰ������
struct SeqList;
typedef struct SeqList Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);
//����ͨѶ¼
void DestroyContact(Contact* pc);
//����ͨѶ¼
void LoadContact(Contact* pc);
//����ͨѶ¼
void SaveContact(Contact* pc);

//��ɾ�Ĳ鿴��
//��
void AddContact(Contact* pc);
//ɾ
void DelContact(Contact* pc);
//��
void ModifyContact(Contact* pc);
//��
void SearchContact(Contact* pc);
//��
void ShowContact(Contact* pc);
//��
void ClearContact(Contact* pc);