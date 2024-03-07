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
//按名称查询学生（返回位置）
int FindStudent(Node* pList, char* name)
{
	assert(pList != NULL);
	Node* p = pList->next;
	int pos = 0;
	while (p != NULL)
	{
		pos++;
		if (strcmp(((Student*)p->data)->name, name) == 0)
		{
			return pos;
		}
		p = p->next;
	}
	return -1;
}
//删除学生
void DeleteStudent(Node* pList, int pos)
{
	assert(pList != NULL);
	Erase(pList, pos);
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
//添加论文、项目、获奖
Student* AddThesis(Student* stu, Thesis thesis)
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
	stu->thesisNum++;
	return stu;
}
Student* AddProject(Student* stu, Project project)
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
	stu->projectNum++;
	return stu;
}
Student* AddAward(Student* stu, Award award)
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
	stu->awardNum++;
	return stu;
}
//删除论文、项目、获奖
Student* DeleteThesis(Student* stu, int pos)
{
	assert(stu != NULL);
	for (int i = pos; i < THESIS_MAX - 1; i++)
	{
		stu->thesis[i] = stu->thesis[i + 1];
	}
	stu->thesis[THESIS_MAX - 1] = { 0 };
	stu->thesisNum--;
	return stu;
}
Student* DeleteProject(Student* stu, int pos)
{
	assert(stu != NULL);
	for (int i = pos; i < PROJECT_MAX - 1; i++)
	{
		stu->project[i] = stu->project[i + 1];
	}
	stu->project[PROJECT_MAX - 1] = { 0 };
	stu->projectNum--;
	return stu;
}
Student* DeleteAward(Student* stu, int pos)
{
	assert(stu != NULL);
	for (int i = pos; i < AWARD_MAX - 1; i++)
	{
		stu->award[i] = stu->award[i + 1];
	}
	stu->award[AWARD_MAX - 1] = { 0 };
	stu->awardNum--;
	return stu;	
}
//按名称查询论文、项目、获奖（返回位置）
int FindThesis(Student* stu, char* title)
{
	assert(stu != NULL);
	for (int i = 0; i < THESIS_MAX; i++)
	{
		if (strcmp(stu->thesis[i].title, title) == 0)
		{
			return i;
		}
	}
	return -1;
}
int FindProject(Student* stu, char* title)
{
	assert(stu != NULL);
	for (int i = 0; i < PROJECT_MAX; i++)
	{
		if (strcmp(stu->project[i].title, title) == 0)
		{
			return i;
		}
	}
	return -1;
}
int FindAward(Student* stu, char* title)
{
	assert(stu != NULL);
	for (int i = 0; i < AWARD_MAX; i++)
	{
		if (strcmp(stu->award[i].title, title) == 0)
		{
			return i;
		}
	}
	return -1;
}
//修改论文、项目、获奖
Student* ModifyThesis(Student* stu, int pos, Thesis thesis)
{
	assert(stu != NULL);
	stu->thesis[pos] = thesis;
	return stu;
}
Student* ModifyProject(Student* stu, int pos, Project project)
{
	assert(stu != NULL);
	stu->project[pos] = project;
	return stu;
}
Student* ModifyAward(Student* stu, int pos, Award award)
{
	assert(stu != NULL);
	stu->award[pos] = award;
	return stu;
}
//按位置返回论文、项目、获奖
Thesis* GetThesis(Student* stu, int pos)
{
	assert(stu != NULL);
	return &stu->thesis[pos];
}
Project* GetProject(Student* stu, int pos)
{
	assert(stu != NULL);
	return &stu->project[pos];

}
Award* GetAward(Student* stu, int pos)
{
	assert(stu != NULL);
	return &stu->award[pos];
}

//论文结构体
//创建论文
Thesis CreateThesis(char* title, char author[MEMBER_MAX][NAME_MAX], char* periodical, char* pagination, Date publishDate, char grade, float score)
{
	Thesis thesis = { 0 };
	strcpy(thesis.title, title);
	for (int i = 0; i < MEMBER_MAX; i++)
	{
		strcpy(thesis.author[i], author[i]);
	}
	strcpy(thesis.periodical, periodical);
	strcpy(thesis.pagination, pagination);
	thesis.publishDate = publishDate;
	thesis.grade = grade;
	thesis.score = score;
	return thesis;
}
//修改论文具体信息（置NULL不改）
Thesis ModifyThesisDetail(Thesis thesis, char* title, char author[MEMBER_MAX][NAME_MAX], char* periodical, char* pagination, Date publishDate, char grade, float score)
{
	if (title != NULL)
	{
		strcpy(thesis.title, title);
	}
	if (author != NULL)
	{
		for (int i = 0; i < MEMBER_MAX; i++)
		{
			strcpy(thesis.author[i], author[i]);
		}
	}
	if (periodical != NULL)
	{
		strcpy(thesis.periodical, periodical);
	}
	if (pagination != NULL)
	{
		strcpy(thesis.pagination, pagination);
	}
	if (publishDate.year != 0)
	{
		thesis.publishDate = publishDate;
	}
	if (grade != 0)
	{
		thesis.grade = grade;
	}
	if (score != 0)
	{
		thesis.score = score;
	}
	return thesis;
}
//项目结构体
//创建项目
Project CreateProject(char* title, char member[MEMBER_MAX][NAME_MAX], int id, Date startDate, Date endDate)
{
	Project project = { 0 };
	strcpy(project.title, title);
	for (int i = 0; i < MEMBER_MAX; i++)
	{
		strcpy(project.member[i], member[i]);
	}
	project.id = id;
	project.startDate = startDate;
	project.endDate = endDate;
	return project;
}
//修改项目具体信息（置NULL不改）
Project ModifyProjectDetail(Project project, char* title, char member[MEMBER_MAX][NAME_MAX], int id, Date startDate, Date endDate)
{
	if (title != NULL)
	{
		strcpy(project.title, title);
	}
	if (member != NULL)
	{
		for (int i = 0; i < MEMBER_MAX; i++)
		{
			strcpy(project.member[i], member[i]);
		}
	}
	if (id != 0)
	{
		project.id = id;
	}
	if (startDate.year != 0)
	{
		project.startDate = startDate;
	}
	if (endDate.year != 0)
	{
		project.endDate = endDate;
	}
	return project;
}
//获奖结构体
//创建获奖
Award CreateAward(char* title, char organization[ORGANIZATION_MAX], char member[MEMBER_MAX][NAME_MAX], char level[LEVEL_MAX], Date awardDate)
{
	Award award = { 0 };
	strcpy(award.title, title);
	strcpy(award.organization, organization);
	for (int i = 0; i < MEMBER_MAX; i++)
	{
		strcpy(award.member[i], member[i]);
	}
	strcpy(award.level, level);
	award.awardDate = awardDate;
	return award;
}
//修改获奖具体信息（置NULL不改）
Award ModifyAwardDetail(Award award, char* title, char organization[ORGANIZATION_MAX], char member[MEMBER_MAX][NAME_MAX], char level[LEVEL_MAX], Date awardDate)
{
	if (title != NULL)
	{
		strcpy(award.title, title);
	}
	if (organization != NULL)
	{
		strcpy(award.organization, organization);
	}
	if (member != NULL)
	{
		for (int i = 0; i < MEMBER_MAX; i++)
		{
			strcpy(award.member[i], member[i]);
		}
	}
	if (level != NULL)
	{
		strcpy(award.level, level);
	}
	if (awardDate.year != 0)
	{
		award.awardDate = awardDate;
	}
	return award;
}
//日期结构体
//创建日期
Date CreateDate(int year, int month, int day)
{
	Date date = { 0 };
	date.year = year;
	date.month = month;
	date.day = day;
	return date;
}
//修改日期具体信息（置0不改）
Date ModifyDateDetail(Date date, int year, int month, int day)
{
	if (year != 0)
	{
		date.year = year;
	}
	if (month != 0)
	{
		date.month = month;
	}
	if (day != 0)
	{
		date.day = day;
	}
	return date;
}

