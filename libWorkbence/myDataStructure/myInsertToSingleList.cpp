/*
**{create:2011��7��2��22ʱ13��15��}{last modify:2011��7��6��11ʱ51��36��}
**author:mang
**������Ĳ���
**������Դ��"c��ָ��" 244ҳ
*/

#include <stdio.h>
#include <myDataStructureDeclare.h>  //���Լ���ͷ�ļ�,���������ṹ��Ķ���
#include <malloc.h>
#include <stdlib.h>   //�ļ����õ���exit()����,stdlib.h�а���exit()�����ĺ���ԭ��

/*
**���������
����Ľ��ֻ�������� ��һ������ֵ��һ��ָ����һ�����Ľṹ��ָ��
�ú���������������һ����ָ��root��ָ�루ָ��ṹ��ָ���ָ�룩��һ����Ҫ�������ֵ
�ú����޷���ֵ��
����������value��С�����˳���Խ���㲢���뵽���ʵ�λ�á�
*/
void
myInsertToSingleList(SingleListNode ** const rootp, int const value )
{
	SingleListNode **link,*current,*newSingleListNode;
	link = rootp;
	current = *rootp;

	
	/*
	**����Ϊ�����жϵ���current !=NUll������current->next != NULL
	��ʹ�ò���ĩβ��������뵽�����м��һ�������
	*/
	/*Ѱ���½������λ��*/
	while( current!=NULL && current->value < value )
	{
		link = &(current->next);
		current = current->next;
	}

	/*�����µĽ��*/
	newSingleListNode = (SingleListNode *)malloc( sizeof( SingleListNode ) );
	if(newSingleListNode == NULL)
	{
		printf("malloc error");
		exit(1);
	}
	newSingleListNode->value=value;

	/*
	**����ǳ��Ľ�����������2�������
	1�ѽ������м䣨����ĩβ�����Ҳ�����������֮�ڣ���ʱcurrent = null��
	2�ѽ�����ͷ������ʱ��Ҫ�޸�ͷָ��root��
	*/
	/*�����µĽ��*/
	newSingleListNode->next = current;
	*link = newSingleListNode;

}