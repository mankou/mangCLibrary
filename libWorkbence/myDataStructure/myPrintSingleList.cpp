#include <stdio.h>
#include <myDataStructureDeclare.h>
/*
**该函数用输出单链表
**单链表结点只有两个域，其定义在myDataStrutureDeclare.h中
一个是整型变量，一个是指向该结构体结点的指针
*/
void 
myPrintSingleList(SingleListNode * root)
{
	SingleListNode * current;

	current = root;

	/*输出结点中的value值*/
	while(current!=NULL)
	{
		printf("%d-->",current->value);
		current = current->next;
	}

	printf("NULL\n");
}
