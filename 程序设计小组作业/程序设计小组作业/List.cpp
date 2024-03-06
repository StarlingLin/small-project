#define _CRT_SECURE_NO_WARNINGS
//实现链表头文件的接口
#include "List.h"

//初始化链表
void InitList(Node* pList)
{
	//断言
	assert(pList != NULL);
	pList->data = NULL;
	pList->next = NULL;
}
//销毁链表
void DestroyList(Node* pList)
{
	//断言
	assert(pList != NULL);
	Node* p = pList->next;
	Node* q = NULL;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	pList->next = NULL;
}

//获取链表长度
int GetLength(Node* pList)
{
	//断言
	assert(pList != NULL);
	int n = 0;
	Node* p = pList->next;
	while (p != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}

//头部/尾部插入
void PushFront(Node* pList, ListDataType* data)
{
	//断言
	assert(pList != NULL);
	Node* pNew = (Node*)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		printf("内存分配失败！\n");
		exit(EXIT_FAILURE);
	}
	pNew->data = data;
	pNew->next = pList->next;
	pList->next = pNew;
}
void PushBack(Node* pList, ListDataType* data)
{
	//断言
	assert(pList != NULL);
	Node* p = pList;
	while (p->next != NULL)
	{
		p = p->next;
	}
	Node* pNew = (Node*)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		printf("内存分配失败！\n");
		exit(EXIT_FAILURE);
	}
	pNew->data = data;
	pNew->next = NULL;
	p->next = pNew;
}
//头部/尾部删除
void PopFront(Node* pList)
{
	//断言
	assert(pList != NULL);
	Node* p = pList->next;
	if (p != NULL)
	{
		pList->next = p->next;
		free(p);
	}
}
void PopBack(Node* pList)
{
	//断言
	assert(pList != NULL);
	Node* p = pList;
	while (p->next->next != NULL)
	{
		p = p->next;
	}
	Node* q = p->next;
	p->next = NULL;
	free(q);
}
//任意位置插入/删除
void Insert(Node* pList, int pos, ListDataType* data)
{
	//断言
	assert(pList != NULL);
	Node* p = pList;
	int i = 0;
	while (p != NULL && i < pos)
	{
		p = p->next;
		i++;
	}
	if (p != NULL)
	{
		Node* pNew = (Node*)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			printf("内存分配失败！\n");
			exit(EXIT_FAILURE);
		}
		pNew->data = data;
		pNew->next = p->next;
		p->next = pNew;
	}
}
void Erase(Node* pList, int pos)
{
	//断言
	assert(pList != NULL);
	Node* p = pList;
	int i = 0;
	while (p != NULL && i < pos)
	{
		p = p->next;
		i++;
	}
	if (p != NULL && p->next != NULL)
	{
		Node* q = p->next;
		p->next = q->next;
		free(q);
	}
}

//保存/加载数据到txt文件
bool SaveData(Node* pList)
{
	//断言
	assert(pList != NULL);
	FILE* fp = fopen("data.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败！\n");
		return false;
	}
	Node* p = pList->next;
	while (p != NULL)
	{
		fprintf(fp, "%s\n%s\n", p->data->name, p->data->gender);
		for (int i = 0; i < THESIS_MAX; ++i)
		{
			fprintf(fp, "%s\n",	p->data->thesis[i].title);
			for (int j = 0; j < MEMBER_MAX; ++j)
			{
				fprintf(fp, "%s\n", p->data->thesis[i].author[j]);
			}
			fprintf(fp, "%s\n%s\n%d %d %d\n%c\n%.2f\n",
				p->data->thesis[i].periodical, 
				p->data->thesis[i].pagination,
				p->data->thesis[i].publishDate.year, 
				p->data->thesis[i].publishDate.month, 
				p->data->thesis[i].publishDate.day,
				p->data->thesis[i].grade,
				p->data->thesis[i].score
			);
		}
		for (int i = 0; i < PROJECT_MAX; ++i)
		{
			fprintf(fp, "%s\n", p->data->project[i].title);
			for (int j = 0; j < MEMBER_MAX; ++j)
			{
				fprintf(fp, "%s\n", p->data->project[i].member[j]);
			}
			fprintf(fp, "%d\n%d %d %d\n%d %d %d\n",
				p->data->project[i].id,
				p->data->project[i].startDate.year,
				p->data->project[i].startDate.month,
				p->data->project[i].startDate.day,
				p->data->project[i].endDate.year,
				p->data->project[i].endDate.month,
				p->data->project[i].endDate.day
			);
		}
		for (int i = 0; i < AWARD_MAX; ++i)
		{
			fprintf(fp, "%s\n%s\n", p->data->award[i].title, p->data->award->organization);
			for (int j = 0; j < MEMBER_MAX; ++j)
			{
				fprintf(fp, "%s\n", p->data->award[i].member[j]);
			}
			fprintf(fp, "%s\n%d %d %d\n",
				p->data->award[i].level,
				p->data->award[i].awardDate.year,
				p->data->award[i].awardDate.month,
				p->data->award[i].awardDate.day
			);
		}
		p = p->next;
	}
	fclose(fp);
	return true;
}
//bool LoadData(Node* pList)
//{
//	//断言
//	assert(pList != NULL);
//	FILE* fp = fopen("data.txt", "r");
//	if (fp == NULL)
//	{
//		printf("文件打开失败！\n");
//		return false;
//	}
//	ListDataType data;
//	while (fscanf(fp, "%d", &data) != EOF)
//	{
//		PushBack(pList, data);
//	}
//	fclose(fp);
//	return true;
//}