/*create:2011年6月7日11时37分26秒 last modify:2011年6月7日11时37分31秒
*author:mang	
*/

#include <stdio.h>
#include <string.h>

/*该题出自c和指针 181页
**my_strrstr()函数实现在一个字符串中查找子字符串最后出现的位置，其结果返回指针。
**s1为指向主字符串的指针即指向被查找的字符串的指针，s2为指向子字符串的指针
**/
char* 
myStrrStr(char const *s1,char const *s2)
{
	char *last;
	char *current;

	//把指针初始化为我们已经找到的前一次匹配位置
	last = NULL;

	//只在第二个字符串不为空时才进行查找，如果s2为空，返回NULL
	if( *s2 != '\0')

		/*
		**查找s2在s1中第1次出现的位置
		*/
		current = strstr( s1 , s2 );
		
		while( current !=NULL )
		{
			/*
			**我们每次找到字符串时，让指针指向中它的起始位置。然后查找该字符串下一个匹配位置
			*/
			last = current;
			current = strstr( last +1, s2);
		}
		
		/*
		**返回指向我们找到的最后一次匹配的起始位置的指针
		*/
		return last;



}
/*output:自已运行吧
*
*///~
