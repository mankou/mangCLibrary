# include "binaryTree.h"
# include <malloc.h>
# include <myInput.h>
# include <stdio.h>
/*
**用递归形式插入结点（二叉树是用链接形式实现的）
*/
void
insert2(BinaryTree ** current,TREE_TYPE value)
{
	/*
	**如果结点为空，则新建结点。如果结点不为空，则进行比较并递归调用
	*/
	if(!*current){
		*current =(BinaryTree*)malloc( sizeof(BinaryTree) );
		/*
		**对malloc()函数申请结点不成功的情况进行处理
		*/
		if( !*current )
		{
			puts("申请结点出错");
		}
		else{
			/*
			**新结点赋值
			*/
			(*current)->value = value;
			(*current)->left = NULL;
			(*current)->right= NULL;
		}
	}
	else{
			
		/*
		**如果要插入的值大于当前结点对应的值，则插入右子树，否则插入左子树
		*/
		if(value > (*current)->value){
			insert2(&(*current)->right,value);
		}
		else if(value < (*current)->value){
			insert2(&(*current)->left,value);
		}
	}

	
	
	
	
}

/*
**递归方式输出二叉树结点值
**这里为了与前面用递归形式插入结点insert2()函数相对应，所以也在后面加了一个2
*/
void
printTree2(BinaryTree * root)
{
	
	/*
	**如果左子树不空则输出左子树。
	**再输出根结点
	**然后如果右子树不空则输出右子树
	*/
	if( root->left ){
		printTree2(root->left);
	}
	myPrintInt(root->value);
	if( root-> right){
		printTree2(root->right);
	}

}