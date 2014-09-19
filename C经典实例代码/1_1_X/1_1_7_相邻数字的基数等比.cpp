/**************************************************************************
	@ Title:			相邻数字的基数等比：确定进制	

	@ Description:		1、读入三个整数p、q和r，求出一个进制B，使得在B进制下，
						p * q = r：
					（1）如果有多个进制符合，选最小进制
					（2）进制取值范围2-16		
	@ Conclusion:

	@ ExtendedProblem:	1、字符指针能自动扩容？有何后遗症吗？

				2、通过字符指针访问字符串内容的形式有哪些？

				2.5、字符指针*s指的是整个字符串，那我想访问
					第一个字符该咋办？

						

	@ Author:			rh_Jameson

	@ Date:				2014/07/29
***************************************************************************/

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

#define MaxSize 10

//---------------------------1、读入三个整数p、q和r，求出一个进制B，使得在B进制下，p * q = r：--------------------------//

//将字符数组中的数转为十进制整数				记号3：实现字符数组转为整数(负数),以及对atoi函数的测试
int ch2Ten(char* s,int radix)
{
	int len = strlen(s);
	int tmp = 0;
	int res = 0;
	
	for( int i = 0; i <= len-1; i++ )					//逐个字符获取，并将该字符转换为十进制数字，加到res上，最后得到该字符串的十进制整数
	{
		//tmp = s[i]-'0';						//记号1：s[i]的另一种表示
		tmp = *(s+i) - '0';
		if ( tmp >= radix )
		{
			return -1;
		}
		//tmp *= pow((double)radix,( len-1-i ) );
		//res += tmp;
		res += ( int )tmp * pow((double)radix, ( len-1-i ) );		//例：ch2Ten ( "9", 2 ), 则 res = 9 * 2^0 =9;
	}
	return res;
}

//遍历2-16进制，找出符合条件的进制，并返回
int cal ( char* p,char* q, char* r )
{
	int TenP,TenQ,TenR;							//用来保存从字符数组中取来的十进制整数
	for(int i = 2; i <= 16; i++ )
	{		

		if( ( TenP = ch2Ten ( p, i ) ) == -1 ||				//如果特定进制下，该字符数组无法转为十进制整数，返回-1
			( TenQ = ch2Ten ( q, i ) ) == -1 ||			//p，q，r任一数等于-1，跳出循环
			( TenR = ch2Ten ( r, i ) ) == -1 )
		{
			continue;
		}
		if(TenR == TenP * TenQ)						//满足 p * q = r的，返回该进制数
		{
			return i;
		}
	}
	return 0;
}

//主处理程序
void func1()
{
	cout << "程序说明：读入三个整数p、q和r，求出一个进制B，使得在B进制下，p * q = r" << endl;
	cout << endl ;

	char *p = new char[MaxSize],			//记号2：字符指针会自动扩容吗？有何后遗症吗？
		 *q = new char[MaxSize],
		 *r = new char[MaxSize];
	
	cout << "请输入p，q，r的值（格式：p q r）：" ;
	cin >> p >> q >> r;
	
	int radix = cal(p,q,r);  //返回符合要求的进制	
	if(radix != 0)
	{
		cout << "符合要求的进制是：" << radix << endl;
	}
	else
	{
		cout <<"无符合要求的进制!" << endl;
	}
}


//-----------------------------ExtendedProblem:	1、字符指针能自动扩容？有何后遗症吗？----------------------------------//
void ex_pro_pointerToChar()
{
	char* ptr = new char[2];
	
	ptr = "pointer to char!";		//初始化时，分配两个char的空间，但字符串已经超出越界，但依然可以输出
						//该变量所在内存空间之后如果无敏感数据，输出正常，如果有的话，将会导致未知后果！

	cout << ptr << endl;
}

//----------------------------ExtendedProblem:2、通过字符指针访问字符串内容的形式有哪些？------------------------------//
//---------------------------2.5、字符指针*s指的是整个字符串，那我想访问第一个字符该咋办？-----------------------------//
void ex_pro_p2ch_read()
{
	char* str = "abcdefgh";
	char str2[] = "helloworld";

	int len = strlen ( str );
	int len2Arr =strlen ( str2 );

	for(int i = 0; i < len; i++)
	{
		//cout << str[i];
		cout << *(str + i);			//如果str是字符数组的话，不可以使用该方式访问元素，只能通过下标方式	
	}
	
	for(int j = 0; j < len2Arr; j++)
	{
		//cout << str2[j];
		cout << *( str2 + j );			//如果str是字符数组的话，不可以使用该方式访问元素，只能通过下标方式
							//但vs2010环境下，可以输出,无错误，无警告！！
	}

	//cout << str << endl;				//输出字符串所有元素
	//cout << *str << endl ;			//输出字符串第一个元素
	//cout << ( str + 1 ) << endl;			//输出出第一个元素外的其他元素
	cout << endl;

	char** pptr = &str;
	cout << pptr <<	endl;
	cout << *pptr << endl;
}



int main()
{
	//func1();					//实现描述1问题
	//ex_pro_pointerToChar();			//实现扩展问题1
	ex_pro_p2ch_read();
	return 0;
}
