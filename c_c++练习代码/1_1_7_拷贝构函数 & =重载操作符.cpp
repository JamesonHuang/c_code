/*********************************************************************
	@ Title:		拷贝构函数 & =重载操作符	

	@ Description:		1、熟悉拷贝构造函数和copy assign操作符					
						
				2、测试返回外部指针或引用，用户使用
				外部指针改变内部数据以及解决方法

	@ Conclusion:			

	@ Author:			rh_Jameson

	@ Date:				2014/09/08
**********************************************************************/

#include<iostream>
using namespace std;


//-------------1、熟悉拷贝构造函数和copy assignment函数-----------------//
class Refer					//引用对象
{
public:	
	void setA(int a)
	{
		this->a = a;
	}
	int getA()
	{
		return a;
	}

	void setB(int b)
	{
		this->b = b;
	}	
	int getB()
	{
		return b;
	}
private:
	int a, b;
};

class Test
{
public:
	Test()
	{
	}
	~Test()
	{
	}
	Test(const Test &other)							//拷贝构造函数
	{
		cout << "这是拷贝构造函数" << endl;
		res = other.res;						//内置类型直接赋值
		r = other.r;							//应用对象直接赋值
		rr = new Refer();						//指针须重新分配一段空间，并逐一赋值
		rr->setA( other.rr->getA() );
		rr->setB( other.rr->getB() );
	}
	const Test & operator=(const Test &other)				//重载赋值操作符
	{
		cout << "这是重载复制操作符" << endl;
		res = other.res;
		r = other.r;
		rr = new Refer();
		rr->setA( other.rr->getA() );
		rr->setB( other.rr->getB() );
		return *this;
	}

	void setRes(int res)
	{
		this->res = res;
	}
	int getRes()
	{
		return res;
	}
	void setRefer(Refer r)
	{
		this->r = r;
	}
	Refer getRefer()
	{
		return r;
	}
	void setReferPointer(Refer* rr)
	{
		this->rr = rr;
	}
	//强烈警告：返部指针指向内部对象,外部指针可以改变private的数据
	Refer* getReferPointer()
	{
		return rr;
	}
	//解决之法
	Refer const * getReferP()
	{
		return rr;
	}
	

private:
	int res;
	Refer r;
	Refer *rr;

};

//测试复制构造函数和赋值操作符
void testCopyConstructorAssign()
{
	Refer r;							//定义refer对象，并初始化其成员变量
	r.setA(10);
	r.setB(20);

	Test source;							//定义源对象，并初始化
	source.setRes( 30 );
	source.setRefer( r );

	r.setA( 40 );
	r.setB( 50 );	
	source.setReferPointer( &r );	

	cout << "源对象的成员值是：" << endl;
	cout << "source.Res:" << source.getRes() << endl;

	cout << "source.getRefer.A:" << source.getRefer().getA() <<endl;
	cout << "source.getRefer.B:" << source.getRefer().getB() << endl;
	
	cout << "source.getReferPointer.A:" << source.getReferPointer()->getA() << endl;
	cout << "source.getReferPointer.B:" << source.getReferPointer()->getB() << endl;

	Test obj(source);
	//Test obj = source;						//调用拷贝构造函数
	//obj = source;							//调用赋值操作符，调用哪个函数取决于obj是否初始化		
	cout << "目标对象的成员值是：" << endl;
	cout << "obj.Res:" << obj.getRes() << endl;

	cout << "obj.getRefer.A:" << obj.getRefer().getA() <<endl;
	cout << "obj.getRefer.B:" << obj.getRefer().getB() << endl;
	
	cout << "obj.getReferPointer.A:" << obj.getReferPointer()->getA() << endl;
	cout << "obj.getReferPointer.B:" << obj.getReferPointer()->getB() << endl;


	cout << "改变obj对象的数据：" << endl;
	obj.setRes( 80 );
	r.setA( 90 );
	r.setB( 100 );
	obj.setRefer( r );
	r.setA( 110 );
	r.setB( 120 );
	obj.setReferPointer( &r );

	cout << "目标对象的成员值是：" << endl;
	cout << "obj.Res:" << obj.getRes() << endl;

	cout << "obj.getRefer.A:" << obj.getRefer().getA() <<endl;
	cout << "obj.getRefer.B:" << obj.getRefer().getB() << endl;
	
	cout << "obj.getReferPointer.A:" << obj.getReferPointer()->getA() << endl;
	cout << "obj.getReferPointer.B:" << obj.getReferPointer()->getB() << endl;


	//源对象和目标对像各对应一段空间，改变了目标对象的数据，不会影响到源对象的数据
	cout << "此时，源对象的成员值是：" << endl;

	cout << "源对象的成员值是：" << endl;
	cout << "source.Res:" << source.getRes() << endl;

	cout << "source.getRefer.A:" << source.getRefer().getA() <<endl;
	cout << "source.getRefer.B:" << source.getRefer().getB() << endl;
	
	cout << "source.getReferPointer.A:" << source.getReferPointer()->getA() << endl;
	cout << "source.getReferPointer.B:" << source.getReferPointer()->getB() << endl;

}

//-------------2、熟悉拷贝构造函数和copy assignment函数-----------------//
void testPointerChangeInternalData()
{
	Refer r;
	r.setA(10);
	r.setB(20);
	Test source;
	source.setRes( 30 );
	source.setRefer( r );

	r.setA( 40 );
	r.setB( 50 );	
	source.setReferPointer( &r );	

	cout << "改变前内部指针指向对象的数据：" << endl;
	cout << "source.getReferPointer().A: " << source.getReferPointer()->getA() << endl;
	cout << "source.getReferPointer().B: " << source.getReferPointer()->getB() << endl << endl;

	//强烈警告：返部指针指向内部对象
	Refer *t = source.getReferPointer();
	//const Refer *t = source.getReferP();						//解决方法
	t->setA( 60 );									//外部指针t改变指向对象的数据，内部指针rr指向的数据也跟着改变
	t->setB( 70 );
	cout << "外部指针t改变指向对象的数据:" << endl;
	cout << "t->A:" << t->getA() << endl;
	cout << "t->B:" << t->getB() << endl << endl;
	
	cout << "改变后内部指针指向对象的数据：" << endl;
	cout << "source.getReferPointer().A: " << source.getReferPointer()->getA() << endl;
	cout << "source.getReferPointer().B: " << source.getReferPointer()->getB() << endl;

}


int main()
{
	//testPointerChangeInternalData();
	testCopyConstructorAssign();
	return 0;
}
