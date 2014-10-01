/*********************************************************************
	@ Title:		inline函数调试

	@ Description:		1、测试inline函数能否调试

	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/09/07
**********************************************************************/

#include<iostream>
using namespace std;



//-------------1、测试inline函数能否调试-----------------//
inline void testInline()
{
	cout << "testInline" << endl;
}

int main()
{
	testInline();
	return 0;
}