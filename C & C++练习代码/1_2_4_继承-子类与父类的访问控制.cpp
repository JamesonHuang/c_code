/*********************************************************************
	@ Title:		类的继承	

	@ Description:		1、类的访问控制

	@ Conclusion:		1、子类会创建父类的私有成员，但不可访问父类
				的私有成员，只能通过公有成员函数访问	

	@ Author:		rh_Jameson

	@ Date:			2014/07/24
**********************************************************************/
#include<iostream>
using namespace std;

//父类
class Father
{
public:
	int pubVar;
	
	//输出该类的私有成员变量
	void printPFVar()
	{
		pfVar = 111;
		cout << pfVar << endl;
	}

private:
	int pfVar;
};
//子类
class Son :public Father
{
public:
	void printFatherVar()
	{
		pubVar = 99;
		
		cout << pubVar << endl;
		printPFVar();
	}
};

class  base
  { public :
           int  a ,  b ;  
  } ;
class  derived : public  base
  { public :  
         int  b ,  c ; 
  } ;
void  f ()
{ derived  d ;
   d . a = 1 ;
   d . base :: b = 2 ;
   d . b = 3 ;
   d . c = 4 ;

   Son s;
	s.printFatherVar();
	s. Father :: pubVar = 22;

   cout<<"d.a = " << d.a << endl;
   cout<<"d.b = " << d.b << endl;
   cout<<"d.c = " << d.c << endl;

};



int main()
{
	
	//f();
	return 0;
}

