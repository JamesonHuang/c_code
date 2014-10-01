/**************************************************************************
	@ Title:		斐波那契数列	

	@ Description:		1、数列第一个和第二个数都为1
					
				2、接下来每个数都等于前面两个数字之和
	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/07/29
***************************************************************************/

#include<iostream>

using namespace std;
int fin(int n)
{
	if( n == 1 || n == 2 )
	{
		return 1;
	}
	else
	{
		return fin( n - 1 ) + fin( n - 2 );
	}
}

int main()
{
	int n =fin(40);
	cout << n <<endl;
	return 0;
}