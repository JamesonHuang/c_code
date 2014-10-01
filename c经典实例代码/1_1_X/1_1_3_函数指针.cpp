/*********************************************************************
	@ Title:		函数指针	

	@ Description:		1、利用函数指针，实现输出两数中最小值

				2、实现回调函数

	@ Conclusion:		1、函数指针定义：	int ( * pf )(int x,int y);	
				   赋值初始化：		pf = printMin;
				   调用指针指向函数：	pf(x,y)

				2、回调函数是通过传递函数指针实现

	@ Author:		rh_Jameson

	@ Date:			2014/07/24
**********************************************************************/
#include<iostream>

using namespace std;



//-------------1、利用函数指针，实现输出两数中最小值------------------//

//实现比较，返回最小值
int printMin(int cmpM,int cmpN)
{
	return cmpM < cmpN ? cmpM : cmpN;
}
//实现调用函数指针
void ptrToFunc()
{
	int x,y;
	
	//定义函数指针
	int ( * pf )(int x,int y);	
	
	//复制初始化
	pf = printMin;
	
	cout << "请输入待比较数x，y：";
	cin >> x >> y;

	cout << "x和y中较小数的值是：" << pf(x,y) <<endl;		//pf(x,y)  调用pf指向的函数
}




//-------------------------2、实现回调函数---------------------------//

void printWelcome(int len)
{    
	cout << "欢迎光临 --" << len << endl;
}
 
void printGoodbye(int len)
{    
	cout << "谢谢惠顾 --" << len << endl;
}

//通过函数指针进行调用 
void callback(int times, void (* print)(int))
{
    int i;
    for (i = 0; i < times; ++i)
    {
		cout<<i;
        print(i);			 
    }       
	cout << endl << "我不知道你是迎客还是送客！" << endl << endl;
}



int main()
{
	//ptrToFunc();
	
	//调用回调函数
	callback(10,printWelcome);
	callback(10,printGoodbye);

	return 0;
}
