/**************************************************************************
	@ Title:		二叉树	

	@ Description:		1、求二叉树任意两个结点间的共同父结点
	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/07/29
***************************************************************************/

#include<iostream>

using namespace std;

int main()
{
	int nodeA,nodeB;
	cout << "请输入二叉树中的两个结点：";
	cin >> nodeA >> nodeB;

	while( nodeA / 2 != nodeB / 2 )
	{
		nodeA /= 2;
		nodeB /= 2;
	}
	cout << " 共同父结点是："<< nodeA/2 <<endl;
	return 0;
}