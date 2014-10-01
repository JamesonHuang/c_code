/*********************************************************************
	@ Title:			字符串转换函数	

	@ Description:		1、使用atoi，atof，itoa函数
						
				2、使用命令行参数

	@ Conclusion:		1、atoi：字符串转整型
				   atof：字符串转浮点
				   itoa：整型转字符串

				2、vs2010环境下itoa用不了~~

	@ Author:		rh_Jameson

	@ Date:			2014/07/25
**********************************************************************/


#include<iostream>
#include<cstdlib>
using namespace std;
#define MAXSIZE 200

//实现字符串转整型、浮点型
void strToIF (char* str,int intVar,float fVar)
{
	intVar = atoi (str);		//调用atoi函数
	fVar = atof (str);			//调用atof函数
	
	cout << "待转换字符串:" << str << endl;
	cout << "转换为整型：" << intVar << endl;
	cout << "转换为浮点型：" << fVar << endl;

}
//实现整型、浮点型转字符串
void IFToStr(char* str,int intVar,float fVar)
{
	//vs2010环境下使用不了
	itoa(intVar,str,10);		//转换为十进制整数
	//itoa(intVar,str,2);
	cout<< "转换后的字符串为：" << str <<endl;
}


int main()
{
	//定义相应变量
	char* str = ( char * ) malloc ( MAXSIZE * sizeof(char) );
	str = "123321.0123";
	int intVar = 999;
	float fVar = 0.000000;

	//实现字符串转整型、浮点型
	//strToIF(str,intVar,fVar);
	
	//实现整型、浮点型转字符串
	IFToStr(str,intVar,fVar);

	return 0;
}

//命令行参数
int main(int argc, char * argv[]) 
{ 
	for(int i = 0;i < argc; i ++ ) 
	{
		cout<<argv[i]<<endl;
	}
	return 0; 
}