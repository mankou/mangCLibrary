/**{create:2011��7��18��19ʱ04��35��}{last modify:2011��7��18��19ʱ04��39��}
*author:mang
*����Դ�ڡ�c��ָ�롷p357-p358 �þ�̬����ʵ�ֶ�ջ
*�ó���Ϊ �þ�̬����ʵ�ֶ�ջ�ľ���ʵ�ִ��� 
*mystack_staticArrays.cpp my��ǰ׺�������ҵ��ļ� stack��ʾ��ջ��_a����
*/

#include <assert.h>			//assert.h ��ϵͳ��ͷ�ļ�,���ļ��е�assert()�����õ������ͷ�ļ���
#include <myStack.h>			//stack.h   �����Լ�������ͷ�ļ����ó���ķ�ʽ�����˹��ڶ�ջ����������
#define STACK_SIZE 100		//STACK_SIZE �����ջ����󳤶�

static STACK_TYPE  array[STACK_SIZE];	//��̬����array[]��Ϊ��ջ����Ĵ洢����
static int top_element = -1;			//top_element ָ���ջ�������Ԫ��

/**
*��ջ�����ľ���ʵ�� ����STACK_TYPE ��stack.h �ļ�����#define ����������������ջ�������������
*/
void
push(STACK_TYPE value)		
{
	assert( !isFull() );
	array[ ++top_element ] = value;

}

/**
*��ջ�����ľ���ʵ�� ����STACK_TYPE ��stack.h �ļ�����#define ����������������ջ�������������
*/
void
pop()
{
	assert( !isEmpty() );
	top_element--;
}

/**
*�õ�ջ��Ԫ��ֵ�����ľ���ʵ�֣�ע��ֻ�õ�ջ��Ԫ��ֵ���������г�ջ��ջ���� ����STACK_TYPE ��stack.h �ļ�����#define ����������������ջ�������������
*/
STACK_TYPE
top()
{
	return array[ top_element ];
}

/**
*�ж϶�ջĿǰ�Ƿ�����
*/
int
isFull()
{
	return top_element >= STACK_SIZE-1 ;
}

/**
*�ж϶�ջĿ¼�Ƿ�Ϊ��
*/
int
isEmpty()
{
	return top_element == -1 ;
}
//~