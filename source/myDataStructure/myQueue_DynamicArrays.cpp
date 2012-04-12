/*
**{create:2011年9月7日20时09分10秒}{last modify:2011年9月9日20时25分41秒}
**该文件为声明队列相关的函数的头文件，相当于队列的接口，任意实现队列的具体文件
可将该头文件包含进来，并具体实现相关函数即可
*/


# include <stdio.h>
# include <myQueue.h>
# include <malloc.h>
# include <assert.h>
# define QUEUE_TYPE int	//@todo注释 

/*
**front rear 分别指向队列的头和尾
**初始化时只要满足队列空的条件即可，不一定front一定为1,rear一定为0,也可以front=2 rear=1
*/
int front=1,rear=0;  

int QueueSize; //队列的容量

QUEUE_TYPE * array; //@todo
/*
**函数功能：创建队列
**说明：只有用动态数组实现队列时才用到该函数
*/
void  
create_Queue( unsigned size )
{
	QueueSize = size+1;//由于这里用循环数组实现队列，所以有一个空间空着不用，这里使QueueSize=size+1 以使队列真正的长度就是size
	array = ( QUEUE_TYPE * ) malloc( sizeof(QUEUE_TYPE) * QueueSize );
	/*
	**如果队列创建不成功，则说明
	*/
	if( !array )
	{
		puts("创建队列未成功");
	}
	
}

/*
**函数功能：销毁创建队列时所占用的内存
**说明：用单链表、动态数组形式实现队列时用到该函数，用静态数组实现队列时不需要该函数
*/
void
destroy_Queue( void )
{
	free( array );
	puts("已销毁队列");

}

/*
**函数功能：判断队列是否满，若满返回1 ，不满返回0
*/
int
isFull_Queue()
{
	return (rear+2)%QueueSize == front;

}

/*
**函数功能：判断队列是否为空，若空返回1,不空返回0
*/
int
isEmpty_Queue()
{
	return (rear+1)%QueueSize == front;

}

/*
**函数功能：入队操作
*/
void
insert_Queue(QUEUE_TYPE value)
{
	/*
	**加入防止在create前调用该函数
	*/
	if(!array)
	{
		puts("由于是用动态数组实现队列，所以不能在create之前调用本函数");
		assert(!array);
	}

	/*
	**入队操作，先判断队列是否为满，如不满再入队
	*/
	if( isFull_Queue() )
	{
		puts("队列已满，不能再进行入队操作了");
		return ;
	}
	else
	{
		rear = (rear+1)%QueueSize;
		array[ rear ] = value;
	}

}

/*
**函数功能：出队操作
**说明：这里的出队操作是指只弹出元素，不返回弹出的元素值
*/
void
delete_Queue()
{
	/*
	**加入防止在create前调用该函数
	*/
	if(!array)
	{
		puts("由于是用动态数组实现队列，所以不能在create之前调用本函数");
		assert(!array);
	}

	/*
	**出队操作，先判断队列是否为空，再进行出队操作
	*/
	if( isEmpty_Queue() )
	{
		puts("队列已经空了，不能进行出队操作");
		return;
	}
	else
	{
		front = (front+1)%QueueSize;
	}

}

/*
**函数功能：取得队列的第一个元素，即下一个要出队的元素值
**说明：只取得队列第一个元素，并不进行出队操作
*/
QUEUE_TYPE first_Queue()
{
	/*
	**加入防止在create前调用该函数
	*/
	if(!array)
	{
		puts("由于是用动态数组实现队列，所以不能在create之前调用本函数");
		assert(!array);
	}
	/*
	**先判断队列是否为空，若空则说明
	*/
	if(isEmpty_Queue())
	{
		puts("队列已空");
		
	}
	else
	{
		return array[front];
	}
}