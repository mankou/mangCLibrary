/**{create:2011年7月18日19时04分35秒}{last modify:2011年7月18日19时04分39秒}
*author:mang
*程序源于《c和指针》p357-p358 用静态数组实现堆栈
*该程序为 用静态数组实现堆栈的具体实现代码 
*mystack_staticArrays.cpp my是前缀代表是我的文件 stack表示堆栈，_a代表
*/

#include <assert.h>			//assert.h 是系统的头文件,本文件中的assert()函数用到了这个头文件。
#include <myStack.h>			//stack.h   是我自己声明的头文件，用抽象的方式声明了关于堆栈函数的声明
#define STACK_SIZE 100		//STACK_SIZE 定义堆栈的最大长度

static STACK_TYPE  array[STACK_SIZE];	//静态数组array[]是为堆栈分配的存储区域
static int top_element = -1;			//top_element 指向堆栈最上面的元素

/**
*入栈函数的具体实现 其中STACK_TYPE 在stack.h 文件中用#define 定义过，用来抽象堆栈处理的数据类型
*/
void
push(STACK_TYPE value)		
{
	assert( !isFull() );
	array[ ++top_element ] = value;

}

/**
*出栈函数的具体实现 其中STACK_TYPE 在stack.h 文件中用#define 定义过，用来抽象堆栈处理的数据类型
*/
void
pop()
{
	assert( !isEmpty() );
	top_element--;
}

/**
*得到栈顶元素值函数的具体实现，注意只得到栈顶元素值，并不进行出栈入栈操作 其中STACK_TYPE 在stack.h 文件中用#define 定义过，用来抽象堆栈处理的数据类型
*/
STACK_TYPE
top()
{
	return array[ top_element ];
}

/**
*判断堆栈目前是否满了
*/
int
isFull()
{
	return top_element >= STACK_SIZE-1 ;
}

/**
*判断堆栈目录是否为空
*/
int
isEmpty()
{
	return top_element == -1 ;
}
//~