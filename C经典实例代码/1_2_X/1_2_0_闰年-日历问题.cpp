/**************************************************************************
	@ Title:		闰年-日历问题	

	@ Description:		1、判断闰年
						
				2、给定从公元2000年1月1号开始逝去的天数，
				判断这一天是哪年哪月哪日星期几
	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/07/29
***************************************************************************/

#include<iostream>

using namespace std;

//-------------------------1、判断闰年------------------------------------//
int isLeapYear(int year)
{
	if((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)
	{
		return 1;
		//cout << year << "是闰年！" << endl;
	}
	else
	{
		return 0;
		//cout << year << "不是闰年！" << endl;
	}
}

//---2、给定从公元2000年1月1号开始逝去的天数，判断这一天是哪年哪月哪日星期几---//
/*
*问题一：要求的那天是星期几
*
*问题二：要求那天是哪年哪月哪日
*/
char week[7][10] ={"六","日","一","二","三","四","五"};

int year[2] ={365,366};				//平年天数 & 闰年天数

int month[2][12] ={ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
					31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31	};	//平年&闰年各自的月数

void judgeDays()
{
	int days,dayOfWeek;
	int i = 0,j = 0;
	if( cin >> days && days > 0 )
	{
		dayOfWeek = days % 7;								//求出这一天是星期几
		
		for(i = 2000; days >= year[ isLeapYear(i) ]; i++)				//对给定天数，逐年开减~
		{
			days -= year[isLeapYear(i)];
		}
		for(j = 0; days >= month[isLeapYear(i)][j]; j++)				//逐月开减~~
		{
			days -= month[isLeapYear(i)][j];
		}
		cout << days << "是：" << i << "年，" << j+1 << "月，" << days + 1 << "号,星期" << week[dayOfWeek] << endl;
	}
	else
	{
		cout << "输入的天数不合要求！" << endl;
	}
}


int main()
{
	/*判断闰年
	int year ;
	cout << "请输入年份：";
	cin >> year;
	bool isLeap = isLeapYear ( year );
	cout << isLeap << endl;*/

	judgeDays();

	return 0;
}