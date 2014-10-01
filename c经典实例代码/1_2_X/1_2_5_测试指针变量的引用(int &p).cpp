/*********************************************************************
	@ Title:		测试指针变量的引用(int* &p)	

	@ Description:		1、测试指针变量的引用(int* &p)	
						
						

	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/08/09
**********************************************************************/

#include<iostream>
using namespace std;


//------------------1、测试指针变量的引用(int* &p)-------------------//
void testRefPointer()
{
	//普通指针、引用
	int iVar =10;
	int *ip = &iVar;
	int &refI = iVar;
	cout << "普通指针、引用：" << endl;
	cout << iVar << endl;
	
	cout << (ip == &refI) << endl;
	cout << ip << endl;
	cout << &refI << endl;

	cout << "指针变量的引用：" << endl;

	//指针变量的引用
	int iVarB = 20;
	int *iptr = &iVar;
	int *iptrA = iptr;
	int* &iptrB = iptrA;		//定义了一个指针变量的引用

	cout << *iptr << endl;
	cout << iptr << endl;

	cout << *iptrA << endl;
	cout << iptrA << endl;

	cout << *iptrB << endl;
	cout << iptrB << endl;
}

int refPtrFunc( int* &m, int* &n )
{
	return *m > *n ? *m : *n;
}

void testRefPtrByFunc()
{
	int m = 10, n = 20;
	
	int *mptr = &m;
	int* nptr = &n;
	int* &refNPtr = nptr;

	//cout << refPtrFunc( refNPtr, mptr ) << endl;
	cout << refPtrFunc( nptr, mptr ) << endl;
}




int main()
{
	testRefPtrByFunc();
	//testRefPointer();
	return 0;
}