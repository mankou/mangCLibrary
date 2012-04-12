/*
**{create:2011年7月6日11时56分23秒}{last modify:2011年7月6日11时56分28秒}
**author:mang
**myDataStructure.h头文件是与myDataStructure函数库相对应的，myDataStructure函数库
用于存放我自己的数据结构相关的处理函数
*/



/*
**myInsertToSingleList()函数源文件路径为 库函数基准路径\source\myDataStructure\myPrintint.cpp
**单链表插入
链表的结点只有两个域 ，一个整型值，一个指向下一个结点的结构体指针
该函数有两个参数，一个是指向root的指针（指向结构体指针的指针），一个是要插入的数值
该函数无返回值。
函数将按照value由小到大的顺序，自建结点并插入到合适的位置。
*/
void myInsertToSingleList(SingleListNode ** const rootp, int const value );

/*
**myPrintSingleList()函数源文件路径为 库函数基准路径\source\myDataStructure\myPrintSingleList.cpp
**第二种单链表插入的方法
**该函数有两个参数，一个是指向单链表结点的头指针，一个是要插入的整数
**单链表结点的定义在myDataStructureDeclare.h中，
结点包括两个域，一个整理值value 一个指向下一结点的指针next
*/
SingleListNode * myInsertToSingleList2(SingleListNode * root, int value);

/*
**myPrintSingleList()函数源文件路径为 库函数基准路径\source\myDataStructure\myPrintSingleList.cpp
**该函数用输出单链表
**一个参数，该参数为头指针。没有返回值
**单链表结点只有两个域，其定义在myDataStrutureDeclare.h中
一个是整型变量，一个是指向该结构体结点的指针
*/
void myPrintSingleList(SingleListNode * root);


