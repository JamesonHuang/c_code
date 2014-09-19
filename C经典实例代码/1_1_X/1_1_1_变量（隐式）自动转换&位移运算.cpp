/*********************************************************************
	@title:			变量（隐式）自动转换&位移运算

	@description:		1、int型变量赋值给char型变量
				2、浮点型与整型之间的运算、转换
				3、左、右移运算

	@author:		rh_Jameson

	@date:			2014/07/22
**********************************************************************/
#include<iostream>
using namespace std;


//----------------1、int型变量赋值给char型变量----------------------//
void intToChar()
{
	int in = 1378;
	char c = in;				//赋值过程中，int发生自动转换，丢弃整型的高3字节，留下最低字节							

	cout << (int)c << endl;			//结果为98，b，
	cout << c << endl;			//过程：1378,16进制下是0x00000562，留下低八位，即0x62，0x62换回十进制则为98
}


//----------------2、浮点型与整型之间的运算、转换------------------//
void intConvertDouble()
{
	int a = 10, b = 3;
	
	double	c = a / b,					//c=3
		d = 5 / 2,					//d=2
		e = 5 / 2.0,					//e=2.5
		f = ( double )a / b;				//f=3.33333

	//输出
	cout<<"c="<<c<<endl;
	cout<<"d="<<d<<endl;
	cout<<"e="<<e<<endl;
	cout<<"f="<<f<<endl;
}

//------------------3、左、右移运算--------------------------------//
/*
	(0)注意负数的补码形式求值，求反码时，符号位不变
	(1)左移时，符号位会被丢弃,每左移一位，最低位补0
	(2)右移时，符号位不变,根据符号的值，来确定补0还是补1
*/

//左移运算
void leftShift()
{
	char v1_lf = 0xff,					//= -1				！注意负数的补码形式求值，求反码时，符号位不变
		 v2_lf = 0x0f,					//= 15
		 v3_lf = 0x00,					//= 0
		 v4_lf = 0xf0;					//= -16				！注意负数的补码形式求值...
	
	v4_lf <<= 4;						//=0				！左移时，符号位会被丢弃
	v2_lf <<= 4;						//=-16
	
	v1_lf = 0x7f;						//=127
	v1_lf <<=1;							//=-2

	cout<<"v1_lf="<<(int)v1_lf<<endl;
	cout<<"v2_lf="<<(int)v2_lf<<endl;
	cout<<"v3_lf="<<(int)v3_lf<<endl;
	cout<<"v4_lf="<<(int)v4_lf<<endl;
}

//右移运算
void rightShift()
{
	char v1_rf = 0xff,					//= -1				！注意负数的补码形式求值，求反码时，符号位不变
		 v2_rf = 0x0f,					//= 15
		 v3_rf = 0x00,					//= 0
		 v4_rf = 0xf0;					//= -16				！注意负数的补码形式求值...
	
	v4_rf >>= 4;						//= -1				!右移时符号位不变,根据符号的值，来确定补0还是补1
	v2_rf >>= 1;						//=7


	cout<<"v1_rf="<<(int)v1_rf<<endl;
	cout<<"v2_rf="<<(int)v2_rf<<endl;
	cout<<"v3_rf="<<(int)v3_rf<<endl;
	cout<<"v4_rf="<<(int)v4_rf<<endl;
}


int main()
{
	//intToChar();
	//intConvertDouble();
	//leftShift();
	rightShift();
	return 0;
}


