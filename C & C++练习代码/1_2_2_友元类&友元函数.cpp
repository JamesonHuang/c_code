/*********************************************************************
	@ Title:		友元函数、友元类	

	@ Description:		1、建立一个友元函数、友元类
						
				2、通过友元访问源类的private成员
						

	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/07/21
**********************************************************************/

#include <iostream>

using namespace std;

//源类
class MyClass
{
public:
	int pubX, pubY;					//公有成员变量
	
	//声明该类的友元类，不管是public还是private下，都生效
	friend class FriendClass;

	//MyClass(int X):pubY(X){}			//构造函数初始化

	//设置公有成员变量pubX、pubY
	void setPubX ( int X )				
	{
		this -> pubX =X;
		cout<<"This is setPubX, PubX = "<<(this -> pubX)<<endl;
	}
	void setPubY ( int Y )
	{
		this -> pubY = Y;
		cout<<"This is setPubY, PubY = "<<(this -> pubY)<<endl;
	}

	//设置私有成员变量priX，priY
	void setPriX ( int X )				
	{
		this -> priX =X;
		cout<<"This is setPriX, PriX = "<<(this -> priX)<<endl;
	}
	void setPriY ( int Y )
	{
		this -> priY = Y;
		cout<<"This is setPriY, PriY = "<<(this -> priY)<<endl;
	}

	friend void friFunc(MyClass &p);		//声明友元函数
	//void friFunc(MyClass &p);				//未声明友元函数时，友元函数定义无法访问

private:
	int priX,priY;					//私有成员变量
	
	//私有操作
	void priFunc()
	{
		cout<<"这是私有操作函数"<<endl;
	}
};

//友元函数定义
void friFunc(MyClass &p)
{
	p.priX = 10;
	
	cout<<"priX:"<< p.priX <<endl;
	
}

//非友元类，但有友元函数
class NFriendClass
{
public:
	MyClass mc;
	void printXY()
	{
		/*    通过函数获取公有、私有成员，均成功    */
		mc.setPubX(10);		
		mc.setPubY(20);
		mc.setPriX(30);
		mc.setPriY(40);


		//直接获取成员变量，公有成员变量获取成功，但私有成员则失败
		cout<<"直接获取PubX："<<mc.pubX<<endl;
		cout<<"直接获取PubY："<<mc.pubY<<endl;
		
		/*
		cout<<"直接获取PriX："<<mc.priX<<endl;			//提示PriX不可访问
		cout<<"直接获取PriY："<<mc.priY<<endl;
		mc.priFunc();
		*/		
		
	}


};

//友元类
class FriendClass
{
public:
	MyClass mc;
	void printXY()
	{
		/*    通过函数获取公有、私有成员，均成功    */
		mc.setPubX(10);		
		mc.setPubY(20);
		mc.setPriX(30);
		mc.setPriY(40);


		//直接获取成员变量，公有、私有成员变量获取成功
		cout<<"直接获取PubX："<<mc.pubX<<endl;
		cout<<"直接获取PubY："<<mc.pubY<<endl;
		
		
		cout<<"直接获取PriX："<<mc.priX<<endl;			//成功访问私有成员变量
		cout<<"直接获取PriY："<<mc.priY<<endl;
		
		cout<<endl;

		mc.priFunc();						//通过友元访问元类的私有函数
	}
};



int main()
{
	//操作非友元类	
	NFriendClass nfc;
	nfc.printXY();
	
	

	//操作友元类
	FriendClass fc;
	fc.printXY();
	
	//操作友元函数
	MyClass mc;
	friFunc(mc);

	return 0;
}