/*
**{create:2011年8月30日21时48分35秒}{lastmodify:2011年8月30日21时49分09秒}
**该文件用链表形式实现堆栈
*/
# include <stdio.h>
# include <myStack.h>
# include <malloc.h>
# include <assert.h>

/**这个文件中定义的全局变量，在main函数中并未使用，main函数中
*使用了该文件中的函数，该文件中的函数使用该文件中的全局变量那是
*再自然不过了。main函数之所以能使用该文件中的函数，也是加了函数
*原型声明的，只不过这个函数原型声明在myStack.h 头文件中罢了
*/

/*
**创建链表时第一个结点不用于存储数据，第二个结点才存储数据
*/

/*
**声明堆栈结点类型
*/
typedef struct listStack_temp
{
	STACK_TYPE value;
	listStack_temp * next;
}listStack;

/*pointer 作为堆栈的头指针*/
listStack * pointer = NULL;
/*
**由于是用链表实现堆栈，所以不用事先创建堆栈以获取空间
**只有用动态数组实现堆栈时才使用该函数
*/
void
createStack(unsigned size)
{

}

/*
**释放堆栈使用过的内存
*/
void
destoryStack(void)
{
	while( pointer ) //也可写成while( !isEmpty() )
	{
		listStack * temp = pointer;
		pointer = pointer->next;
		free(temp);
	}

}

/*
**入栈操作
*/
void
push(STACK_TYPE value)
{
	
        

		/*
		**创建新的结点，并赋值
		*/
		listStack * newNode = (listStack *)malloc( sizeof( listStack ) );
		//判断申请内存是否成功
		if( !newNode )
		{
			printf("malloc申请分配内存失败");
			return;
		}
		newNode->value = value;
		newNode->next = pointer;
		/*
		**更改头指针
		*/
		pointer = newNode ;

}

/*
**出栈操作
*/
void
pop()
{	
	
		/*
		**判断堆栈是否为空，若为空则直接返回
		*/
		if( isEmpty() )
		{
			puts("堆栈已经为空，不能进行出栈操作");
			return ;
		}

		/*
		*出栈操作
		*/
		listStack * temp = pointer;
		pointer = pointer->next;
		free(temp);

}

/*
**返回堆栈顶元素值
**只是返回顶元素值，并不进行出栈操作
*/
STACK_TYPE
top()
{
		
	if( isEmpty() )	
	{
		puts("堆栈已经空了，不能调用top()函数");
		assert( !isEmpty() );
	}
	return pointer->value;

}


/*
**由于是链表实现堆栈，所以不需要isFull()函数
*/

int
isFull()
{
	
	return 0;//由于是用链表实现堆栈，所以理论上说永远不会满，所以永远返回假(0)

}


/*
**判断堆栈是否为空
**若空返回1,否则返回0
*/
int
isEmpty()
{
	
		/*
		*判断堆栈是否为空
		*/
		return pointer == NULL;

}
