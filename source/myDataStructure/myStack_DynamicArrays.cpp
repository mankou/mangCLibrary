/*
**{create:2011年8月30日21时51分38秒}{last modify:2011年8月30日21时51分44秒}
**author:mang
**该文件用动态数组实现堆栈
*/

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <myStack.h>

static int top_element = -1;
STACK_TYPE * pointer = NULL;
unsigned StackSize;

void
createStack(unsigned size)
{
	
	assert( StackSize == 0 );//判断是否多次创建堆栈，如果是则终止程序运行
	StackSize = size;	
	pointer=(STACK_TYPE *)malloc(size * sizeof(STACK_TYPE));	
	//判断pointer是否为空
	if( !pointer ) 
	{
		printf("创建堆栈失败\n");
		return ;
	}
	
}
void
destoryStack(void)
{
	assert( StackSize != 0 );
	StackSize = 0;
	free(pointer);
}
void
push(STACK_TYPE value)
{
	if( isFull() )
	{
		puts("可能是您在创建堆栈前调用了本函数pust()，也能是堆栈已经满了，你仍旧调用push()函数");
		assert(!isFull());//一是防止堆栈创建前调用本函数(由isFull()函数完成)二是防止堆栈满时调用本函数
	}
	
	pointer[ ++top_element ] = value;		

}
void
pop( void )
{
	assert( !isEmpty() );
	top_element-- ;
}
STACK_TYPE
top(void)
{
	if(StackSize ==0 )
	{
		puts("可能是在创建堆栈前调用了本函数top()，或者是堆栈空时调用了本函数top()");
		assert( !isEmpty() );//一是防止堆栈创建前调用本函数（由isEmpty()函数完成） 二是防止堆栈空时调用本函数由assert(!isEmpty())完成
	}
	
	return pointer[ top_element ];
}

int
isFull()
{
	/*
	**注意这里的手法，如果在创建堆栈前就调用本函数，则通过assert()函数的判定就终止本函数运行了，也就不会再return了
	*所以这里的assert()有if的作用 
	*if(创建堆栈前调用本函数) 
	*	终止程序运行
	*else 
	*	return top_element == -1
	*/
	/*
	**防止在堆栈创建前调用本函数
	*/
	if(StackSize ==0 )
	{
		puts("由于是用动态数组创建堆栈，所以不能在创建堆栈之前调用本函数isFull()");
		assert( StackSize >0 );	//防止在堆栈创建前就调用本函数。也可以用这条语句，作用效果一样assert( pointer );
	}
	
	return top_element >= (int)StackSize - 1  ; 
}

int
isEmpty()
{

	/*
	**注意这里的手法，如果在创建堆栈前就调用本函数，则通过assert()函数的判定就终止本函数运行了，也就不会再return了
	*所以这里的assert()有if的作用 
	*if(创建堆栈前调用本函数) 
	*	终止程序运行
	*else 
	*	return top_element == -1
	*/
	/*
	**防止在堆栈创建前调用本函数
	*/
	if(StackSize ==0 )
	{
		puts("由于是用动态数组创建堆栈，所以不能在创建堆栈之前调用本函数isEmpty()");
		assert( StackSize >0 );	//防止在堆栈创建前就调用本函数。也可以用这条语句，作用效果一样assert( pointer );
	}
	
	return top_element == -1 ;
}