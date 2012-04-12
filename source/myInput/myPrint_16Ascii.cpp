/*{create:2011年7月2日15时37分38秒}{last modify:2011年7月2日15时37分46秒}
**author:mang
**出自pointer on c 270-271页
**题目：将一个无符号数换成16进制的字符序列，并打印出来
*/

#include <stdio.h>


/*
接受一个整型值（无符号），把它转换为16进制的字符序列，并打印出来。前导零被去除
*/
void 
myPrint_16Ascii( unsigned int value )
{
	unsigned int quotient ; //quotient 是商是意思
	quotient = value / 16 ;
	if ( quotient != 0)
		myPrint_16Ascii( quotient );
	/*
	**由于在一些机器上字符与数字并不是邻的，下面的作法使字母和数字相邻，
	余数将从字符串中选择一个正确的字符
	*/
	putchar( "0123456789ABCDEF"[value % 16] );
}
/*说明
**若常量字符串出现在表达式中，其值是一个指针，指向第一个字符
程序最后一句就是"xyz"[2]的形式，即相当于字符z
而"xyz"+2 其结果是一个指针，指向字符z
*///~