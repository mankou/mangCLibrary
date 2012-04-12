/*
**{create:2011��9��10��19ʱ18��26��}{last modify:2011��9��10��19ʱ18��30��}
**author:mang
**���ܣ��õ�����ʵ�ֶ���
*/
#include <stdio.h>
#include <myQueue.h>
#include <malloc.h>

/*
**����������н������
*/
typedef struct ListQueue_Temp{
	QUEUE_TYPE  value;
	ListQueue_Temp * next;	
}ListQueue;

/*
**��������˼��
1 ��λͷָ����βָ��
2 ͷָ�롢βָ�븳��ֵ��������ȫ�ֱ������Ը���ֵ�����ص�
*/
ListQueue * front , * rear;


/*
**��������
**����������������ʵ�ֶ��У������ò����ú����������ʵ��
*/
void  create_Queue( unsigned size )
{
	/*
	**������������ʵ�ֶ��У������ò���create�����������ʵ��
	*/
}

/*
**���ٶ�����ʹ�õ��ڴ�ռ�
*/
void
destroy_Queue( void )
{
	while( !isEmpty_Queue() )
	{
		ListQueue * temp = front;
		front = front->next;
		free(temp);
	}

}

/*
**�ж϶����Ƿ���
**������������ʵ�ֶ��У�������������Զ��������������Զ����0
*/
int
isFull_Queue()
{
	return 0; //������������ʵ�ֶ��У�������˵��Զ������;
}

/*
**�ж϶����Ƿ��
**���շ���1 ���򷵻�0
*/
int
isEmpty_Queue()
{
	return front == NULL;
}

/*
**��Ӳ���
*/
void
insert_Queue(QUEUE_TYPE value)
{
	ListQueue * newNode = ( ListQueue * )malloc( sizeof(ListQueue) );//�����½��
	
	/*
	**���ж��������Ƿ�ɹ�
	*/
	if( !newNode )
	{
		puts("������δ�ɹ�");
		return;
	}
	else{
		
		/*
		**�½�㸳ֵ
		*/
		newNode->value = value;
		newNode->next = NULL;
		
		/*
		**�����������һ���ǲ���֮ǰ��û�н��  ��һ���ǲ���֮ǰ�Ѿ��н����
		*/
		if( isEmpty_Queue() )
		{

			front = rear = newNode;
		}
		else{
			rear->next = newNode;
			rear = newNode;
		}
		
	}
}

/*
**���Ӳ���
**����ĳ������µĳ��ӣ���ֻ����Ԫ�أ��������ص���Ԫ�ص�ֵ
*/
void
delete_Queue()
{
	/*
	**�ж϶����Ƿ�Ϊ�գ������յ���Ԫ�أ������ٵ���Ԫ����ռ�õĿռ�
	*/
	if( !isEmpty_Queue() )
	{
		ListQueue * temp;
		temp = front;
		front = front->next;
		free(temp);
	}
	else{
		puts("�����ѿգ������ٽ��г�ջ������");
	}
}

/*
**ȡ����һ������Ԫ�ص�ֵ
*/
QUEUE_TYPE
first_Queue()
{
	/*
	**���ж϶����Ƿ�Ϊ�գ������գ�ȡ����һ������Ԫ�ص�ֵ
	*/
	if(!isEmpty_Queue() )
	{
		return front->value;
	}
	else{
		puts("�����ѿ�");
	}
}