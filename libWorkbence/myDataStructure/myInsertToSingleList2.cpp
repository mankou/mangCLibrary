/*
**{create:2011��7��6��15ʱ13��03��}{last modify:2011��7��6��15ʱ13��09��}
**author:mang
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>  //���ļ����õ���exit()������������Ҫ���ͷ�ļ�
#include <myDataStructureDeclare.h> //���Լ���ͷ�ļ�������������������������
/*
**�ڶ��ֵ��������ķ���
**�ú���������������һ����ָ���������ͷָ�룬һ����Ҫ���������
**��������Ķ�����myDataStructureDeclare.h�У�
������������һ������ֵvalue һ��ָ����һ����ָ��next
*/
SingleListNode * 
myInsertToSingleList2(SingleListNode * root, int value)
{
	SingleListNode *previous, *current,*newNode;

	previous = NULL;
	current = root;

	while(current != NULL && current->value < value )
	{
		previous= current;
		current = current->next;
	}

	newNode = (SingleListNode *)malloc( sizeof( SingleListNode ) );
	if( newNode == NULL )
	{
		printf("malloc error");
		exit(1);
	}
	newNode->value = value;
	
	if( previous == NULL )
	{
		newNode->next = root;
		return newNode;

	}
	else
	{
		newNode->next = current;
		previous->next = newNode;
		return root;
	}

}