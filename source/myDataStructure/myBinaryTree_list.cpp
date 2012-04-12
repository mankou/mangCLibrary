# include "binaryTree.h"
# include <malloc.h>
# include <myInput.h>
# include <stdio.h>
/*
**�õݹ���ʽ�����㣨����������������ʽʵ�ֵģ�
*/
void
insert2(BinaryTree ** current,TREE_TYPE value)
{
	/*
	**������Ϊ�գ����½���㡣�����㲻Ϊ�գ�����бȽϲ��ݹ����
	*/
	if(!*current){
		*current =(BinaryTree*)malloc( sizeof(BinaryTree) );
		/*
		**��malloc()���������㲻�ɹ���������д���
		*/
		if( !*current )
		{
			puts("���������");
		}
		else{
			/*
			**�½�㸳ֵ
			*/
			(*current)->value = value;
			(*current)->left = NULL;
			(*current)->right= NULL;
		}
	}
	else{
			
		/*
		**���Ҫ�����ֵ���ڵ�ǰ����Ӧ��ֵ����������������������������
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
**�ݹ鷽ʽ������������ֵ
**����Ϊ����ǰ���õݹ���ʽ������insert2()�������Ӧ������Ҳ�ں������һ��2
*/
void
printTree2(BinaryTree * root)
{
	
	/*
	**��������������������������
	**����������
	**Ȼ��������������������������
	*/
	if( root->left ){
		printTree2(root->left);
	}
	myPrintInt(root->value);
	if( root-> right){
		printTree2(root->right);
	}

}