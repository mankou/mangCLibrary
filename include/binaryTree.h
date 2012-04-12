/*
**{create:2011年10月8日18时52分09秒}{last modify:2011年10月8日18时52分14秒}
**author:mang
**version:1.0
**function:二叉树相关源文件的头文件。即所有与二叉树相关的函数的函数原型，二叉树
类型声明都包括在该文件中
*/
# define TREE_TYPE int  //定义二叉树处理的基本类型

/*
**定义二叉树结点类型
**若是用链表形式实现二叉树，则需要定义二叉树结点类型。若是用数组形式实现则无须
定义该类型
*/
typedef struct BinaryTree_Temp{
	TREE_TYPE value;
	struct BinaryTree_Temp * left;
	struct BinaryTree_Temp * right;
}BinaryTree;


/*
**插入结点
**该插入函数是为用数组形式实现二叉树的情况准备的。
*/
void insert1(TREE_TYPE value);

/*
**插入结点
**该插入函数是为用链表形式实现二叉树的情况准备的。
*/
void insert2(BinaryTree ** current,TREE_TYPE value);

/*
**查找结点
*/
TREE_TYPE * find(TREE_TYPE value);

/*
**输出二叉树
**该函数是为用链表形式实现二叉树的情况准备的。
*/
void printTree2(BinaryTree * root);
