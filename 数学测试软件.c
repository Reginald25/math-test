#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 100  //������100������������
#define RIGHT 1
#define WRONG 0
#define TRUE 1

void SelectAdd();//ѡ��ӷ���
void SelectSub();//ѡ�������
void SelectMul();//ѡ��˷���
void SelectDiv();//ѡ�������
int AddFunc( int firstNum, int secondNum );//�ӷ��з�
int SubFunc( int firstNum, int secondNum );//�����з�
int MulFunc( int firstNum, int secondNum );//�˷��з�
int DivFunc( int firstNum, int secondNum );//�����з�

int total = 0;//���Ե���Ŀ����
int right = 0;//��ȷ�Ĵ�����

int main()
{
	int choiceNum;//��¼�û�ѡ�����
	srand( ( unsigned int ) time ( NULL ) );//����������趨
	while( TRUE )
	{
		printf( "1.�ӷ���\n2.������\n3.�˷���\n4.������\n5.���ͳ��\n0.�˳�\n" );
		printf( "\n�밴���֣�0~5��ѡ���Ӧ�Ĺ��ܣ�" );
		scanf( "%d", &choiceNum );
		while( choiceNum < 0 || choiceNum > 5 )
		{
			printf( "û����ѡ��Ĺ��ܣ�����ѡ��" );
			scanf( "%d", &choiceNum );
		}
		switch( choiceNum )
		{
			case 1:
				SelectAdd();//�ӷ���
				break;
			case 2:
				SelectSub();//������
				break;
			case 3:
				SelectMul();//�˷���
				break;
			case 4:
				SelectDiv();//������
				break;
			case 5:
				printf( "\n---------------------��Ĳ������ͳ��---------------------\n" );
				printf( "���Ѳ���%d�⣬������ȷΪ%d��\n", total, right );
				printf( "------------------------------------------------------------\n" );
				break;
			case 0:
				printf( "�˳�\n" );
				exit(0);
			default:
				break;
		}
	}
}

void SelectAdd()//�ӷ�ʵ��
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
		printf( "����һ���ӷ��⣿��������Y����y����������ѡ��������\n");
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
	while( scanf( "%d", &answer ) != 1 )//ֱ���û�����һ��������Ϊֹ
	{
		printf( "����𰸸�ʽ����ȷ��������\n");
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
		printf( "��ȷ���� %d\n", result );
		return WRONG;
	}
}

void SelectSub()//��������
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
		printf( "����һ�������⣿��������Y����y����������ѡ��������\n" );
		getchar();
		char c = getchar();
		getchar();
		if( c != 'Y' && c != 'y' )
			break;
	}
}

int SubFunc( int firstNum, int secondNum )//��������ж�
{
	int answer, result;
	printf( "%d - %d = ", firstNum, secondNum );
	while( scanf( "%d", &answer ) != 1 )//ֱ���û�����һ��������Ϊֹ
	{
		printf( "����𰸸�ʽ����ȷ��������\n" );
		getchar();
		printf( "%d - %d = ", firstNum, secondNum );
		getchar();
	}
	result = firstNum - secondNum;
	if( result == answer )
	{
		printf("Great��\n");
		return RIGHT;
	}
	else
	{
		printf( "��ȷ����:%d\n", result );
		return WRONG;
	}
}

void SelectMul()//ѡ��˷�����
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
		printf( "����һ���˷��⣿��������Y����y����������ѡ��������\n" );
		getchar();
		char c = getchar();
		getchar();
		if( c != 'Y' && c != 'y' )
			break;
	}
}

int MulFunc( int firstNum, int secondNum )//�Գ˷�����ж�
{
	int answer, result;
	printf( "%d * %d = ", firstNum, secondNum );
	while( scanf( "%d", &answer ) != 1 )//ֱ���û�����һ��������Ϊֹ
	{
		printf( "������Ĵ𰸸�ʽ����ȷ�������䣺\n" );
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
		printf( "��ȷ�Ĵ𰸣�%d\n", result );
		return WRONG;
	}
}

void SelectDiv()//ѡ���������
{
	while( TRUE )
	{
		++total;
		int dividend, divisor, result;
		dividend = rand() % RANGE;
		divisor = rand() % RANGE;
		result = dividend / divisor;
		while( dividend != result * divisor )//��������������������������
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
		printf( "����һ�������⣿��������Y����y����������ѡ��������\n" );
		getchar();
		char c = getchar();
		getchar();
		if( c != 'Y' && c != 'y' )
			break;
	}
}

int DivFunc( int firstNum, int secondNum )//�Գ�������ж�
{
	int answer, result;
	printf( "%d / %d = ", firstNum, secondNum );
	while( scanf( "%d", &answer ) != 1 )//ֱ���û�����һ��������Ϊֹ
	{
		printf( "������Ĵ𰸸�ʽ����ȷ�������䣺\n" );
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
		printf( "��ȷ�Ĵ𰸣�%d\n", result );
		return WRONG;
	}
}
