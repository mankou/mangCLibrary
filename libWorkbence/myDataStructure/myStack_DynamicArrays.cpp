/*
**{create:2011��8��30��21ʱ51��38��}{last modify:2011��8��30��21ʱ51��44��}
**author:mang
**���ļ��ö�̬����ʵ�ֶ�ջ
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
	
	assert( StackSize == 0 );//�ж��Ƿ��δ�����ջ�����������ֹ��������
	StackSize = size;	
	pointer=(STACK_TYPE *)malloc(size * sizeof(STACK_TYPE));	
	//�ж�pointer�Ƿ�Ϊ��
	if( !pointer ) 
	{
		printf("������ջʧ��\n");
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
		puts("���������ڴ�����ջǰ�����˱�����pust()��Ҳ���Ƕ�ջ�Ѿ����ˣ����Ծɵ���push()����");
		assert(!isFull());//һ�Ƿ�ֹ��ջ����ǰ���ñ�����(��isFull()�������)���Ƿ�ֹ��ջ��ʱ���ñ�����
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
		puts("�������ڴ�����ջǰ�����˱�����top()�������Ƕ�ջ��ʱ�����˱�����top()");
		assert( !isEmpty() );//һ�Ƿ�ֹ��ջ����ǰ���ñ���������isEmpty()������ɣ� ���Ƿ�ֹ��ջ��ʱ���ñ�������assert(!isEmpty())���
	}
	
	return pointer[ top_element ];
}

int
isFull()
{
	/*
	**ע��������ַ�������ڴ�����ջǰ�͵��ñ���������ͨ��assert()�������ж�����ֹ�����������ˣ�Ҳ�Ͳ�����return��
	*���������assert()��if������ 
	*if(������ջǰ���ñ�����) 
	*	��ֹ��������
	*else 
	*	return top_element == -1
	*/
	/*
	**��ֹ�ڶ�ջ����ǰ���ñ�����
	*/
	if(StackSize ==0 )
	{
		puts("�������ö�̬���鴴����ջ�����Բ����ڴ�����ջ֮ǰ���ñ�����isFull()");
		assert( StackSize >0 );	//��ֹ�ڶ�ջ����ǰ�͵��ñ�������Ҳ������������䣬����Ч��һ��assert( pointer );
	}
	
	return top_element >= (int)StackSize - 1  ; 
}

int
isEmpty()
{

	/*
	**ע��������ַ�������ڴ�����ջǰ�͵��ñ���������ͨ��assert()�������ж�����ֹ�����������ˣ�Ҳ�Ͳ�����return��
	*���������assert()��if������ 
	*if(������ջǰ���ñ�����) 
	*	��ֹ��������
	*else 
	*	return top_element == -1
	*/
	/*
	**��ֹ�ڶ�ջ����ǰ���ñ�����
	*/
	if(StackSize ==0 )
	{
		puts("�������ö�̬���鴴����ջ�����Բ����ڴ�����ջ֮ǰ���ñ�����isEmpty()");
		assert( StackSize >0 );	//��ֹ�ڶ�ջ����ǰ�͵��ñ�������Ҳ������������䣬����Ч��һ��assert( pointer );
	}
	
	return top_element == -1 ;
}