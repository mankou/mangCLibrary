/*create:2011��6��7��11ʱ37��26�� last modify:2011��6��7��11ʱ37��31��
*author:mang	
*/

#include <stdio.h>
#include <string.h>

/*�������c��ָ�� 181ҳ
**my_strrstr()����ʵ����һ���ַ����в������ַ��������ֵ�λ�ã���������ָ�롣
**s1Ϊָ�����ַ�����ָ�뼴ָ�򱻲��ҵ��ַ�����ָ�룬s2Ϊָ�����ַ�����ָ��
**/
char* 
myStrrStr(char const *s1,char const *s2)
{
	char *last;
	char *current;

	//��ָ���ʼ��Ϊ�����Ѿ��ҵ���ǰһ��ƥ��λ��
	last = NULL;

	//ֻ�ڵڶ����ַ�����Ϊ��ʱ�Ž��в��ң����s2Ϊ�գ�����NULL
	if( *s2 != '\0')

		/*
		**����s2��s1�е�1�γ��ֵ�λ��
		*/
		current = strstr( s1 , s2 );
		
		while( current !=NULL )
		{
			/*
			**����ÿ���ҵ��ַ���ʱ����ָ��ָ����������ʼλ�á�Ȼ����Ҹ��ַ�����һ��ƥ��λ��
			*/
			last = current;
			current = strstr( last +1, s2);
		}
		
		/*
		**����ָ�������ҵ������һ��ƥ�����ʼλ�õ�ָ��
		*/
		return last;



}
/*output:�������а�
*
*///~
