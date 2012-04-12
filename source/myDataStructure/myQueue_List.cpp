/*
**{create:2011年9月10日19时18分26秒}{last modify:2011年9月10日19时18分30秒}
**author:mang
**功能：用单链表实现队列
*/
#include <stdio.h>
#include <myQueue.h>
#include <malloc.h>

/*
**定义链表队列结点类型
*/
typedef struct ListQueue_Temp{
	QUEUE_TYPE  value;
	ListQueue_Temp * next;	
}ListQueue;

/*
**有两层意思。
1 定位头指针与尾指针
2 头指针、尾指针赋初值。由于是全局变量所以赋初值是稳秘的
*/
ListQueue * front , * rear;


/*
**创建队列
**由于这里是用链表实现队列，所以用不到该函数，这里空实现
*/
void  create_Queue( unsigned size )
{
	/*
	**由于是用链表实现队列，所以用不到create函数，这里空实现
	*/
}

/*
**销毁队列所使用的内存空间
*/
void
destroy_Queue( void )
{
	while( !isEmpty_Queue() )
	{
		ListQueue * temp = front;
		front = front->next;
		free(temp);
	}

}

/*
**判断队列是否满
**由于是用链表实现队列，所以理论上永远不会满。所以永远返回0
*/
int
isFull_Queue()
{
	return 0; //由于是用链表实现队列，理论上说永远不会满;
}

/*
**判断队列是否空
**若空返回1 否则返回0
*/
int
isEmpty_Queue()
{
	return front == NULL;
}

/*
**入队操作
*/
void
insert_Queue(QUEUE_TYPE value)
{
	ListQueue * newNode = ( ListQueue * )malloc( sizeof(ListQueue) );//申请新结点
	
	/*
	**先判断申请结点是否成功
	*/
	if( !newNode )
	{
		puts("申请结点未成功");
		return;
	}
	else{
		
		/*
		**新结点赋值
		*/
		newNode->value = value;
		newNode->next = NULL;
		
		/*
		**分两种情况，一种是插入之前还没有结点  另一种是插入之前已经有结点了
		*/
		if( isEmpty_Queue() )
		{

			front = rear = newNode;
		}
		else{
			rear->next = newNode;
			rear = newNode;
		}
		
	}
}

/*
**出队操作
**这里的出队是新的出队，即只弹出元素，但不返回弹出元素的值
*/
void
delete_Queue()
{
	/*
	**判断队列是否为空，若不空弹出元素，并销毁弹出元素所占用的空间
	*/
	if( !isEmpty_Queue() )
	{
		ListQueue * temp;
		temp = front;
		front = front->next;
		free(temp);
	}
	else{
		puts("队列已空，不能再进行出栈操作了");
	}
}

/*
**取得下一个出队元素的值
*/
QUEUE_TYPE
first_Queue()
{
	/*
	**先判断队列是否为空，若不空，取得下一个出队元素的值
	*/
	if(!isEmpty_Queue() )
	{
		return front->value;
	}
	else{
		puts("队列已空");
	}
}