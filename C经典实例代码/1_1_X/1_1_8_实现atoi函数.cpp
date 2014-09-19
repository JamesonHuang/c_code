/********************************************************************************************
	@ Title:			实现atoi函数	

	@ Description:		1、测试系统自带的atoi函数
						
				2、自己实现atoi函数（注意负数）

	@ Conclusion:		1、实现函数的各种异常处理
					（1）判断字符串非空
					（2）注意去除空格
					（3）注意正负数处理
					（4）非整数型字符串的处理
				2、转换公式：
					（1）res += ( str[iterator] - '0' ) * pow(10.0,len-1-iterator);
					（2）res = res *10 + ( str[iterator] - '0' ); 

	@ Author:		rh_Jameson

	@ Date:			2014/07/30
*********************************************************************************************/

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//---------------------1、测试系统自带的atoi函数---------------------//
void sys_call_atoi()
{
	int atoiVar = atoi("-212");
	int atoiVar2 = atoi ( "+2111" );
	//int atoiVar3 = atoi ( "aaa");
	
	cout << atoiVar << endl;
	cout << atoiVar2 << endl;
	//cout << atoiVar3 << endl;
}


//------------------2、自己实现atoi函数（注意负数）-----------------------//
int myAtoi(const char* str)
{
	int len = strlen(str);							//字符串长度
	int res = 0 ;								//结果值

	int iterator =0;							//迭代器
	bool flag = false;							//正负数标志，false为正，true为负
	
	if(str == NULL)								//字符串为空时，返回0
	{
		return 0;
		cout << "字符串为空！" << endl;
	}
	if( *str == '-')							//字符串是负数，迭代器移动一位，再将正负数标志改为true
	{
		iterator++;
		flag = true ;
	}
	if( *str == '+' )							//字符串是正数，迭代器移动一位
	{
		iterator++;
	}

	for( ; iterator < len; iterator++ )
	{
		if(*(str + iterator) == ' ')			//跳过空格
		{
			continue;
		}
		if ( *(str + iterator) > '9' || *(str + iterator) < '0')
		{
			cout << "该字符串非整数字符串! " << endl;
			return 0;
		}

		/*str[iterator]是'1'，其实ascii码值为0x31，而'0'的ascii码是0x30，用str[i]-'0'就得到了1*/
		//res += ( str[iterator] - '0' ) * pow(10.0,len-1-iterator);
		res = res *10 + ( str[iterator] - '0' ); 
	}

	return res;
	
	
}

int main()
{

	//sys_call_atoi();
	
	char* str = (char *)malloc ( 10 * sizeof (char) );
	cout << "请输入整数字符串：";
	cin >> str;
	//str = "  1 2  3";
	int var = myAtoi( str );

	cout << "转为整数:" << var << endl;

	return 0 ;
}





