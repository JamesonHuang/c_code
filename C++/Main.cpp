/*********************************************************************
	@ Title:		c++ primer 1-2章测试代码

	@ Description:		1、测试cerr/clog/cout
						
				2、直接初始化

				3、测试引用

				4、测试字符串是深拷贝还是浅拷贝

				5、testFOR ++i

	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/08/02
**********************************************************************/

#include <iostream>
#include <string>
using namespace std;

//---------------------1、测试cerr/clog/cout-------------------------//
void testCerrClogCout()
{
	cout << "该行由cout输出" << endl;
	cerr << "该行由cerr输出" << endl;
	clog << "该行由clog输出" << endl;

	//奇葩格式
	cout << "helloworld " "helloworld " "osijdfioja" <<endl;
	cout << "hi!" << endl;

	cout << "/*";
	cout << "*/ ";
	//cout << /* "*/" */ ;
	cout <<  /* "*/" */ ";

}

//----------------------2、直接初始化-------------------------//
void initial()
{
	//初始化并不一定是赋值！
	int val(10);
	cout<< val << endl;
}

//-----------------------3、测试引用----------------------------//
void refFunc()
{
	int v = 10, n = 20;
	int &refM =v;
	//int &refN;			//引用须初始化，否则报错
	const int &rval = 8 ;

	refM = n;
	cout << refM << endl;
	cout << v <<endl;
	cout << &rval << endl; 
}


//--------------4、测试字符串是深拷贝还是浅拷贝---------------------//
void testString()
{
	string strA,strB;
	strA ="abc";
	strB = strA;
	strB ="ttt";
	
	cout << strB << endl;
	cout << strA << endl;

	int size;
	cin >>size;
	char* str = ( char* ) malloc ( size * sizeof(char) );
	str = "jjjjjjj";
	cout << str << endl;
}


//------------------5、testFOR ++i----------------------//
void tesStringDeep()
{
	int sum = 0;
	for (int i = 0; i <= 10; ++i)
	{
		sum += i;
	}
	cout << sum << endl;


}







int main()
{
	
	string line,word;
	
	while(getline(cin,line))
	{
		cout << line << endl;
	}
	while (cin >> word)
	{
		cout << word << endl;
	}

	//testCerrClogCout();
	
	return 0;
}
