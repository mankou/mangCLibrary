/*
**{create:2011��7��6��11ʱ42��37��}{last modify:2011��7��6��11ʱ42��41��}
**author:mang 
*/


/* ��������͵Ķ��������˼�����ѽṹ�����͵Ķ�����typedef������һ��
���ڽṹ���еĳ�Ա������ָ������ͽṹ���ָ�룬��������һ����ʱ������
Node_tag,��������������ˣ�������÷������ߣ���һ��������һ���ṹ��Ķ��壬
�ڶ���typedef */
/*
**����һ���ṹ�����ͣ�������Ŀǰ���ڵ�����ṹ
myInsertToSingleList()���� myPrintSingleList()���������õ������������
*/
typedef struct Node_tag
{
	int value;
	struct Node_tag *next;

}SingleListNode ;