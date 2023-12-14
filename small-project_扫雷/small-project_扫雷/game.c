#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

int t = 0;

//打印选择菜单
void menu()
{
	printf("****************\n");
	printf("***1.开始游戏***\n");
	printf("***0.结束游戏***\n");
	printf("****************\n");
}

//初始化数组（用字符填充）
void InitBoard(char arr[IROW][ICOL], int row, int col, char ch)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			arr[i][j] = ch;
}

//展示面版（打印数组）
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


//雷区初始化（确保第一步周围没有雷）
void SetMine(char mine[IROW][ICOL], char show[IROW][ICOL], char fakebool[IROW][ICOL])
{
	//第一步排雷点储存在r0、c0
	int r0 = 1;
	int c0 = 1;
	//用于储存随机数的变量
	int randrow = 0;
	int randcol = 0;
	//已经放置雷数
	int num = 0;

	//获得第一步输入
	do
	{
		if (!(1 <= r0 && ROW >= r0 && 1 <= c0 && COL >= c0))
		{
			system("CLS");
			DisplayBoard(show, IROW, ICOL);
			printf("此坐标有问题，重新输入\n");
		}
		printf("选定你的第一个排查区\n");
		printf("请输入坐标（先行后列，空格分隔，回车结尾）：");
		scanf("%d %d", &r0, &c0);
	} while (!(1 <= r0 && ROW >= r0 && 1 <= c0 && COL >= c0));

	//仿布尔类型标记
	fakebool[r0][c0] = '1';

	//时间戳
	t = time(NULL);

	//获取随机坐标放雷
	while (num != MINES)
	{
		randrow = rand() % ROW + 1;
		randcol = rand() % COL + 1;
		
		//随机坐标不能为已经有雷的格子，也不能是第一次排雷点所在九宫格内
		if ('0' == mine[randrow][randcol] && !(fabs(randcol - c0) <= 1 && fabs(randrow - r0)<= 1))
		{
			mine[randrow][randcol] = '1';
			num++;
		}
	}

	//显示区域
	show[r0][c0] = '0' + GetMine(mine, r0, c0);
	ShowArea(show, mine, fakebool);

	system("CLS");
}

//获取周围雷数
int GetMine(char mine[IROW][ICOL], int row, int col)
{
	return (mine[row - 1][col - 1] + mine[row][col - 1] + mine[row + 1][col - 1]) + mine[row + 1][col] + mine[row - 1][col] + mine[row + 1][col + 1] + mine[row][col + 1] + mine[row - 1][col + 1] - 8 * '0';
}

//找雷过程
void FindMine(char show[IROW][ICOL], char mine[IROW][ICOL], char fakebool[IROW][ICOL])
{
	//创建变量存储玩家输入
	int row = 1;
	int col = 1;
	int mines = MINES;
	do
	{
		//输入排查目标
		do
		{
			system("CLS");
			if (!(1 <= row && ROW >= row && 1 <= col && COL >= col))
			{
				system("CLS");
				printf("此坐标有问题，重新输入\n");
			}
			DisplayBoard(show, IROW, ICOL);
			//DisplayBoard(mine, IROW, ICOL);////////test
			printf("请输入坐标（先行后列，空格分隔，回车结尾）：");
			scanf("%d %d", &row, &col);
		} while (!(1 <= row && ROW >= row && 1 <= col && COL >= col));

		//判断雷况
		if (mine[row][col] == '1')
		{
			system("CLS");
			printf("你被炸死啦！！！\n");
			printf("用时%d秒\n", time(NULL) - t);
			printf("雷区情况如下：\n");
			DisplayBoard(mine, IROW, ICOL);
			printf("10秒后将回到标题画面...\n");
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

	//胜利结算
	if (Detected(show) == ROW * COL - MINES)
	{
		system("CLS");
		printf("你成功啦！\n");
		printf("用时%d秒\n", time(NULL) - t);
		printf("10秒后回到标题画面...\n");
		DisplayBoard(show, IROW, ICOL);
		Sleep(10000);
	}
}

//显示一片区域
void ShowArea(char show[IROW][ICOL], char mine[IROW][ICOL], char fakebool[IROW][ICOL])
{
	_Bool flag = false;//用于标记循环是否有意义，是否跳出
	
	do
	{
		flag = false;//每轮循环初始认为无意义
		for (int i = 1; i <= ROW; i++)
			for (int j = 1; j <= COL; j++)
				//上下左右的伪布尔值为1且自己不是雷且自己布尔值不为1且周围至少有一个show值为0则自己的伪布尔值也设为1
				if ((fakebool[i][j - 1] == '1' || fakebool[i - 1][j] == '1' || fakebool[i + 1][j] == '1' || fakebool[i][j + 1] == '1') && mine[i][j] != '1' && fakebool[i][j] != '1' && !(show[i - 1][j] != '0' && show[i + 1][j] != '0' && show[i][j - 1] != '0' && show[i][j + 1] != '0' && show[i+1][j+1] != '0'&& show[i-1][j-1] != '0'&& show[i+1][j-1] != '0'&& show[i-1][j+1] != '0'))
					fakebool[i][j] = '1', flag = true, show[i][j] = '0' + GetMine(mine, i, j);;//若发生改变，认为本轮循环有意义//将伪布尔值标记为应该显示的格子在show中显示
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