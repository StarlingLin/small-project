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

//保存/加载数据
bool SaveData(Node* pList)
{
	//断言
	assert(pList != NULL);
	
	//txt文件保存
	FILE* fp = fopen("data.txt", "w");
	if (fp == NULL)
	{
		perror("文件打开失败！");
		return false;
	}
	Node* p = pList->next;
	while (p != NULL)
	{
		fprintf(fp, "姓名：%s\n性别：%s\n", p->data->name, p->data->gender);
		fprintf(fp, "论文数：%d\n项目数：%d\n获奖数：%d\n", 
			p->data->thesisNum,
			p->data->projectNum,
			p->data->awardNum
		);
		fprintf(fp, "------------------------\n");
		for (int i = 0; i < p->data->thesisNum; ++i)
		{
			fprintf(fp, "论文%d：《%s》\n", i + 1, p->data->thesis[i].title);
			fprintf(fp, "作者（首行通讯作者）：\n");
			for (int j = 0; j < MEMBER_MAX; ++j)
			{
				fprintf(fp, "%s\n", p->data->thesis[i].author[j]);
			}
			fprintf(fp, "期刊：%s\n页码/卷期/论文编号：%s\n发表日期：%d年%d月%d日\n论文级别：%c\n论文加分：%.2f\n",
				p->data->thesis[i].periodical, 
				p->data->thesis[i].pagination,
				p->data->thesis[i].publishDate.year, 
				p->data->thesis[i].publishDate.month, 
				p->data->thesis[i].publishDate.day,
				p->data->thesis[i].grade,
				p->data->thesis[i].score
			);
			fprintf(fp, "------------------------\n");
		}
		for (int i = 0; i < p->data->projectNum; ++i)
		{
			fprintf(fp, "项目%d：%s\n", i+1, p->data->project[i].title);
			fprintf(fp, "成员（首行指导老师）：\n");
			for (int j = 0; j < MEMBER_MAX; ++j)
			{
				fprintf(fp, "%s\n", p->data->project[i].member[j]);
			}
			fprintf(fp, "项目编号：%d\n开始日期：%d年%d月%d日\n结束日期：%d年%d月%d日\n",
				p->data->project[i].id,
				p->data->project[i].startDate.year,
				p->data->project[i].startDate.month,
				p->data->project[i].startDate.day,
				p->data->project[i].endDate.year,
				p->data->project[i].endDate.month,
				p->data->project[i].endDate.day
			);
			fprintf(fp, "------------------------\n");
		}
		for (int i = 0; i < p->data->awardNum; ++i)
		{
			fprintf(fp, "奖项%d：%s\n颁奖机构：%s\n", i + 1, 
				p->data->award[i].title, 
				p->data->award->organization
			);
			fprintf(fp, "获奖人（不唯一）：\n");
			for (int j = 0; j < MEMBER_MAX; ++j)
			{
				fprintf(fp, "%s\n", p->data->award[i].member[j]);
			}
			fprintf(fp, "获奖级别：%s\n获奖日期：%d年%d月%d日\n",
				p->data->award[i].level,
				p->data->award[i].awardDate.year,
				p->data->award[i].awardDate.month,
				p->data->award[i].awardDate.day
			);
			fprintf(fp, "------------------------\n");
		}
		fprintf(fp, "========================\n");
		p = p->next;
	}
	fclose(fp);

	//二进制文件保存
	fp = fopen("data.bin", "wb");
	if (fp == NULL)
	{
		perror("文件打开失败！");
		return false;
	}
	p = pList->next;
	while (p != NULL)
	{
		fwrite(p->data, sizeof(ListDataType), 1, fp);
		p = p->next;
	}
	fclose(fp);

	return true;
}
bool LoadData(Node* pList)
{
	//断言
	assert(pList != NULL);

	//txt文件加载
	FILE* fp = fopen("data.txt", "r");
	if (fp == NULL)
	{
		perror("文件打开失败！");
		return false;
	}
	ListDataType* data = (ListDataType*)malloc(sizeof(ListDataType));
	if (data == NULL)
	{
		printf("内存分配失败！\n");
		return false;
	}
	while (fscanf(fp, "姓名：%s\n性别：%s\n", data->name, data->gender) != EOF)
	{
		fscanf(fp, "论文数：%d\n项目数：%d\n获奖数：%d\n",
			&data->thesisNum,
			&data->projectNum,
			&data->awardNum
		);
		fscanf(fp, "------------------------\n");
		for (int i = 0; i < data->thesisNum; ++i)
		{
			fscanf(fp, "论文%*d：《%[^》]", data->thesis[i].title);
			fscanf(fp, "》\n作者（首行通讯作者）：\n");
			for (int j = 0; j < MEMBER_MAX; ++j)
			{
				fgets(data->thesis[i].author[j], NAME_MAX, fp);
				//去掉换行符
				data->thesis[i].author[j][strlen(data->thesis[i].author[j]) - 1] = '\0';
			}
			fscanf(fp, "期刊：%s\n页码/卷期/论文编号：%s\n发表日期：%d年%d月%d日\n论文级别：%c\n论文加分：%f\n",
				data->thesis[i].periodical,
				data->thesis[i].pagination,
				&data->thesis[i].publishDate.year,
				&data->thesis[i].publishDate.month,
				&data->thesis[i].publishDate.day,
				&data->thesis[i].grade,
				&data->thesis[i].score
			);
			fscanf(fp, "------------------------\n");
		}
		for (int i = 0; i < data->projectNum; ++i)
		{
			fscanf(fp, "项目%*d：%s\n", data->project[i].title);
			fscanf(fp, "成员（首行指导老师）：\n");
			for (int j = 0; j < MEMBER_MAX; ++j)
			{
				fgets(data->project[i].member[j], NAME_MAX, fp);
				//去掉换行符
				data->project[i].member[j][strlen(data->project[i].member[j]) - 1] = '\0';
			}
			fscanf(fp, "项目编号：%d\n开始日期：%d年%d月%d日\n结束日期：%d年%d月%d日\n",
				&data->project[i].id,
				&data->project[i].startDate.year,
				&data->project[i].startDate.month,
				&data->project[i].startDate.day,
				&data->project[i].endDate.year,
				&data->project[i].endDate.month,
				&data->project[i].endDate.day
			);
			fscanf(fp, "------------------------\n");
		}
		for (int i = 0; i < data->awardNum; ++i)
		{
			fscanf(fp, "奖项%*d：%s\n颁奖机构：%s\n",
				data->award[i].title,
				data->award->organization
			);
			fscanf(fp, "获奖人（不唯一）：\n");
			for (int j = 0; j < MEMBER_MAX; ++j)
			{
				fgets(data->award[i].member[j], NAME_MAX, fp);
				//去掉换行符
				data->award[i].member[j][strlen(data->award[i].member[j]) - 1] = '\0';
			}
			fscanf(fp, "获奖级别：%s\n获奖日期：%d年%d月%d日\n",
				data->award[i].level,
				&data->award[i].awardDate.year,
				&data->award[i].awardDate.month,
				&data->award[i].awardDate.day
			);
			fscanf(fp, "------------------------\n");
		}
		fscanf(fp, "========================\n");
		//复制data并插入链表
		ListDataType* temp = (ListDataType*)malloc(sizeof(ListDataType));
		if (temp == NULL)
		{
			printf("内存分配失败！\n");
			exit(EXIT_FAILURE);
		}
		memcpy(temp, data, sizeof(ListDataType));
		PushBack(pList, temp);
	}
	fclose(fp);
	return true;
}
bool LoadDataBinary(Node* pList)
{
	//二进制文件加载
	FILE* fp = fopen("data.bin", "rb");
	ListDataType* data = (ListDataType*)malloc(sizeof(ListDataType));
	if (data == NULL)
	{
		printf("内存分配失败！\n");
		exit(EXIT_FAILURE);
	}
	if (fp == NULL)
	{
		perror("文件打开失败！");
		return false;
	}
	while (fread(data, sizeof(ListDataType), 1, fp) != 0)
	{
		PushBack(pList, data);
	}
	fclose(fp);
}