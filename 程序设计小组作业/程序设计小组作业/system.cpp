#define _CRT_SECURE_NO_WARNINGS

#include "List.h"
#include "system.h"

//添加学生
Student* AddStudent(Node* pList)
{
	assert(pList != NULL);
	Student* p = (Student*)malloc(sizeof(Student));
	if (p == NULL)
	{
		printf("内存分配失败！\n");
		exit(EXIT_FAILURE);
	}
	*p = { 0 };
	PushBack(pList, p);
	return p;
}
//修改学生信息
Student* ModifyStudent(Student* stu, char* name, char* gender, Thesis* theses, Project* projects, Award* awards)
{
	assert(stu != NULL);
	strcpy(stu->name, name);
	strcpy(stu->gender, gender);
	if (theses != NULL)
	{
		for (int i = 0; i < THESIS_MAX; i++)
		{
			stu->thesis[i] = theses[i];
		}
	}
	if (projects != NULL)
	{
		for (int i = 0; i < PROJECT_MAX; i++)
		{
			stu->project[i] = projects[i];
		}
	}
	if (awards != NULL)
	{
		for (int i = 0; i < AWARD_MAX; i++)
		{
			stu->award[i] = awards[i];
		}
	}
	return stu;
}
//添加
void AddThesis(Student* stu, Thesis thesis)
{
	assert(stu != NULL);
	for (int i = 0; i < THESIS_MAX; i++)
	{
		if (stu->thesis[i].title[0] == '\0')
		{
			stu->thesis[i] = thesis;
			break;
		}
	}
}
void AddProject(Student* stu, Project project)
{
	assert(stu != NULL);
	for (int i = 0; i < PROJECT_MAX; i++)
	{
		if (stu->project[i].title[0] == '\0')
		{
			stu->project[i] = project;
			break;
		}
	}
}
void AddAward(Student* stu, Award award)
{
	assert(stu != NULL);
	for (int i = 0; i < AWARD_MAX; i++)
	{
		if (stu->award[i].title[0] == '\0')
		{
			stu->award[i] = award;
			break;
		}
	}
}