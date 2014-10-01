/*********************************************************************
	@ Title:			字符数组-字符串	

	@ Description:		1、字符串处理
						
				2、gets() puts() / scanf() printf()
						getchar() putchar()

	@ Conclusion:		1、scanf：输入字符串中不能有空格
					gets:输入字符串中可以有空格

				2、printf：可输出各种类型的数据
					puts:只能输出字符串
						
				3、putchar:输出一个字符
					getchar：等待输入一个字符

	@ Author:			rh_Jameson

	@ Date:				2014/07/24
**********************************************************************/

#include<stdio.h>
#include<string.h>

void charArr()
{
	char szTitle[] = "Prison Break";
	char szHero[100] = "Michael Scofield";
	char szPrisonName[100];
	char szResponse[100];


	printf("What's the name of the prison in %s?\n",szTitle);
	
	//scanf("%s",szPrisonName);							//scanf：输入字符串中不能有空格
											//例如：输入Fox River，只能读入Fox
	
	gets(szPrisonName);								//gets:输入字符串中可以有空格
											//输入Fox River，读入Fox River
	
	if(strcmp( szPrisonName, "Fox River") == 0)					//输入字符串与"Fox River"一致，则条件成立
	{
		printf("Yeah! Do you love %s?\n",szHero);
	}
	else
	{
		strcpy(szResponse,"It seems you haven't watched it!\n");		//将字面量拷贝到szResponse
		printf(szResponse);
	}

	szTitle[0] = 't';
	szTitle[3] = 0;
	
	//printf(szTitle);								//pirntf:可输出各种类型的数据
	puts(szTitle);		//结果：tri						//puts:只能输出字符串

	putchar('s');
	getchar();
	
}


int main()
{
	charArr();
	return 0;
}