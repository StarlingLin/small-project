#define _CRT_SECURE_NO_WARNINGS

#include "Contact.h"
#include "SeqList.h"

//��ʼ��ͨѶ¼
void InitContact(Contact* pc)
{
	//����
	assert(pc);
	SLInit(pc);
}
//����ͨѶ¼
void DestroyContact(Contact* pc)
{
	//����
	assert(pc);
	SLDestory(pc);
}

//��ɾ�Ĳ鿴��
//��
void AddContact(Contact* pc)
{
	//����
	assert(pc);
	//������ϵ�˽ṹ�����
	Info info;
	printf("���������ϵ��...\n");
	//��ʼ��
	printf("��������ϵ������:>");
	scanf("%s", info.name);
	printf("��������ϵ���Ա�:>");
	scanf("%s", info.gender);
	printf("��������ϵ������:>");
	scanf("%d", &info.age);
	printf("��������ϵ�˵绰:>");
	scanf("%s", info.tele);
	printf("��������ϵ�˵�ַ:>");
	scanf("%s", info.addr);
	printf("��������ϵ������:>");
	scanf("%s", info.mail);

	//���浽ͨѶ¼��
	SLPushBack(pc, info);
	printf("�����ϵ�˳ɹ���\n");
	system("pause");
	system("cls");
}
//ɾ
void DelContact(Contact* pc)
{
	//����
	assert(pc);
	//ɾ����ϵ��
	printf("������Ҫɾ������ϵ������:>");
	char name[NAME_MAX];
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ������ϵ�˲����ڣ�\n");
	}
	else
	{
		SLRemove(pc, pos);
		printf("ɾ����ϵ�˳ɹ���\n");
	}
	system("pause");
	system("cls");
}
//��
void ModifyContact(Contact* pc)
{
	//����
	assert(pc);
	//�޸���ϵ��
	printf("������Ҫ�޸ĵ���ϵ������:>");
	char name[NAME_MAX];
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ���ϵ�˲����ڣ�\n");
	}
	else
	{
		Info temp;
		system("cls");
		printf("��������ĺ���ϵ������:>");
		scanf("%s", temp.name);
		printf("��������ĺ���ϵ���Ա�:>");
		scanf("%s", temp.gender);
		printf("��������ĺ���ϵ������:>");
		scanf("%d", &temp.age);
		printf("��������ĺ���ϵ�˵绰:>");
		scanf("%s", temp.tele);
		printf("��������ĺ���ϵ�˵�ַ:>");
		scanf("%s", temp.addr);
		printf("��������ĺ���ϵ������:>");
		scanf("%s", temp.mail);
		SLModifyByPos(pc, pos, temp);
		printf("�޸���ϵ�˳ɹ���\n");
	}
	system("pause");
	system("cls");
}
//��

//��
void ShowContact(Contact* pc)
{
	//����
	assert(pc);
	printf("���ڴ�ӡ��ϵ��...\n");
	Sleep(1000);
	system("cls");
	printf("*******************************\n");
	printf("**********��ϵ����Ϣ***********\n");
	printf("*******************************\n");
	for (int i = 0; i < pc->size; ++i)
	{
		printf("������%s\n", pc->arr[i].name);
		printf("�Ա�%s\n", pc->arr[i].gender);
		printf("���䣺%d\n", pc->arr[i].age);
		printf("�绰��%s\n", pc->arr[i].tele);
		printf("��ַ��%s\n", pc->arr[i].addr);
		printf("���䣺%s\n", pc->arr[i].mail);
		printf("*******************************\n");
	}
	printf("*******************************\n");
	printf("��ӡ��ɡ�\n");
	system("pause");
	system("cls");
}
//��


//ͨ������������ϵ��
int FindByName(Contact* pc, char* name)
{
	//����
	assert(pc);
	//����ͨѶ¼
	for (int i = 0; i < pc->size; ++i)
	{
		if (strcmp(pc->arr[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}