/*********************************************************************
	@ Title:		c++ primer 习题测试	

	@ Description:		1、无符号溢出
						
				2、有符号溢出

	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/07/30
**********************************************************************/

#include<iostream>
using namespace std;


int main()
{
	//unsigned short usVar = 65537;			//无符号溢出，输出的数是当前数模2的n次方
	////int iVar = 10000000000;
	//int iVar = 2100000000;					//有符号溢出，是负数
	//cout << iVar << endl;
	//cout << usVar << endl;

	int v = 10;
	int * const cpi = &v;

	//cout <<  *cpi << endl;
	
	const char *cp = "hello";
	int cnt = 0;
	while( cp )
	{
		++cnt;
		++cp;
		cout << cnt << endl;
	}
	
	/*while( *cp )
	{
		++cnt;
		++cp;
	}*/

	return 0;
}