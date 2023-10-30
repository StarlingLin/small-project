#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//��ӡѡ��˵�
void menu()
{
	printf("****************\n");
	printf("***1.��ʼ��Ϸ***\n");
	printf("***0.������Ϸ***\n");
	printf("****************\n");
}

//��ʼ�����飨���ַ���䣩
void InitBoard(char arr[IROW][ICOL], int row, int col, char ch)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			arr[i][j] = ch;
}

//չʾ��棨��ӡ���飩
void DisplayBoard(char arr[IROW][ICOL], int row, int col)
{
	for (int i = 0; i < col - 1; i++)
		if (i < 10)
			printf("%d  ", i);
		else
			printf("%d ", i);
	printf("\n");
	for (int i = 1; i < row - 1; i++)
	{
		if (i < 10)
			printf("%d  ", i);
		else
			printf("%d ", i);
		for (int j = 1; j < col - 1; j++)
			printf("%c  ", arr[i][j]);
		printf("\n");
	}
}


//������ʼ����ȷ����һ����Χû���ף�
void SetMine(char mine[IROW][ICOL], char show[IROW][ICOL], char fakebool[IROW][ICOL])
{
	//��һ�����׵㴢����r0��c0
	int r0 = 1;
	int c0 = 1;
	//���ڴ���������ı���
	int randrow = 0;
	int randcol = 0;
	//�Ѿ���������
	int num = 0;

	//��õ�һ������
	do
	{
		if (!(1 <= r0 && ROW >= r0 && 1 <= c0 && COL >= c0))
		{
			system("CLS");
			DisplayBoard(show, IROW, ICOL);
			printf("�����������⣬��������\n");
		}
		printf("ѡ����ĵ�һ���Ų���\n");
		printf("���������꣨���к��У��ո�ָ����س���β����");
		scanf("%d %d", &r0, &c0);
	} while (!(1 <= r0 && ROW >= r0 && 1 <= c0 && COL >= c0));

	//�²������ͱ��
	fakebool[r0][c0] = '1';

	//��ȡ����������
	while (num != MINES)
	{
		randrow = rand() % ROW + 1;
		randcol = rand() % COL + 1;
		
		//������겻��Ϊ�Ѿ����׵ĸ��ӣ�Ҳ�����ǵ�һ�����׵����ھŹ�����
		if ('0' == mine[randrow][randcol] && !(fabs(randcol - c0) <= 1 && fabs(randrow - r0)<= 1))
		{
			mine[randrow][randcol] = '1';
			num++;
		}
	}

	//��ʾ����
	show[r0][c0] = '0' + GetMine(mine, r0, c0);
	ShowArea(show, mine, fakebool);

	system("CLS");
}

//��ȡ��Χ����
int GetMine(char mine[IROW][ICOL], int row, int col)
{
	return (mine[row - 1][col - 1] + mine[row][col - 1] + mine[row + 1][col - 1]) + mine[row + 1][col] + mine[row - 1][col] + mine[row + 1][col + 1] + mine[row][col + 1] + mine[row - 1][col + 1] - 8 * '0';
}

//���׹���
void FindMine(char show[IROW][ICOL], char mine[IROW][ICOL], char fakebool[IROW][ICOL])
{
	//���������洢�������
	int row = 1;
	int col = 1;
	int mines = MINES;
	do
	{
		//�����Ų�Ŀ��
		do
		{
			if (!(1 <= row && ROW >= row && 1 <= col && COL >= col))
			{
				system("CLS");
				DisplayBoard(show, IROW, ICOL);
				printf("�����������⣬��������\n");
			}
			system("CLS");
			DisplayBoard(show, IROW, ICOL);
			//DisplayBoard(mine, IROW, ICOL);////////test
			printf("���������꣨���к��У��ո�ָ����س���β����");
			scanf("%d %d", &row, &col);
		} while (!(1 <= row && ROW >= row && 1 <= col && COL >= col));
		//�ж��׿�
		if (mine[row][col] == '1')
		{
			system("CLS");
			printf("�㱻ը����������\n");
			printf("����������£�\n");
			DisplayBoard(mine, IROW, ICOL);
			printf("10��󽫻ص����⻭��...\n");
			Sleep(10000);
			system("CLS");
			break;
		}
		else
		{
			fakebool[row][col] = '1';
			show[row][col] = '0' + GetMine(mine, row, col);
			ShowArea(show, mine, fakebool);
		}
	} while (Detected(show) != ROW * COL - MINES);

	//ʤ������
	if (Detected(show) == ROW * COL - MINES)
	{
		system("CLS");
		printf("��ɹ�����\n");
		printf("10���ص����⻭��...\n");
		DisplayBoard(show, IROW, ICOL);
		Sleep(10000);
	}
}

//��ʾһƬ����
void ShowArea(char show[IROW][ICOL], char mine[IROW][ICOL], char fakebool[IROW][ICOL])
{
	_Bool flag = false;//���ڱ��ѭ���Ƿ������壬�Ƿ�����
	
	do
	{
		flag = false;//ÿ��ѭ����ʼ��Ϊ������
		for (int i = 1; i <= ROW; i++)
			for (int j = 1; j <= COL; j++)
				//�������ҵ�α����ֵΪ1���Լ����������Լ�����ֵ��Ϊ1����Χ������һ��showֵΪ0���Լ���α����ֵҲ��Ϊ1
				if ((fakebool[i][j - 1] == '1' || fakebool[i - 1][j] == '1' || fakebool[i + 1][j] == '1' || fakebool[i][j + 1] == '1') && mine[i][j] != '1' && fakebool[i][j] != '1' && !(show[i - 1][j] != '0' && show[i + 1][j] != '0' && show[i][j - 1] != '0' && show[i][j + 1] != '0' && show[i+1][j+1] != '0'&& show[i-1][j-1] != '0'&& show[i+1][j-1] != '0'&& show[i-1][j+1] != '0'))
					fakebool[i][j] = '1', flag = true, show[i][j] = '0' + GetMine(mine, i, j);;//�������ı䣬��Ϊ����ѭ��������//��α����ֵ���ΪӦ����ʾ�ĸ�����show����ʾ
	} while (flag);
}

int Detected(char show[IROW][ICOL])
{
	int cnt = 0;
	for (int i = 1; i <= ROW; i++)
		for (int j = 1; j <= COL; j++)
			if (show[i][j] != '*')
				cnt++;
	return cnt;
}