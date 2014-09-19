/*********************************************************************
	@ Title:		小白第一章	

	@ Description:		1、分离百位、十位、个位，反转三位数
						
				2、不用临时变量来交换变量

				3、三整数排序

				4、习题实验

	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/08/09
**********************************************************************/

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;


//----------------1、分离百位、十位、个位，反转三位数-----------------//
void reverseNum()
{
	//srand( (int)time(NULL) );
	//int num = rand()%10000;
	int num = 9876;
	cout << num << endl;
	
	//方法一：如果为520的话，该方法会逆转为025
	//cout << (num % 10) << (num / 10) % 10 << (num / 100) % 10 << (num / 1000) << endl;

	//方法二：相加，再输出
	int res = ( num % 10 ) *1000 + (num / 10) % 10 * 100 + (num / 100) % 10 * 10 + (num / 1000);
	cout << res << endl;

}

//---------------------2、不用临时变量来交换变量---------------------//
void swap(int &x, int &y)
{
	x = x + y;
	y = x - y;
	x = x - y;
}

//--------------------------3、三整数排序----------------------------//
void triSort(int a, int b, int c)
{
	int tmp = 0;
	if(a > b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	if(a > c)
	{
		tmp = a;
		a = c;
		c = tmp;
	}
	if(b > c)
	{
		tmp = b;
		b = c;
		c = tmp;
	}
	cout << a << "\t" << b << "\t" << c << endl;
}

//----------------------------4、习题实验----------------------------//
void testExp()
{
	//cout << -111111 * 111111 << endl;

	cout << sqrt( -10.0 ) << endl;
}
//-------------2、实现每输出10个元素，就换行，再输出-----------------//


int main()
{
	//reverseNum();

	/*int x =10, y = 20;
	swap(x, y);
	cout << x << endl;
	cout << y << endl;*/
	
	//triSort(90, 29,22);

	testExp();
	return 0;
}