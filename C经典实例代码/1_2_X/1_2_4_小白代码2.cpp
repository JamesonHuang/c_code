/*********************************************************************************************
	@ Title:			Ð¡°×ÊéµÚ¶þÕÂ	

	@ Description:		1¡¢²âÊÔ³ÌÐòÔËÐÐÊ±¼ä
						
				2¡¢²âÊÔcinµÄ·µ»ØÖµ

				3¡¢Êä³öÕûÊýµÄÎ»Êý

				4¡¢Êä³öÉÏÈý½Ç¡¢ÏÂÈý½Ç¡¢ÁâÐÎ

	@ Conclusion:		1¡¢´òÓ¡ÁâÐÎ
					i < lineÊ±£¬Ðëline - i¸ö¿Õ¸ñ£¬´òÓ¡2i-1¸öÐÇºÅ£¬
						line - i, 2 * line-(line-i)=n+i

					i > lineÊÇ£¬Ðëi - line¸ö¿Õ¸ñ£¬´òÓ¡2i-1¸öÐÇºÅ£¬
						i - line,  2 * line - (i - line)=3 * line - i;

	@ Author:		rh_Jameson

	@ Date:			2014/08/27
*********************************************************************************************/

#include<iostream>
#include<ctime>
using namespace std;


//----------------------1¡¢²âÊÔ³ÌÐòÔËÐÐÊ±¼ä--------------------------//
void testCount()
{
	//cout << clock()/ CLOCKS_PER_SEC << endl;
	cout << clock() << endl;
}
//----------------------2¡¢²âÊÔcinµÄ·µ»ØÖµ---------------------------//
void testCin()
{
	int a, b;
	while( cin >> a >> b )
	{
		cout << a + b << endl;
	}
}
//----------------------3¡¢Êä³öÕûÊýµÄÎ»Êý---------------------------//
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
//---------------------4¡¢Êä³öÉÏÈý½ÇÐÎ£¬1,3,5...----------------------//
int printTopTri()
{
	int i,j;
	int line = 10;
	for( i = 1; i <= line; ++i )					//¿ØÖÆÐÐÊý
	{
		j = 1;
		/*while(j <= line - i)
		{
			cout << " ";
			++j;
		}*/
		for( j =1;  j <= ( line - i ); ++j )		//¿ØÖÆÊä³ö¿Õ¸ñline - i¸ö
		{
			cout << " ";
		}

		
		/*while( j <= (2 * i -1) )
		{
			cout << "*";
			++j;
		}*/
		for( j = 1; j <= (2 * i - 1); ++j )			//¿ØÖÆÊä³öÐÇºÅ2 * i - 1¸ö
		{
			cout << "*";
		}
		
		cout << endl; 
	}
	return 0;
	
    
}

//---------------------------5¡¢Êä³öµ¹Èý½Ç---------------------------------//
void printReverseTri()
{
	int i,j;
	int line = 10;
	for( i = line; i >= 1; --i )						//µ¹×ÅÊä³ö£¬Ñ­»·ÄÚÎÞ±ä¶¯
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
//---------------------------5¡¢Êä³öÁâÐÎ·½·¨Ò»---------------------------------//
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

//---------------------------5¡¢Êä³öÁâÐÎ·½·¨¶þ---------------------------------//
void printLin()
{
	int line = 10;
	int i,j;												//ÐÐ£¬ÁÐ 
    for(i = 1; i <= 2 * line; i++) 
    { 
        for(j = 1; j <= 2 * line; j++) 
        { 
            if(i < line)									//i < lineÊ±£¬Ðë´òÓ¡line - i¸ö¿Õ¸ñ
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
            else											//i > lineÊ±£¬Ðë´òÓ¡i - line¸ö¿Õ¸ñ
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