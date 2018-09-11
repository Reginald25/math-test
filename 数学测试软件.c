#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 100  //测试是100以内算术运算
#define RIGHT 1
#define WRONG 0
#define TRUE 1

void SelectAdd();//选择加法题
void SelectSub();//选择减法题
void SelectMul();//选择乘法题
void SelectDiv();//选择除法题
int AddFunc( int firstNum, int secondNum );//加法判分
int SubFunc( int firstNum, int secondNum );//减法判分
int MulFunc( int firstNum, int secondNum );//乘法判分
int DivFunc( int firstNum, int secondNum );//除法判分

int total = 0;//测试的题目总数
int right = 0;//正确的答题数

int main()
{
	int choiceNum;//记录用户选择操作
	srand( ( unsigned int ) time ( NULL ) );//随机量种子设定
	while( TRUE )
	{
		printf( "1.加法题\n2.减法题\n3.乘法题\n4.除法题\n5.结果统计\n0.退出\n" );
		printf( "\n请按数字（0~5）选择对应的功能：" );
		scanf( "%d", &choiceNum );
		while( choiceNum < 0 || choiceNum > 5 )
		{
			printf( "没有你选择的功能，请重选：" );
			scanf( "%d", &choiceNum );
		}
		switch( choiceNum )
		{
			case 1:
				SelectAdd();//加法题
				break;
			case 2:
				SelectSub();//减法题
				break;
			case 3:
				SelectMul();//乘法题
				break;
			case 4:
				SelectDiv();//除法题
				break;
			case 5:
				printf( "\n---------------------你的测试情况统计---------------------\n" );
				printf( "你已测试%d题，其中正确为%d题\n", total, right );
				printf( "------------------------------------------------------------\n" );
				break;
			case 0:
				printf( "退出\n" );
				exit(0);
			default:
				break;
		}
	}
}

void SelectAdd()//加法实现
{
	while( TRUE )
	{
		++total;
		int firstNum, secondNum, sum;
		firstNum = rand() % RANGE;
		secondNum = rand() % RANGE;
		sum = firstNum + secondNum;
		while( sum > 100)
        {
            firstNum = rand() % RANGE;
            secondNum = rand() % RANGE;
            sum = firstNum + secondNum;
        }
		if( AddFunc( firstNum, secondNum ) )
			++right;
		printf( "再做一道加法题？继续按‘Y’或‘y’，返回重选按其他键\n");
		getchar();
		char c = getchar();
		getchar();
		if( c != 'Y' && c != 'y' )
			break;
	}
}

int AddFunc( int firstNum, int secondNum )
{
	int answer, result;
	printf(" %d + %d = ", firstNum, secondNum );
	while( scanf( "%d", &answer ) != 1 )//直到用户输入一个整数答案为止
	{
		printf( "输入答案格式不正确，请重输\n");
		getchar();
		printf( "%d + %d = ", firstNum, secondNum );
		getchar();
	}
	result = firstNum + secondNum;
	if( result == answer )
	{
		printf( "Great!\n" );
		return RIGHT;
	}
	else
	{
		printf( "正确答案是 %d\n", result );
		return WRONG;
	}
}

void SelectSub()//减法运算
{
	while( TRUE )
	{
		++total;
		int firstNum, secondNum;
		firstNum = rand() % RANGE;
		secondNum = rand() % RANGE;
		while( firstNum < secondNum )
        {
            firstNum = rand() % RANGE;
            secondNum = rand() % RANGE;
        }
		if( SubFunc( firstNum, secondNum ) )
			++right;
		printf( "再做一道减法题？继续按‘Y’或‘y’，返回重选按其他键\n" );
		getchar();
		char c = getchar();
		getchar();
		if( c != 'Y' && c != 'y' )
			break;
	}
}

int SubFunc( int firstNum, int secondNum )//减法结果判断
{
	int answer, result;
	printf( "%d - %d = ", firstNum, secondNum );
	while( scanf( "%d", &answer ) != 1 )//直到用户输入一个整数答案为止
	{
		printf( "输入答案格式不正确，请重输\n" );
		getchar();
		printf( "%d - %d = ", firstNum, secondNum );
		getchar();
	}
	result = firstNum - secondNum;
	if( result == answer )
	{
		printf("Great！\n");
		return RIGHT;
	}
	else
	{
		printf( "正确答案是:%d\n", result );
		return WRONG;
	}
}

void SelectMul()//选择乘法运算
{
	while( TRUE )
	{
		++total;
		int firstNum, secondNum;
		firstNum = rand() % RANGE;
		secondNum = rand() % RANGE;
		while( firstNum * secondNum > 100 )
        {
            firstNum = rand() % RANGE;
            secondNum = rand() % RANGE;
        }
		if( MulFunc( firstNum, secondNum ) )
			++right;
		printf( "再做一道乘法题？继续按‘Y’或‘y’，返回重选按其他键\n" );
		getchar();
		char c = getchar();
		getchar();
		if( c != 'Y' && c != 'y' )
			break;
	}
}

int MulFunc( int firstNum, int secondNum )//对乘法结果判断
{
	int answer, result;
	printf( "%d * %d = ", firstNum, secondNum );
	while( scanf( "%d", &answer ) != 1 )//直到用户输入一个整数答案为止
	{
		printf( "你输入的答案格式不正确，请重输：\n" );
		getchar();
		printf( "%d * %d = ", firstNum, secondNum );
		getchar();
	}
	result = firstNum * secondNum;
	if( result == answer )
	{
		printf( "Great!\n" );
		return RIGHT;
	}
	else
	{
		printf( "正确的答案：%d\n", result );
		return WRONG;
	}
}

void SelectDiv()//选择除法运算
{
	while( TRUE )
	{
		++total;
		int dividend, divisor, result;
		dividend = rand() % RANGE;
		divisor = rand() % RANGE;
		result = dividend / divisor;
		while( dividend != result * divisor )//若不能整除则重新生成两个数
		{
			while( dividend < divisor)
            {
                dividend = rand() % RANGE;
                divisor = rand() % RANGE;
            }
			dividend = rand() % RANGE;
			divisor = rand() % RANGE;
			result = dividend / divisor;
		}
		if( DivFunc( dividend, divisor ) )
			++right;
		printf( "再做一道除法题？继续按‘Y’或‘y’，返回重选按其他键\n" );
		getchar();
		char c = getchar();
		getchar();
		if( c != 'Y' && c != 'y' )
			break;
	}
}

int DivFunc( int firstNum, int secondNum )//对除法结果判断
{
	int answer, result;
	printf( "%d / %d = ", firstNum, secondNum );
	while( scanf( "%d", &answer ) != 1 )//直到用户输入一个整数答案为止
	{
		printf( "你输入的答案格式不正确，请重输：\n" );
		getchar();
		printf( "%d / %d = ", firstNum, secondNum );
		getchar();
	}
	result = firstNum / secondNum;
	if( result == answer )
	{
		printf( "Great!\n" );
		return RIGHT;
	}
	else
	{
		printf( "正确的答案：%d\n", result );
		return WRONG;
	}
}
