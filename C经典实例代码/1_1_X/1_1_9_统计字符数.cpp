/**************************************************************************
	@ Title:		统计字符数	

	@ Description:		1、字符大小相关
				
				2、判断一个字符串（含a-z）中哪个字符出现的次数最多
						
	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/07/29
***************************************************************************/

#include<iostream>
using namespace std;

#define MAX 26

//------------------------------------------------1、字符大小相关-----------------------------------------------------//
void sizeofCharArr()
{
	char* ch = (char*)malloc(5 * sizeof(char) );
	ch = "asffdfg";
	cout << sizeof(ch) << endl;			//不管字符串大小是多少，永远输出4，因为sizeof（ch）是指该字符指针变量的大小	
	cout << strlen(ch) << endl;			//字符串实际大小

	char c[] = "asdf";				//字符数组大小：4
	cout << sizeof(c) << endl;			//输出：5;	原因：加了一个结束符
}



//-------------------------------2、判断一个字符串（含a-z）中哪个字符出现的次数最多------------------------------------//
void judgecMaxCount(const char * s,int* MaxCount,int* MaxIndex)
{
	int* chList = (int*) malloc ( MAX * sizeof(int) );
	
	//初始化字母表，每个字母出现次数初始化为0
	for ( int i = 0; i < MAX; i++ )
	{
		chList[i] =0;
	}

	int sLen = strlen(s);					//给定字符串的长度
	int index;
	
	for( int j = 0; j < sLen; j++)				//遍历字符串
	{
		index = s[j] - 'a';
		if( index >= 0 && index < MAX )			//元素为字母时，字母表相应元素的值+1
		{
			chList[index]++;
		}
		else
		{
			cout << "给定字符串不符合要求！" << endl;
		}
		if( *MaxCount < chList[index] )			//判断出现最多次数的字母
		{
			*MaxCount = chList[index];
			*MaxIndex = index;
		}
	}
	
}

int main()
{
	//sizeofCharArr();
	char * s = new char[100];
	cout << "请输入字符串：";
	cin >> s;
	
	int MaxCount = 0, MaxIndex =0;
	judgecMaxCount(s,&MaxCount,&MaxIndex);
	
	char c ='a' + MaxIndex;

	cout << "出现次数最多的字母：" << c <<endl;
	cout << "该字母出现的次数为：" << MaxCount << endl;
	return 0;
}