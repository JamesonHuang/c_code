/*********************************************************************
	@ Title:		虚基类-虚函数-纯虚函数

	@ Description:		1、比较基类、虚基类

				2、比较函数、虚函数


	@ Conclusion:			

	@ Author:			rh_Jameson

	@ Date:				2014/07/29
**********************************************************************/

#include <iostream>
using namespace std;
//-----------------------1、比较基类、虚基类--------------------------//

/*不适用虚基类的情况下*/
class A
{
public:
    int iValue;
};

class B:public A
{
public:
    void bPrintf(){cout<<"This is class B"<<endl;};
};

class C:public A
{
public:
    void cPrintf(){cout<<"This is class C"<<endl;};
};

class D:public B,public C
{
public:
    void dPrintf(){cout<<"This is class D"<<endl;};
};





/*使用虚基类的情况*/
//class A
//{
//public:
//    int iValue;
//};
//
//class B:virtual public A
//{
//public:
//    void bPrintf(){cout<<"This is class B"<<endl;};
//};
//
//class C:virtual public A
//{
//public:
//    void cPrintf(){cout<<"This is class C"<<endl;};
//};
//
//class D:public B, public C
//{
//public:
//    void dPrintf(){cout<<"This is class D"<<endl;};
//};


int main()
{
	D d;

	d.A::iValue = 10;
	d.B::iValue = 20;
	d.C::iValue = 30;
    
	//cout<<d.iValue<<endl; //错误，不明确的访问
    cout<<d.A::iValue<<endl; //正确
    cout<<d.B::iValue<<endl; //正确
    cout<<d.C::iValue<<endl; //正确


	return 0;
}