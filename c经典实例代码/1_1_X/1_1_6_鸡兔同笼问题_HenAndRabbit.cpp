/**************************************************************************
	@ Title:		鸡兔同笼问题	

	@ Description:		笼子里有兔和鸡：
					1、鸡、兔总数量为n，总腿数为m，求鸡、兔各自的数目

					2、总腿数为a，求笼子里至少、至多有多少只动物
	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/07/29
***************************************************************************/

#include<iostream>

using namespace std;

//-------------1、鸡、兔总数量为n，总腿数为m，求鸡、兔各自的数目-----------//
void func1()
{
	int TotalNum,TotalLegs;
	
	cout << " 请输入鸡和兔的总数量： ";
	cin >> TotalNum ;
	
	cout << " 请输入鸡和兔的总腿数： ";
	cin >> TotalLegs;

	//鸡有两条腿，兔有四条腿，解二元一次方程
	int ChickenNum,RabbitNum;

	RabbitNum = ( TotalLegs - 2 * TotalNum ) / 2;

	ChickenNum = TotalNum - RabbitNum;
	if( TotalLegs % 2 == 1 ||  ChickenNum < 0 || RabbitNum < 0 )
	{
		 cout << "输入无解！" << endl;
	}
	else
	{
		cout << "鸡的数目为：" << ChickenNum << endl;
		cout << "兔的数目为：" << RabbitNum << endl;
	}
	

}



//-------------2、总腿数为a，求笼子里至少、至多有多少只动物-----------------//
void func2()
{
	int TotalLegs;
	cout << "请输入鸡和兔的总腿数：";
	cin >> TotalLegs;

	if ( TotalLegs % 2== 1 || TotalLegs < 0 )
	{
		cout << "输入非法数据!" << endl;
		return;
 	}
	int MaxNum = TotalLegs / 2;									//总腿数一定，最多动物数目的情况是：动物全部为鸡的情况下
	int MinNum;
	cout << "笼子里至多有" << MaxNum << "只动物" << endl;
	
	if ( TotalLegs % 4 == 2 )
	{
		//MinNum = TotalLegs / 4 + ( TotalLegs % 4 ) /2;
		MinNum = TotalLegs / 4 + 1;								//一只鸡，剩余均为兔子的情况
	}
	else
	{
		MinNum = TotalLegs / 4 ;								//全为兔子的情况
	}
	cout << "笼子里至少有" << MinNum << "只动物" << endl;


}


int main()
{
	//func1();

	func2();
	
	return 0;
}