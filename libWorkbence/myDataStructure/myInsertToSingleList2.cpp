/*
**{create:2011年7月6日15时13分03秒}{last modify:2011年7月6日15时13分09秒}
**author:mang
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>  //本文件中用到了exit()函数，所以需要这个头文件
#include <myDataStructureDeclare.h> //我自己的头文件，在这里用来声明单链表结点
/*
**第二种单链表插入的方法
**该函数有两个参数，一个是指向单链表结点的头指针，一个是要插入的整数
**单链表结点的定义在myDataStructureDeclare.h中，
结点包括两个域，一个整理值value 一个指向下一结点的指针next
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