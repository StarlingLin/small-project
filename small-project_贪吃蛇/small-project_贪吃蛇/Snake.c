#define _CRT_SECURE_NO_WARNINGS

#include "Snake.h"

int MSPT_VAL[10] = { 1,400,200,150,100,70,50,30,20,10 };

void GameStart(pSnake ps)
{
	//���ÿ���̨��Ϣ
	system("mode con cols=100 lines=27");
	system("title �����ˣ���̰����");
	system("cls");
	//���ع��
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOutput, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(hOutput, &CursorInfo);
	//��ӡ��ʼ����
	Welcome();
	//���Ƶ�ͼ
	PrintMap();
	//��ʼ����
	InitSnake(ps);
	//��ӡ�ڵ�
	PrintSnake(ps);
	//������Ϣ�ĳ�ʼ��
	ps->Direction = MOVE_RIGHT;
	ps->FoodWeight = 10.0f;
	ps->FoodEaten = 0;
	ps->MSPT = 1;
	ps->pFood = NULL;
	ps->Score = 0.0f;
	ps->Status = GAME_RUN;
	ps->HighScore = GetHighScore();
	//����ʳ��
	CreateFood(ps);
}

long double GetHighScore(void)
{
	//���ڴ洢��߷�
	long double HighScore = 0.0f;
	//��ע���"Software\\Value\\Snake"�����������ȡ���������������򴴽�����
	HKEY hKey;
	if (ERROR_SUCCESS == RegOpenKeyEx(HKEY_CURRENT_USER, L"Software\\Value\\Snake", 0, KEY_READ | KEY_WRITE, &hKey))
	{
		DWORD dwType = REG_BINARY;
		DWORD dwSize = sizeof(HighScore);
		RegQueryValueEx(hKey, L"HighScore", NULL, &dwType, (LPBYTE)&HighScore, &dwSize);
		RegCloseKey(hKey);
	}
	else
	{
		if (ERROR_SUCCESS == RegCreateKeyEx(HKEY_CURRENT_USER, L"Software\\Value\\Snake", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL))
		{
			RegSetValueEx(hKey, L"HighScore", 0, REG_BINARY, (const BYTE*)&HighScore, sizeof(HighScore));
			RegCloseKey(hKey);
		}
	}
	return HighScore;
}

void SetHighScore(long double score)
{
	HKEY hKey;
	if (ERROR_SUCCESS == RegOpenKeyEx(HKEY_CURRENT_USER, L"Software\\Value\\Snake", 0, KEY_READ | KEY_WRITE, &hKey))
	{
		RegSetValueEx(hKey, L"HighScore", 0, REG_BINARY, (const BYTE*)&score, sizeof(score));
		RegCloseKey(hKey);
	}
}

void GameRun(pSnake ps)
{
	do
	{
		//��ӡ��Ϣ
		PrintInfo(ps);
		//��ⰴ��
		if (KEY_PRESSED(VK_UP) && ps->Direction != MOVE_DOWN)
		{
			ps->Direction = MOVE_UP;
		}
		else if (KEY_PRESSED(VK_DOWN) && ps->Direction != MOVE_UP)
		{
			ps->Direction = MOVE_DOWN;
		}
		else if (KEY_PRESSED(VK_LEFT) && ps->Direction != MOVE_RIGHT)
		{
			ps->Direction = MOVE_LEFT;
		}
		else if (KEY_PRESSED(VK_RIGHT) && ps->Direction != MOVE_LEFT)
		{
			ps->Direction = MOVE_RIGHT;
		}
		else if (KEY_PRESSED(VK_ESCAPE))
		{
			ps->Status = GAME_EXIT;
			break;
		}
		else if (KEY_PRESSED(VK_SPACE))
		{
			PauseGame(ps);
		}
		if (KEY_PRESSED(0x31))
		{
			ps->MSPT = 1;
			ps->FoodWeight = 10;
		}
		if (KEY_PRESSED(0x32))
		{
			ps->MSPT = 2;
			ps->FoodWeight = 20;
		}
		if (KEY_PRESSED(0x33))
		{
			ps->MSPT = 3;
			ps->FoodWeight = 30;
		}
		if (KEY_PRESSED(0x34))
		{
			ps->MSPT = 4;
			ps->FoodWeight = 50;
		}
		if (KEY_PRESSED(0x35))
		{
			ps->MSPT = 5;
			ps->FoodWeight = 100;
		}
		if (KEY_PRESSED(0x36))
		{
			ps->MSPT = 6;
			ps->FoodWeight = 150;
		}
		if (KEY_PRESSED(0x37))
		{
			ps->MSPT = 7;
			ps->FoodWeight = 300;
		}
		if (KEY_PRESSED(0x38))
		{
			ps->MSPT = 8;
			ps->FoodWeight = 500;
		}
		if (KEY_PRESSED(0x39))
		{
			ps->MSPT = 9;
			ps->FoodWeight = 8000;
		}
		//��һ��
		SnakeMove(ps);
		//ͣ��
		Sleep(MSPT_VAL[ps->MSPT]);
	} while (!ps->Status);
}

void GameEnd(pSnake ps)
{
	switch (ps->Status)
	{
	case GAME_EXIT:
		SetPos(62, 14);
		printf("���ж�����Ϸ��");
		SetPos(62, 16);
		system("pause");
		break;
	case HIT_WALL:
		SetPos(62, 14);
		printf("�㴴��ǽ�ˡ�");
		SetPos(62, 16);
		system("pause");
		break;
	case HIT_SELF:
		SetPos(62, 14);
		printf("�㴴���Լ��ˡ�");
		SetPos(62, 16);
		system("pause");
		break;
	case FINISH_ALL:
		SetPos(62, 14);
		printf("ţ�ƣ��������˸��ӡ�");
		SetPos(62, 16);
		system("pause");
		break;
	}
	//�ͷ���Դ
	pSnakeNode pcur = ps->pSnake;
	pSnakeNode pdel = NULL;
	while (pcur)
	{
		pdel = pcur;
		pcur = pcur->next;
		free(pdel);
	}
	free(ps->pFood);
	ps->pSnake = NULL;
	ps->pFood = NULL;
	ps = NULL;
}

void SnakeMove(pSnake ps)
{
	pSnakeNode pNext = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (!pNext)
	{
		system("cls");
		SetPos(0, 0);
		perror("SnakeMove()->malloc()");
		exit(EXIT_FAILURE);
	}
	pNext->next = NULL;
	switch (ps->Direction)
	{
	case MOVE_UP:
		pNext->x = ps->pSnake->x;
		pNext->y = ps->pSnake->y - 1;
		break;
	case MOVE_DOWN:
		pNext->x = ps->pSnake->x;
		pNext->y = ps->pSnake->y + 1;
		break;
	case MOVE_LEFT:
		pNext->x = ps->pSnake->x - 2;
		pNext->y = ps->pSnake->y;
		break;
	case MOVE_RIGHT:
		pNext->x = ps->pSnake->x + 2;
		pNext->y = ps->pSnake->y;
		break;
	}
	//�����һ��������ʳ��
	if (PosIsFood(pNext, ps))
	{
		EatFood(ps, pNext);
	}
	else
	{
		MoveForward(ps, pNext);
	}
	//���ײǽ
	HitWall(ps);
	//���ײ�Լ�
	HitSelf(ps);
	//��ͼ
	if (643 == ps->FoodEaten)
		ps->Status = FINISH_ALL;
}

void SetPos(int x, int y)
{
	//����豸���
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ù��λ��
	COORD pos = { x, y };
	SetConsoleCursorPosition(hOutput, pos);
}

void Welcome(void)
{
	SetPos(43, 10);
	printf("̰���ߣ�������");
	SetPos(42, 22);
	system("pause");
	system("cls");
	SetPos(32, 6);
	printf("ʹ�á�����������������̰���ߵ��ƶ�");
	SetPos(32, 9);
	printf("ʹ�����ּ�1~9������Ϸ�ٶȣ�1��9�죩");
	SetPos(32, 12);
	printf("�ٶ�Խ�ߵ÷�ҲԽ�ߣ������Ѷ�ҲԽ��");
	SetPos(32, 15);
	printf("���ո��������ͣ��ESC���˳�");
	SetPos(42, 22);
	system("pause");
	system("cls");
}

void PrintMap(void)
{
	SetPos(0, 0);
	for (int i = 0; i <= 28; ++i)
		wprintf(L"%lc", WALL);
	SetPos(0, 26);
	for (int i = 0; i <= 28; ++i)
		wprintf(L"%lc", WALL);
	for (int i = 1; i <= 25; ++i)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}
	for (int i = 1; i <= 25; ++i)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}
}

void InitSnake(pSnake ps)
{
	pSnakeNode pcur = NULL;
	//����5������Ľڵ�
	for (int i = 0; i < 5; ++i)
	{
		pcur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (!pcur)
		{ 
			system("cls");
			SetPos(0, 0);
			perror("InitSnake()->malloc()");
			exit(EXIT_FAILURE);
		}
		pcur->x = POS_X + 2 * i;
		pcur->y = POS_Y;
		pcur->next = NULL;
		//ͷ��
		if (!ps->pSnake)
		{
			ps->pSnake = pcur;
		}
		else
		{
			pcur->next = ps->pSnake;
			ps->pSnake = pcur;
		}
	}
}

void PrintSnake(pSnake ps)
{
	pSnakeNode pcur = ps->pSnake;
	SetPos(pcur->x, pcur->y);
	wprintf(L"%lc", HEAD);
	pcur = pcur->next;
	while (pcur)
	{
		SetPos(pcur->x, pcur->y);
		wprintf(L"%lc", BODY);
		pcur = pcur->next;
	};
}

void CreateFood(pSnake ps)
{
	srand((unsigned int)time(NULL));
	int half_x = 0, y = 0;
	do
	{
		half_x = rand() % 27 + 1;
		y = rand() % 25 + 1;
	} while (PosInSnake(2*half_x, y, ps)); 
	//����ʳ��ڵ�
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(pSnakeNode));
	if (!pFood)
	{
		system("cls");
		SetPos(0, 0);
		perror("CreatFood()->malloc()");
		exit(EXIT_FAILURE);
	}
	pFood->x = 2 * half_x;
	pFood->y = y;
	ps->pFood = pFood;
	SetPos(2 * half_x, y);
	wprintf(L"%lc", FOOD);
}

_Bool PosInSnake(int x, int y, pSnake ps)
{
	pSnakeNode pcur = ps->pSnake;
	while (pcur)
	{
		if (x == pcur->x && y == pcur->y)
		{
			return true;
		}
		pcur = pcur->next;
	}
	return false;
}

_Bool PosIsFood(pSnakeNode pNext, pSnake ps)
{
	if (ps->pFood->x == pNext->x && ps->pFood->y == pNext->y)
		return true;
	return false;
}

void PrintInfo(pSnake ps)
{
	SetPos(62, 2);
	printf("��ǰ�ܵ÷֣�%.1Lf", ps->Score);
	SetPos(62, 4);
	printf("��ʷ��߷֣�%.1Lf", ps->HighScore);
	SetPos(62, 6);
	printf("��һ��ʳ�%.1Lf", ps->FoodWeight * CalcFoodM(ps->FoodEaten));
	SetPos(62, 8);
	printf("��Ϸ�̳��ȣ�%d", MSPT_VAL[ps->MSPT]);
}

void PauseGame(pSnake ps)
{
	SetPos(62, 11);
	printf("����ͣ����Ϸ...");
	while (true)
	{
		Sleep(MSPT_VAL[ps->MSPT]);
		if (KEY_PRESSED(VK_SPACE))
		{
			SetPos(62, 9);
			printf("               ");
			break;
		}
	}
}

void EatFood(pSnake ps, pSnakeNode pNext)
{
	pNext->next = ps->pSnake;
	ps->pSnake = pNext;
	PrintSnake(ps);
	free(ps->pFood);
	CreateFood(ps);
	ps->Score += ps->FoodWeight * CalcFoodM(ps->FoodEaten);
	++ps->FoodEaten;
	if (ps->Score > ps->HighScore)
	{
		ps->HighScore = ps->Score;
		SetHighScore(ps->HighScore);
	}
}

void MoveForward(pSnake ps, pSnakeNode pNext)
{
	pNext->next = ps->pSnake;
	ps->pSnake = pNext;
	pSnakeNode pcur = ps->pSnake;
	while (pcur->next->next)
	{
		pcur = pcur->next;
	}
	SetPos(pcur->next->x, pcur->next->y);
	printf("  ");
	free(pcur->next);
	pcur->next = NULL;
	PrintSnake(ps);
}

long double CalcFoodM(int m)
{
	return 0.0004739178479 * m * m + 1;
}

void HitWall(pSnake ps)
{
	if (0 == ps->pSnake->x ||
		56 == ps->pSnake->x ||
		0 == ps->pSnake->y ||
		26 == ps->pSnake->y)
	{
		ps->Status = HIT_WALL;
	}
}

void HitSelf(pSnake ps)
{
	if (HeadInSelf(ps))
	{
		ps->Status = HIT_SELF;
	}
}

_Bool HeadInSelf(pSnake ps)
{
	pSnakeNode pcur = ps->pSnake->next;
	while (pcur)
	{
		if (ps->pSnake->x == pcur->x && ps->pSnake->y == pcur->y)
		{
			return true;
		}
		pcur = pcur->next;
	}
	return false;
}