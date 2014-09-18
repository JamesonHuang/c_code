//@description:		3、用初始式对数据成员置值

#include <iostream>
#include "Date.h"

using namespace std;


/*
Date:: Date(int y, int m, int d)	// 带参数构造函数
 { year = y ;    month = m ;    day = d ;
   cout <<year <<"/"<<month<<"/"<<day<<": Date with argument object initialized."<<"\n" ;
 }
 */
Date:: Date(int y, int m, int d):year(y),month(m),day(d)	// 带参数构造函数, 用初始式对数据成员置值

 { 
   cout <<year <<"/"<<month<<"/"<<day<<": Date with argument object initialized."<<"\n" ;
 }

// 无参构造函数
Date:: Date() 
{ 
	cout << "Date object initialized.\n" ; 
}

// 析构函数	
Date:: ~Date() 
{ 
	cout << "Date object destroyed.\n" ; 
}

void Date:: SetDate( int y, int m, int d ) 
{ 
	year = y ; 
	month = m ;  
	day = d ; 
}

int Date::IsLeapYear() 
{ 
	return ( year%4==0 && year%100!=0 ) || ( year%400==0 ) ; 
}

void Date::PrintDate()  
{ 
	cout << year << "/" << month << "/" << day << endl ; 
}
