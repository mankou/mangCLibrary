/*
**{create:2011年7月6日11时42分37秒}{last modify:2011年7月6日11时42分41秒}
**author:mang 
*/


/* 这个新类型的定义很有意思，它把结构体类型的定义与typedef合在了一起
由于结构体中的成员变量有指向该类型结构体的指针，所以用了一个临时的名字
Node_tag,神奇就神奇在这了，否则你得分两步走，第一步先声明一个结构体的定义，
第二步typedef */
/*
**定义一个结构定类型，该类型目前用于单链表结构
myInsertToSingleList()函数 myPrintSingleList()函数将会用到这个类型声明
*/
typedef struct Node_tag
{
	int value;
	struct Node_tag *next;

}SingleListNode ;