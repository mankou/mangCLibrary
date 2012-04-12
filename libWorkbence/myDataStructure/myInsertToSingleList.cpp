/*
**{create:2011年7月2日22时13分15秒}{last modify:2011年7月6日11时51分36秒}
**author:mang
**单链表的插入
**程序来源于"c和指针" 244页
*/

#include <stdio.h>
#include <myDataStructureDeclare.h>  //我自己的头文件,用来声明结构体的定义
#include <malloc.h>
#include <stdlib.h>   //文件中用到了exit()函数,stdlib.h中包括exit()函数的函数原型

/*
**单链表插入
链表的结点只有两个域 ，一个整型值，一个指向下一个结点的结构体指针
该函数有两个参数，一个是指向root的指针（指向结构体指针的指针），一个是要插入的数值
该函数无返回值。
函数将按照value由小到大的顺序，自建结点并插入到合适的位置。
*/
void
myInsertToSingleList(SingleListNode ** const rootp, int const value )
{
	SingleListNode **link,*current,*newSingleListNode;
	link = rootp;
	current = *rootp;

	
	/*
	**正因为这里判断的是current !=NUll而不是current->next != NULL
	才使得插在末尾的情况纳入到插入中间的一般情况中
	*/
	/*寻找新结点插入的位置*/
	while( current!=NULL && current->value < value )
	{
		link = &(current->next);
		current = current->next;
	}

	/*创建新的结点*/
	newSingleListNode = (SingleListNode *)malloc( sizeof( SingleListNode ) );
	if(newSingleListNode == NULL)
	{
		printf("malloc error");
		exit(1);
	}
	newSingleListNode->value=value;

	/*
	**这里非常的讲究，包括了2种情况：
	1把结点插在中间（插入末尾的情况也算在这种情况之内，此时current = null）
	2把结点插在头部（这时需要修改头指针root）
	*/
	/*插入新的结点*/
	newSingleListNode->next = current;
	*link = newSingleListNode;

}