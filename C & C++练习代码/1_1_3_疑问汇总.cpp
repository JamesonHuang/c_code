/*********************************************************************
	@ Title:		疑问汇总	

	@ Description:		1、try/catch/throw异常处理
						
				2、typedef的四个用途和两个陷阱

				3、枚举类型与int的恩怨

				4、new delete malloc free
				
				5、野指针、悬垂指针、智能指针

				7、指针传递，操作指针本身测试

	@ Problem:		1、vs2010为什么可以在不包含stdlib的情况下
				使用malloc？（类似的，很多都库函数也是这样）			

	@ Author:		rh_Jameson

	@ Date:			2014/08/04
**********************************************************************/

#include<iostream>
#include<exception>
#include<string>

#include <memory>				//使用智能指针用到

using namespace std;


//---------------------1、try/catch/throw异常处理----------------------//
//方式一：主动抛出，主动写catch捕捉
double divide(double x,double y)
{
	int e = 1;
	if( y == 0)
	{
		//throw y;			//抛出异常y，如果没有相应的catch捕捉，会报错！
		//throw "error";		//只能跑出一个异常，默认是第一个异常
		throw e;			//抛出catch中未直接声明的类型，默认用catch（...）捕捉

							/*当我们在自己定义的函数中抛出(throw)一个异常对象时，如果
							此异常对象在本函数定义，那么编译器会拷贝此对象到某个特定的
							区域。因为当此函数返回时，原本在该函数定义的对象空间将被释放，
							对象也就不存在了。编译器拷贝了对象，在其他函数使用catch语句
							时可以访问到该对象副本*/
	}
	else
		return x / y;
	
}
void TestExceptionWayOne()
{
	double x = 10,y = 0;
	
	try
	{
		cout << divide(x,y) << endl;
	}
	catch(double e)						//对应throw y
	{
		cout <<"出现double y异常！" << endl;
	}
	catch(char *str)					//对应throw "error"
	{
		cout << "出现string 异常！" << endl;
	}
	catch(...)
	{
		cout << "出现未知异常" << endl;
	}
	
}

//方式二：自定义异常类来处理
class myException : public exception
{
public:
	const char* what() const throw()			//throw()在这里是什么作用？相当于Java中的throws？
	{
		return "My Exception!!!";
	}

	
};
void testExceptionWayTwo()
{
	myException me;
	try
	{
		//throw me;
		throw myException();	//直接抛出
	}
	catch(myException& e)		//错误信息e使用派生类myException
	{
		cout << "自定义异常捕捉成功！异常信息是：" << "\t";
		cout << e.what() << endl;
	}
	//catch(exception& e)		//错误信息e使用基类exception，与前者结果一致
	//{
	//	cout << "自定义异常捕捉成功！异常信息是：" << "\t";
	//	cout << e.what() << endl;
	//}
}

//方法三：使用标准异常处理
void testException()
{
	exception e;
	try
	{
		throw e;
	}
	catch(exception &e)
	{
		cout << "调用标准异常,异常信息是：\t" << e.what() <<endl; 
	}
}


//---------------------2、typedef的四个用途和两个陷阱----------------------//

//用途一：定义一种类型的别名，而不只是简单的宏替换
typedef int INT;

/*用途二：	标准C中，声明struct新对象时，必须要带上struct，
*			使用typedef，可以省掉struct，与定义基本数据类型一致。
*			但该用途已成鸡肋，因为c++中可以不带上struct了
*/
struct point
{
	int a;
	double b;
};
typedef struct					//加不加结构名，都可以
{
	int a;
	int b;
} line;

//用途三：定义数组别名，注意格式，好奇葩~~么么哒！
typedef int int_arr_10[10];
typedef int int_arr_100[100];

//用途四：为函数指针定义新的名称：typedef int (*MyFUN)(int a，intb);
//type (*)(....)函数指针
//type (*)[]数组指针


//陷阱一：非简单的宏替换
#define DF_INTPTR int*
typedef int* TYPE_INTPTR; 

void testTypedef()
{	
	//用途一：
	INT val = 100;
	//unsigned INT valA = 100;				//不可以这样写，原因不明，我猜：typedef int INT;该语句已经把INT定义成int型了

	cout << val << endl;
	//cout << valA << endl;


	//用途二:对比
	//point AA;								//c++中可以这样定义结构体对象，但标准C中必须struct point AA！
	struct point AA;		
	AA.a = 10;
	AA.b = 22;
	cout << AA.a << "\t" << AA.b << endl;
	
	line BB;
	BB.a = 99;
	BB.b = 88;
	cout << BB.a << "\t" << BB.b << endl;


	//用途三：
	int_arr_10 arr;
	int_arr_100 arr_100;

	for(int i = 0; i < 10; i++ )
	{
		arr[i] = i;
		arr_100[i] = i;
		cout << arr[i] << endl;
		cout << arr_100[i] << endl;
	}

	//陷阱一：
	DF_INTPTR p1,p2;						//定义了一个指针p1,一个变量p2,等价于int *p1,p2;
	TYPE_INTPTR p3,p4;						//定义了两个指针p3，p4，等价于int *p3, *p4;

	//陷阱二:
	int varA = 11,varB = 22;

	const DF_INTPTR p5 = &varA;				//常量指针，等价于const int* p5 = &varA;	const修饰的是指针指向的对象
	const TYPE_INTPTR p6 = &varB;			//指针常量，等价于int* const p6 =　&varB，	因为const修饰的是指针本身
	TYPE_INTPTR const p7 = &varB;			//指针常量，等同p6

}




//-----------------------3、枚举类型与int的恩怨-------------------------//
void testEnum()
{
	enum color{red, green, blue};
	//color c = 1 ;								//c编译器可以通过，自动转换成green
	color c = green;
	c = color( 2 );								//int转为color型
	int greenVar = green;

	cout << greenVar << endl;
	cout << c <<endl;
}


//-----------------------4、new delete malloc free-----------------------//

//--------------------5、野指针（悬垂指针）、智能指针----------------------//
/*	维基百科：野指针==悬垂指针==迷途指针
*	另一说法：	野指针：	声明，但未初始化的指针
*				悬垂指针：	指针指向的空间已被释放，而指针未被NULL
*
*	Java语言，悬垂指针这样的错误是不会发生的
*
*	c++防止悬垂指针的方法：
*		（1）不用默认拷贝构造函数，自己写一个		——值型的方式管理
*		（2）使用智能指针							——使用引用计数
*/
class Point
{
public:
	int x,y;
};

//使用智能指针share_ptr
void testShare_ptr()						//测试不了，vs2010库中木有文件boost，须安装~~
{
	//share_ptr<int> ip( new int );
	//*ip = 11;
	//cout << *ip << endl;
}


//使用智能指针auto_ptr、unique_ptr
void testSmartPointer()
{
	/*Point *pp = new Point();							//普通指针定义方式
	pp->x = 10;
	pp->y = 100;*/

	auto_ptr<Point> ptr ( new Point() );				//智能指针定义方式
	ptr->x = 10;
	ptr->y = 20;

	//auto_ptr<Point> ptrA(ptr);							//将ptr的空间给了ptrA，ptr变空
	auto_ptr<Point> ptrA = ptr;							//将ptr的空间给了ptrA，ptr变空
	
		
	//cout << ptr->x << endl;
	cout << ptrA->x << endl;
	
	ptr.release();										//相当于delete、free，释放空间
	if(ptr.get() == NULL)								//判断指针是否为空
	{
		cout << "智能指针ptr已经销毁" << endl;	
	}
	/*unique_ptr<int> ptr ( new int() );
	*ptr =10;
	unique_ptr<int> ptrA = move( ptr );
	cout << *ptrA << endl;
	cout << *ptr << endl;*/
}

void testWildPointer()
{
	Point a;
	a.x = 10;
	a.y = 20;
	
	Point b = a;					//对象拷贝，此时对象b会另外开辟一块空间，
									//将a中数据拷贝到该空间中

	cout << &a << endl;
	cout << &b << endl;

	Point *pp = new Point();
	pp->x = 10;
	pp->y = 100;

	Point *cp = pp;					//对象拷贝，此时对象b和对象a在内存中共享同一块空间
	cout << pp << endl;
	cout << cp <<endl;
}


//malloc/free、new/delete正确的分配、释放方式
void testPointer()
{
	//malloc/free正确分配、释放方式
	/*int *p = (int *) malloc(10 * sizeof( int ) );
	for ( int i = 0; i < 10; i++ )
	{
		*( p + i ) = i;
		cout << *( p + i ) << endl;
	}
	free(p);
	p = NULL;*/												//没有这句，p将成为野指针

	//new/delete正确分配、释放方式
	int *q = new int[10];
	for ( int j = 0; j < 10; j++ )
	{
		* ( q + j ) = j;
		cout << * ( q + j ) << endl;
	}
	delete []q;
	q = NULL;												//没有这句，q将成为野指针
	cout << q << endl;

	if ( q == NULL )
	{
		cout << "q指针已经销毁" << endl;
	}



}


//------------------7、指针传递，操作指针本身测试----------------------//
//版本一:
//void GetMemoryA( char* &p)					//指针别名，同一指针
void GetMemoryA( char* p)						//指针副本
{
	p = (char *)malloc(100 * sizeof( char ));
}
void testGetMemoryA() 
{
	char* str = NULL;
	GetMemoryA( str );						//实际上并没有获取到内存空间，在这里，指针成了操作对象，但操作完，返回调用函数时，就不存在了
	strcpy( str, "hello world" );
	cout << str << endl;
  
}
//版本二:
void GetMemoryB( char **p, int num )
{
	*p = (char*) malloc(num);
	if(*p==NULL)
	{
	/*处理代码*/
	}
}
void testGetMemoryB()
{
	char *str = NULL;
	GetMemoryB( &str, 100 );				//该版本可以获取到内存空间，因为这里传的是指针的指针，函数调用完，指针的指针没了，但指针仍存在
	strcpy( str, "hello" );
	cout << str << endl;
}


int main()
{
	//testDynamicAssign();
	//testShare_ptr();
	testGetMemoryA();
	//testEnum();
	//testTypedef();
	//TestExceptionWayOne();
	return 0;
}