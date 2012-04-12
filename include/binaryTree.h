/*
**{create:2011��10��8��18ʱ52��09��}{last modify:2011��10��8��18ʱ52��14��}
**author:mang
**version:1.0
**function:���������Դ�ļ���ͷ�ļ������������������صĺ����ĺ���ԭ�ͣ�������
���������������ڸ��ļ���
*/
# define TREE_TYPE int  //�������������Ļ�������

/*
**����������������
**������������ʽʵ�ֶ�����������Ҫ���������������͡�������������ʽʵ��������
���������
*/
typedef struct BinaryTree_Temp{
	TREE_TYPE value;
	struct BinaryTree_Temp * left;
	struct BinaryTree_Temp * right;
}BinaryTree;


/*
**������
**�ò��뺯����Ϊ��������ʽʵ�ֶ����������׼���ġ�
*/
void insert1(TREE_TYPE value);

/*
**������
**�ò��뺯����Ϊ��������ʽʵ�ֶ����������׼���ġ�
*/
void insert2(BinaryTree ** current,TREE_TYPE value);

/*
**���ҽ��
*/
TREE_TYPE * find(TREE_TYPE value);

/*
**���������
**�ú�����Ϊ��������ʽʵ�ֶ����������׼���ġ�
*/
void printTree2(BinaryTree * root);
