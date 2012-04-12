/*
**{create:2011��8��30��21ʱ48��35��}{lastmodify:2011��8��30��21ʱ49��09��}
**���ļ���������ʽʵ�ֶ�ջ
*/
# include <stdio.h>
# include <myStack.h>
# include <malloc.h>
# include <assert.h>

/**����ļ��ж����ȫ�ֱ�������main�����в�δʹ�ã�main������
*ʹ���˸��ļ��еĺ��������ļ��еĺ���ʹ�ø��ļ��е�ȫ�ֱ�������
*����Ȼ�����ˡ�main����֮������ʹ�ø��ļ��еĺ�����Ҳ�Ǽ��˺���
*ԭ�������ģ�ֻ�����������ԭ��������myStack.h ͷ�ļ��а���
*/

/*
**��������ʱ��һ����㲻���ڴ洢���ݣ��ڶ������Ŵ洢����
*/

/*
**������ջ�������
*/
typedef struct listStack_temp
{
	STACK_TYPE value;
	listStack_temp * next;
}listStack;

/*pointer ��Ϊ��ջ��ͷָ��*/
listStack * pointer = NULL;
/*
**������������ʵ�ֶ�ջ�����Բ������ȴ�����ջ�Ի�ȡ�ռ�
**ֻ���ö�̬����ʵ�ֶ�ջʱ��ʹ�øú���
*/
void
createStack(unsigned size)
{

}

/*
**�ͷŶ�ջʹ�ù����ڴ�
*/
void
destoryStack(void)
{
	while( pointer ) //Ҳ��д��while( !isEmpty() )
	{
		listStack * temp = pointer;
		pointer = pointer->next;
		free(temp);
	}

}

/*
**��ջ����
*/
void
push(STACK_TYPE value)
{
	
        

		/*
		**�����µĽ�㣬����ֵ
		*/
		listStack * newNode = (listStack *)malloc( sizeof( listStack ) );
		//�ж������ڴ��Ƿ�ɹ�
		if( !newNode )
		{
			printf("malloc��������ڴ�ʧ��");
			return;
		}
		newNode->value = value;
		newNode->next = pointer;
		/*
		**����ͷָ��
		*/
		pointer = newNode ;

}

/*
**��ջ����
*/
void
pop()
{	
	
		/*
		**�ж϶�ջ�Ƿ�Ϊ�գ���Ϊ����ֱ�ӷ���
		*/
		if( isEmpty() )
		{
			puts("��ջ�Ѿ�Ϊ�գ����ܽ��г�ջ����");
			return ;
		}

		/*
		*��ջ����
		*/
		listStack * temp = pointer;
		pointer = pointer->next;
		free(temp);

}

/*
**���ض�ջ��Ԫ��ֵ
**ֻ�Ƿ��ض�Ԫ��ֵ���������г�ջ����
*/
STACK_TYPE
top()
{
		
	if( isEmpty() )	
	{
		puts("��ջ�Ѿ����ˣ����ܵ���top()����");
		assert( !isEmpty() );
	}
	return pointer->value;

}


/*
**����������ʵ�ֶ�ջ�����Բ���ҪisFull()����
*/

int
isFull()
{
	
	return 0;//������������ʵ�ֶ�ջ������������˵��Զ��������������Զ���ؼ�(0)

}


/*
**�ж϶�ջ�Ƿ�Ϊ��
**���շ���1,���򷵻�0
*/
int
isEmpty()
{
	
		/*
		*�ж϶�ջ�Ƿ�Ϊ��
		*/
		return pointer == NULL;

}
