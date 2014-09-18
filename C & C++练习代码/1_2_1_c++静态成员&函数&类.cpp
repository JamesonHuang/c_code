/***********************************************************************************
	@ Title:		静态成员&函数&类

	@ Description:		1、定义类的静态成员、静态函数
				2、测试是否存在静态类

	@ Conclusion：		1、类中声明静态变量后，一定要在类外初始化他，否则报错
				（也不可以在类中初始化)
						
				2、在静态函数中设置非静态变量的话，须指定具体对象
				（编译器需要知道该非静态变量属于哪个对象）

				3、在C++中，可以对类声明static，但对其进行访问会出错，
				结合网上的一些观点，c++中应该没有静态类该说法，只
				存在与Java与C#中。

				4、c#/Java中的静态类概念：
					（1）仅包含静态成员
					（本程序测试：c++的“静态类”中成员不会自动转成静态成员）
							
					（2）不能实例化

	@ Author:		rh_Jameson

	@ Date:			2014/07/23
**************************************************************************************/
#include <iostream>

using namespace std;


//----------------1、定义类的静态成员、静态函数-----------------------//
class SClass
{	
public:
	
	//静态函数设置静态变量
	static void setStaticVar(int x)
	{
		s = x;
		cout << "This is a static func" << endl;
	}
	
	//静态函数设置非静态变量，须指定具体对象，否则报错
	static void setVar(int x,SClass *ptr)
	{
		ptr-> ns = x;
	}

	static int s;	//静态变量 s

	int ns;			//非静态变量 ns
};
int SClass :: s = 10;			//静态成员变量必须初始化，否则报错

/*类外定义静态函数*/
//void SClass :: setVar(int x,SClass *ptr)
//{
//	ptr-> ns = x;
//}


//-----------------------------2、静态类测试---------------------------------//
static class StaticClass
{	
public:
	
	
	static void setStaticVar(int x)
	{
		s = x;
		cout << "This is a static func:" << s << endl;
	}
	
	static int s;			
};







int main()
{

//-----------------------静态函数，静态成员-------------------------------//
	/*
		SClass sc;
		sc.set(10);
		cout<<"s = "<<sc.s<<endl;
	*/
	
	//测试不new情况下，是否可以访问指针对象			结果：Debug Error
	//SClass *p ;

	SClass *p = new SClass();

	p -> setStaticVar ( 15 );		//s = 15
	p -> setVar ( 13, p );			//ns = 13
	

	cout << "s=" << p->s << endl;
	cout << "ns=" << p->ns << endl;


//--------------------------静态类测试----------------------------------//
	/*
		StaticClass.s=10;
		StaticClass.setStaticVar(111);
	*/
	return 0;
}