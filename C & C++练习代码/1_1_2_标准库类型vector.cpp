/*********************************************************************
	@ Title:		标准库类型vector	

	@ Description:		1、使用vector，实现循环输出
						
				2、实现每输出10个元素，就换行，再输出

				3、测试vector，熟悉vector的代码格式

	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/08/03
**********************************************************************/

#include<iostream>
#include<vector>
using namespace std;

//---------------------1、使用vector，实现循环输出-------------------//
/*实现vector对象中相邻元素之和的输出*/
void vectorPrint()
{
	vector<int> ivec;							//声明vector对象
	int ival;

	cout << "请输入一串数字：";
	while( cin >> ival )
	{
		ivec.push_back( ival );
	}

	if(ivec.size() == 0)
	{
		cout << "没有数字输入！" << endl;
		exit(0);
	}
	for(vector<int>::size_type ix = 0; ix < ivec.size()-1; ix += 2)
	{
		cout << ivec[ix] + ivec[ix + 1] << "\t";
		if( ix % 6 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;

	if(ivec.size() % 2 != 0)
	{
		cout<<"由于该串数字含有奇数个数字，因此最有一个数字原样输出！" << endl;
	}

	
}

//--------------2、实现每输出10个元素，就换行，再输出----------------//
void intervalTen()
{
	//方式一：
	for( int i = 0; i <= 100; i += 2)
	{
		cout << i << "\t";
		
		if( i % 10 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
	
	//方式二：
	for( vector<int>::size_type i = 0;i <= 100; i++)
	{
		cout << i << "\t";

		if( i % 10 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

//-------------3、测试vector，熟悉vector的代码格式-----------------//
void vectorTest()
{
	//定义格式一
	vector<int> ivec;
	//定义格式二
	vector<int> ivecA(11);

	//循环输出方式一、二
	for( vector<int>::size_type i = 0; i <= 10; i++ )
	{
		ivec.push_back(i);
		//ivec[i] =i;										//ivec不可以通过这种方式赋值，因为ivec中不含任何元素
		ivecA[i] = i;

		cout << ivec[i] << "\t";
		//cout << *(ivec + i) << "\t";						//报错，估计要使用这种方式，只能用迭代器
		cout << ivecA[i] << "\t";
		
		if(i % 10 == 0 && i != 0)
		{
			cout << endl;
		}
		
	}
	//定义格式三
	vector<int> ivecB(10,1);
	//循环输出方式三
	for(vector<int>::iterator iter = ivecB.begin(); iter != ivecB.end(); ++iter)
	{
		vector<int>::const_iterator iterator = ivecB.begin();
		cout << *iter <<"\t";
		
		if(*iter % 10 == 0)
		{
			cout << endl;
		}
	}

	vector<int> ivecC;
	//循环输出方式四
	vector<int>::iterator iter =ivecC.end();
	for (int i = 0; i <= 10; ++i )
	{
		ivecC.insert(iter,44);
		iter = ivecC.end();
		cout << ivecC[i] << "\t";
	}
	cout << endl;
	
	
}





int main()
{
	//vectorPrint();
	/*const int a =10;
	int arr[a];
	for(int i = 0; i < 10; i++)
	{
		arr[i] = i;
		cout << arr[i] << endl;
	}*/
	vectorTest();
	return 0;
}