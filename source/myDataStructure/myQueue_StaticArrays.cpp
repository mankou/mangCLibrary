/*
**{create:2011年9月6日20时31分35秒}{last modify:2011年9月6日20时31分39秒}
**author:mang
**该文件作用：用静态数组实现循环队列
**参考自《c和指针》p364-p369
*/

//	@toto 头文件要放到指定位置，并用<>代替""
#include <stdio.h>
#include "myQueue.h"
#define QUEUE_SIZE 100	//定义用静态数组实现的队列的容量

static QUEUE_TYPE array[QUEUE_SIZE];	//声明静态数组用于队列
/*
**以下语句队列的初始化
**Front 代表队列的头部，Rear代表队列的尾部。
**初始化时只要满足空的条件即可，也即(Rear+1)%QUEUE_SIZE == Front;在这里
*设置Front=1,Rear=0
*/
static int Front=1,Rear=0;



/*
**函数功能：创建队列，由于这里是用静态数组实现队列，所以这里用不着，函数空实现
*/
void
create_Queue( unsigned size)
{
	
}

/*
**函数功能：销毁创建队列时所占用的内存，由于这里是用静态数组实现队列，所以这里
用不着，函数空实现
*/
void
destroy_Queue( void )
{

}

/*
**函数功能：判断队列是否满，若满返回1 ，不满返回0
*/
int
isFull_Queue()
{
	return (Rear+2)%QUEUE_SIZE == Front;	
}

/*
**函数功能：判断队列是否为空，若空返回1,不空返回0
*/
int
isEmpty_Queue()
{
	return (Rear+1)%QUEUE_SIZE == Front;
}

/*
**函数功能：入队操作
*/
void
insert_Queue( QUEUE_TYPE value )
{
		if( isFull_Queue() )
		{
			puts("队列已满，不能进行入队操作");
			return;
		}
		else 
		{
			Rear = (Rear + 1)%QUEUE_SIZE;
			array[ Rear ] = value;
		}
}

/*
**函数功能：出队操作
**说明：这里的出队操作是指只弹出元素，不返回弹出的元素值
*/
void
delete_Queue() 
{
	if( isEmpty_Queue() )
	{
		puts("队列已空，不能进行出队操作");
		return;
	}
	else
	{
		Front = (Front+1)%QUEUE_SIZE;
	}
}

/*
**函数功能：取得队列的第一个元素，即下一个要出队的元素值
**说明：只取得队列第一个元素，并不进行出队操作
*/
QUEUE_TYPE
first_Queue()
{
	if( isEmpty_Queue() )
	{
		puts("队列已空，不能调用first_Queue()函数");
		
	}
	else
	{
		return array[Front];
	}
}