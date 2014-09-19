/*********************************************************************************************
	@ Title:			小白书第二章	

	@ Description:		1、测试程序运行时间
						
				2、测试cin的返回值

				3、输出整数的位数

				4、输出上三角、下三角、菱形

	@ Conclusion:		1、打印菱形
					i < line时，须line - i个空格，打印2i-1个星号，
						line - i, 2 * line-(line-i)=n+i

					i > line是，须i - line个空格，打印2i-1个星号，
						i - line,  2 * line - (i - line)=3 * line - i;

	@ Author:		rh_Jameson

	@ Date:			2014/08/27
*********************************************************************************************/

#include<iostream>
#include<ctime>
using namespace std;


//----------------------1、测试程序运行时间--------------------------//
void testCount()
{
	//cout << clock()/ CLOCKS_PER_SEC << endl;
	cout << clock() << endl;
}
//----------------------2、测试cin的返回值---------------------------//
void testCin()
{
	int a, b;
	while( cin >> a >> b )
	{
		cout << a + b << endl;
	}
}
//----------------------3、输出整数的位数---------------------------//
int printNumCount(int num)
{
	int count = 0;
	while(num != 0)
	{
		num /= 10;
		count++;
	}
	cout << count << endl;
	return count;
}
//---------------------4、输出上三角形，1,3,5...----------------------//
int printTopTri()
{
	int i,j;
	int line = 10;
	for( i = 1; i <= line; ++i )					//控制行数
	{
		j = 1;
		/*while(j <= line - i)
		{
			cout << " ";
			++j;
		}*/
		for( j =1;  j <= ( line - i ); ++j )		//控制输出空格line - i个
		{
			cout << " ";
		}

		
		/*while( j <= (2 * i -1) )
		{
			cout << "*";
			++j;
		}*/
		for( j = 1; j <= (2 * i - 1); ++j )			//控制输出星号2 * i - 1个
		{
			cout << "*";
		}
		
		cout << endl; 
	}
	return 0;
	
    
}

//---------------------------5、输出倒三角---------------------------------//
void printReverseTri()
{
	int i,j;
	int line = 10;
	for( i = line; i >= 1; --i )						//倒着输出，循环内无变动
	{
		j = 1;
		/*while(j <= line - i)
		{
			cout << " ";
			++j;
		}*/
		for( j =1;  j <= ( line - i ); ++j )
		{
			cout << " ";
		}

		
		/*while( j <= (2 * i -1) )
		{
			cout << "*";
			++j;
		}*/
		for( j = 1; j <= (2 * i - 1); ++j )
		{
			cout << "*";
		}
		
		cout << endl; 
	}
}
//---------------------------5、输出菱形方法一---------------------------------//
void printLing()
{
	int i,j;
	int line = 10;
	for( i = 1; i <= line; ++i )
	{
		j = 1;
		/*while(j <= line - i)
		{
			cout << " ";
			++j;
		}*/
		for( j =1;  j <= ( line - i ); ++j )
		{
			cout << " ";
		}

		
		/*while( j <= (2 * i -1) )
		{
			cout << "*";
			++j;
		}*/
		for( j = 1; j <= (2 * i - 1); ++j )
		{
			cout << "*";
		}
		
		cout << endl; 
	}

	for( i = line-1; i >= 1; --i )
	{
		j = 1;
		/*while(j <= line - i)
		{
			cout << " ";
			++j;
		}*/
		for( j =1;  j <= ( line - i ); ++j )
		{
			cout << " ";
		}

		
		/*while( j <= (2 * i -1) )
		{
			cout << "*";
			++j;
		}*/
		for( j = 1; j <= (2 * i - 1); ++j )
		{
			cout << "*";
		}
		
		cout << endl; 
	}

	
}

//---------------------------5、输出菱形方法二---------------------------------//
void printLin()
{
	int line = 10;
	int i,j;												//行，列 
    for(i = 1; i <= 2 * line; i++) 
    { 
        for(j = 1; j <= 2 * line; j++) 
        { 
            if(i < line)									//i < line时，须打印line - i个空格
            { 
                if(j > line - i && j < line + i)			//line - i, 2 * line-(line-i)=n+i
                { 
                    cout << '*'; 
                } 
                else 
                { 
                    cout << ' '; 
                } 
            } 
            else											//i > line时，须打印i - line个空格
            { 
                if(j > i - line && j < 3 * line - i)		//i - line,  2 * line - (i - line)=3 * line - i;
                { 
                    cout << '*'; 
                } 
                else  
                { 
                    cout << ' '; 
                } 
            } 
 
        } 
        cout << endl; 
    } 
}

int main()
{
	//testCount();
	//testCin();
	//printNumCount( 9876 );
	//printTopTri();
	//printReverseTri();
	//printLing();
	printLin();
	return 0;
}