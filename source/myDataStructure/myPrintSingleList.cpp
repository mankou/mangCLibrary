#include <stdio.h>
#include <myDataStructureDeclare.h>
/*
**�ú��������������
**��������ֻ���������䶨����myDataStrutureDeclare.h��
һ�������ͱ�����һ����ָ��ýṹ�����ָ��
*/
void 
myPrintSingleList(SingleListNode * root)
{
	SingleListNode * current;

	current = root;

	/*�������е�valueֵ*/
	while(current!=NULL)
	{
		printf("%d-->",current->value);
		current = current->next;
	}

	printf("NULL\n");
}
