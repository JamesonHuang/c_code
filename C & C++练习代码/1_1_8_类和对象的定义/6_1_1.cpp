/*********************************************************************
	@title:			类和对象的定义

	@description:		1、类的声明中声明该类型指针

				2、一个类的例子

				3、写一个无名类

				4、写一个标准类（引入头文件，main直接调用）
				并用指针访问成员变量与函数

	@author:		rh_Jameson

	@date:			2014/07/21
**********************************************************************/
#include <iostream>
#include "PClass.h"

using namespace std;

//1、类的声明中声明该类型指针
class Link
{
	public:
		int node;
		Link *link; 
};

//2、一个类的例子
class Tdate
{  public:
        
		//设置年月日
		void  Set(int m, int d, int y )
		{ 
			month = m ;  
			day = d ; 
			year = y ; 
		}

		//判断是否为闰年
        int  IsLeapYear()
        { 
			return ( year % 4 == 0 && year % 100 != 0 )||( year % 400 == 0);
		}

		//输出年月日
        void  Print()  
		{ 
			cout << year << "." << month << "." << day << endl ; 
		}

   private:
        int  month, day, year;
};

//3、无名类
class
{
public:
	
	void init(int x,int y)
	{
		this -> x = x;
		this -> y = y;
	}
	void print()
	{
		cout<<"x="<<x<<","<<"y="<<y<<endl;
	}
private:
	int x, y;

}unknown;



int main()
{
	
//--------------------实现描述1----------------------//
	
	Link a;						//实例化对象a
	a.node = 10;
	a.link = new Link;			//new link返回一个指针

	cout<<"a node="<<a.node<<endl;
	cout<<"a link="<<a.link<<endl;

	
//--------------------实现描述2----------------------//
	cout<<endl<<endl;

	Tdate tdate;
	
	tdate.Set(7,21,2014);				//调用设置日期函数
	
	cout<<"设置日期为:";
	tdate.Print();					//打印日期

	cout<<endl;

	cout<<"该日期为闰年吗？\t"<<tdate.IsLeapYear()<<endl<<endl;			//判断是否为闰年


//--------------------实现描述3-----------------------//

	unknown.init(12,12);
	unknown.print();

//--------------------实现描述4-----------------------//
	PClass *p = new PClass;
	
	p->x=10;
	p->y=10;

	p->print();

	return 0;
}

