/*{create:2011��6��15��11ʱ09��13��}{last modify:2011��6��15��11ʱ09��19��}
**author:mang
**��������c��ָ��133ҳ ����7.8b ,�������ҵĺ�����myLib.lib
**��Ŀ���õ������������n���Ʋ���������ֵ
*/


#include <stdio.h>

/*
**�õ����ķ�������n���Ʋ���������ֵ
ע��ú������ֻ�ܼ��㵽��48����
*/
long 
myFibonacci( int n )
{
	/*
	**������̽����� next_older_reslut  previous_result result  ��˳����ǰ�ƽ�
	*/
	long result;
	long previous_result;
	long next_older_result;

	/*
	**�ú������ֻ�ܼ��㵽��48����,���������������жϣ�������48�򲻽��м���
	*/
	if( n>48 )
	{
		printf("�ú������ֻ�ܼ��㵽��49���Ʋ���������������������ҵļ��㷶Χ���ҽ��Զ�����0\n");
		return 0;
	
	}

	result = previous_result = 1;

	while( n>2 )
	{
		n -= 1;
		next_older_result = previous_result;
		previous_result = result;
		result = previous_result + next_older_result;
			
	}
	return result;

}
/*
*///~
