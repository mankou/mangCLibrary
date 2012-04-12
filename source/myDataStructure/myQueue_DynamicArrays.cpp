/*
**{create:2011��9��7��20ʱ09��10��}{last modify:2011��9��9��20ʱ25��41��}
**���ļ�Ϊ����������صĺ�����ͷ�ļ����൱�ڶ��еĽӿڣ�����ʵ�ֶ��еľ����ļ�
�ɽ���ͷ�ļ�����������������ʵ����غ�������
*/


# include <stdio.h>
# include <myQueue.h>
# include <malloc.h>
# include <assert.h>
# define QUEUE_TYPE int	//@todoע�� 

/*
**front rear �ֱ�ָ����е�ͷ��β
**��ʼ��ʱֻҪ������пյ��������ɣ���һ��frontһ��Ϊ1,rearһ��Ϊ0,Ҳ����front=2 rear=1
*/
int front=1,rear=0;  

int QueueSize; //���е�����

QUEUE_TYPE * array; //@todo
/*
**�������ܣ���������
**˵����ֻ���ö�̬����ʵ�ֶ���ʱ���õ��ú���
*/
void  
create_Queue( unsigned size )
{
	QueueSize = size+1;//����������ѭ������ʵ�ֶ��У�������һ���ռ���Ų��ã�����ʹQueueSize=size+1 ��ʹ���������ĳ��Ⱦ���size
	array = ( QUEUE_TYPE * ) malloc( sizeof(QUEUE_TYPE) * QueueSize );
	/*
	**������д������ɹ�����˵��
	*/
	if( !array )
	{
		puts("��������δ�ɹ�");
	}
	
}

/*
**�������ܣ����ٴ�������ʱ��ռ�õ��ڴ�
**˵�����õ�������̬������ʽʵ�ֶ���ʱ�õ��ú������þ�̬����ʵ�ֶ���ʱ����Ҫ�ú���
*/
void
destroy_Queue( void )
{
	free( array );
	puts("�����ٶ���");

}

/*
**�������ܣ��ж϶����Ƿ�������������1 ����������0
*/
int
isFull_Queue()
{
	return (rear+2)%QueueSize == front;

}

/*
**�������ܣ��ж϶����Ƿ�Ϊ�գ����շ���1,���շ���0
*/
int
isEmpty_Queue()
{
	return (rear+1)%QueueSize == front;

}

/*
**�������ܣ���Ӳ���
*/
void
insert_Queue(QUEUE_TYPE value)
{
	/*
	**�����ֹ��createǰ���øú���
	*/
	if(!array)
	{
		puts("�������ö�̬����ʵ�ֶ��У����Բ�����create֮ǰ���ñ�����");
		assert(!array);
	}

	/*
	**��Ӳ��������ж϶����Ƿ�Ϊ�����粻�������
	*/
	if( isFull_Queue() )
	{
		puts("���������������ٽ�����Ӳ�����");
		return ;
	}
	else
	{
		rear = (rear+1)%QueueSize;
		array[ rear ] = value;
	}

}

/*
**�������ܣ����Ӳ���
**˵��������ĳ��Ӳ�����ָֻ����Ԫ�أ������ص�����Ԫ��ֵ
*/
void
delete_Queue()
{
	/*
	**�����ֹ��createǰ���øú���
	*/
	if(!array)
	{
		puts("�������ö�̬����ʵ�ֶ��У����Բ�����create֮ǰ���ñ�����");
		assert(!array);
	}

	/*
	**���Ӳ��������ж϶����Ƿ�Ϊ�գ��ٽ��г��Ӳ���
	*/
	if( isEmpty_Queue() )
	{
		puts("�����Ѿ����ˣ����ܽ��г��Ӳ���");
		return;
	}
	else
	{
		front = (front+1)%QueueSize;
	}

}

/*
**�������ܣ�ȡ�ö��еĵ�һ��Ԫ�أ�����һ��Ҫ���ӵ�Ԫ��ֵ
**˵����ֻȡ�ö��е�һ��Ԫ�أ��������г��Ӳ���
*/
QUEUE_TYPE first_Queue()
{
	/*
	**�����ֹ��createǰ���øú���
	*/
	if(!array)
	{
		puts("�������ö�̬����ʵ�ֶ��У����Բ�����create֮ǰ���ñ�����");
		assert(!array);
	}
	/*
	**���ж϶����Ƿ�Ϊ�գ�������˵��
	*/
	if(isEmpty_Queue())
	{
		puts("�����ѿ�");
		
	}
	else
	{
		return array[front];
	}
}