/*
**{create:2011��9��6��20ʱ31��35��}{last modify:2011��9��6��20ʱ31��39��}
**author:mang
**���ļ����ã��þ�̬����ʵ��ѭ������
**�ο��ԡ�c��ָ�롷p364-p369
*/

//	@toto ͷ�ļ�Ҫ�ŵ�ָ��λ�ã�����<>����""
#include <stdio.h>
#include "myQueue.h"
#define QUEUE_SIZE 100	//�����þ�̬����ʵ�ֵĶ��е�����

static QUEUE_TYPE array[QUEUE_SIZE];	//������̬�������ڶ���
/*
**���������еĳ�ʼ��
**Front ������е�ͷ����Rear������е�β����
**��ʼ��ʱֻҪ����յ��������ɣ�Ҳ��(Rear+1)%QUEUE_SIZE == Front;������
*����Front=1,Rear=0
*/
static int Front=1,Rear=0;



/*
**�������ܣ��������У������������þ�̬����ʵ�ֶ��У����������ò��ţ�������ʵ��
*/
void
create_Queue( unsigned size)
{
	
}

/*
**�������ܣ����ٴ�������ʱ��ռ�õ��ڴ棬�����������þ�̬����ʵ�ֶ��У���������
�ò��ţ�������ʵ��
*/
void
destroy_Queue( void )
{

}

/*
**�������ܣ��ж϶����Ƿ�������������1 ����������0
*/
int
isFull_Queue()
{
	return (Rear+2)%QUEUE_SIZE == Front;	
}

/*
**�������ܣ��ж϶����Ƿ�Ϊ�գ����շ���1,���շ���0
*/
int
isEmpty_Queue()
{
	return (Rear+1)%QUEUE_SIZE == Front;
}

/*
**�������ܣ���Ӳ���
*/
void
insert_Queue( QUEUE_TYPE value )
{
		if( isFull_Queue() )
		{
			puts("�������������ܽ�����Ӳ���");
			return;
		}
		else 
		{
			Rear = (Rear + 1)%QUEUE_SIZE;
			array[ Rear ] = value;
		}
}

/*
**�������ܣ����Ӳ���
**˵��������ĳ��Ӳ�����ָֻ����Ԫ�أ������ص�����Ԫ��ֵ
*/
void
delete_Queue() 
{
	if( isEmpty_Queue() )
	{
		puts("�����ѿգ����ܽ��г��Ӳ���");
		return;
	}
	else
	{
		Front = (Front+1)%QUEUE_SIZE;
	}
}

/*
**�������ܣ�ȡ�ö��еĵ�һ��Ԫ�أ�����һ��Ҫ���ӵ�Ԫ��ֵ
**˵����ֻȡ�ö��е�һ��Ԫ�أ��������г��Ӳ���
*/
QUEUE_TYPE
first_Queue()
{
	if( isEmpty_Queue() )
	{
		puts("�����ѿգ����ܵ���first_Queue()����");
		
	}
	else
	{
		return array[Front];
	}
}