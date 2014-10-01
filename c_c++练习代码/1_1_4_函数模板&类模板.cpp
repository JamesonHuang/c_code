/*********************************************************************
	@ Title:		函数模板、类模板	

	@ Description:		1、实现函数模板
						
				2、实现类模板


	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/08/22
**********************************************************************/

#include<iostream>
using namespace std;


//----------------------------1、实现函数模板------------------------//
template <typename T>
T Max(T x, T y)
{
	return x > y ? x : y;
}


//----------------------------2、实现类模板--------------------------//
template <class S>
class Compare
{
public:
	Compare(S x, S y)
	{
		xx = x;
		yy = y;
	}
	S Min()
	{
		return xx < yy ? xx : yy;
	}

	S Max()
	{
		return xx > yy ? xx : yy;
	}

private:
	S xx, yy;
};

//-------------2、实现每输出10个元素，就换行，再输出-----------------//
//-------------2、实现每输出10个元素，就换行，再输出-----------------//
//-------------2、实现每输出10个元素，就换行，再输出-----------------//


int main()
{
	//int res = Max(111.2, 22.0);
	//cout << res << endl;
	
	Compare<int> c(11, 33);
	//Compare<int> c;					//不存在默认构造函数
	 
	int res = c.Min();
	cout << res << endl;
	
	return 0;
}