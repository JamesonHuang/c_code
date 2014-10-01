/**************************************************************************
	@ Title:		密文加密与解密	

	@ Description:		1、原文中每个字母用该字母之后的第五个字母替换
						
				2、原文字母都为大写
	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/07/29
***************************************************************************/

#include<iostream>
#include<string>
#define MAXSIZE 100

using namespace std;

char* chEncrypt(const char* str)
{
	
	char* res = new char[1];

	int len = strlen(str);
	for(int i =0; i < len; i++ )
	{
		res[i] = (str[i]+5 - 'A') % 26 + 'A';
	}
	return res;
}

void charEncriptFunc()
{
	char* enStr = (char *)malloc(sizeof(char));
	cout << "请输入待加密的原文：";
	cin >> enStr;
	
	char* res = (char *)malloc(sizeof(char));
	res = chEncrypt( enStr );

	cout << "加密后的密文为：" << res << endl;
}



string strEncrypt(string str)
{	
	string res = new char[1];

	int len = str.length();
	for(int i =0; i < len; i++ )
	{
		res[i] = (str[i]+5 - 'A') % 26 + 'A';
	}
	return res;
}

void strEncriptFunc()
{
	string enStr;
	cout << "请输入待加密的原文：";
	cin >> enStr;
	
	string res ;
	res = strEncrypt( enStr );

	cout << "加密后的密文为：" << res << endl;
}



int main()
{
	//charEncriptFunc();
	strEncriptFunc();
	return 0;
}