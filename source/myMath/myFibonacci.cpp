/*{create:2011年6月15日11时09分13秒}{last modify:2011年6月15日11时09分19秒}
**author:mang
**该例出自c和指针133页 程序7.8b ,现纳入我的函数库myLib.lib
**题目：用迭代方法计算第n个菲波那契数的值
*/


#include <stdio.h>

/*
**用迭代的访求计算第n个菲波那契数的值
注意该函数最多只能计算到第48个数
*/
long 
myFibonacci( int n )
{
	/*
	**计算过程将按照 next_older_reslut  previous_result result  的顺序向前推进
	*/
	long result;
	long previous_result;
	long next_older_result;

	/*
	**该函数最多只能计算到第48个数,所以在这里做了判断，若大于48则不进行计算
	*/
	if( n>48 )
	{
		printf("该函数最大只能计算到第49个菲波那契数，你的数超过了我的计算范围，我将自动返回0\n");
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
