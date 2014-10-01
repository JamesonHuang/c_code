/******************************************************************************
	@ Title:			文件读写	

	@ Description:		1、使用文件函数fopen(),fclose()
				2、使用文件函数fscanf(),fprintf()
				3、测试不操作File指针，而是操作File类型对象
				4、字符指针初始化相关
				5、用fgetc读文件，用fputc写文件
				6、用fgets函数读文件, fputs函数写文件
				7、用fread读文件，用fwrite写文件

	@ Conclusion:		1、char* colName ="initialChar pointer";
				（该方式，初始化字符指针变量后，字符串只能读，不能写）
						
				2、疑问：
				FilePTest中，&f失败，fp成功，&f 和 fp不是一样吗？

	@ Author:		rh_Jameson

	@ Date:			2014/07/24
*******************************************************************************/

#include<stdio.h>
#include <stdlib.h>		//exit()、malloc（）需要用到



//读取文件，并将内容输出到屏幕上( fscanf )
void filePrintToScreen()
{
	/* 该方式，初始化字符指针变量后，字符串只能读，不能写 */
	//char* colName ="initialChar pointer";							//错误

	/* new动态分配内存空间 */
	//char* colName = new char;								//调试过程中，代码正确输出，但运行的话，就报错，操作影响到内存其他数据？
	//char* colName = new char[30];								//正确
	
	/*malloc动态分配内存空间*/
	char* colName = ( char * ) malloc( 30 * sizeof(char) );					//正确	
	//char colName[30]="";									//定义字符数组
	
	int colNum,colNum2;
	
	FILE * fp;
	fp = fopen( "txtFile.txt", "r");		//调用fopen函数，获得目标文件
	if( fp == NULL )					
	{
		printf("读不到该文件！");
		return;							
		//exit(0);		
	}	
	
	while( fscanf(fp,"%s %d %d",colName,&colNum,&colNum2) != EOF )			//一直读文件直到结束，格式化输入函数
	{
		printf("%s %d %d\n",colName,colNum,colNum2);
		
	}
	
	fclose( fp );									//关闭文件函数

}


//测试不操作File指针，而是操作File类型对象：失败！
void FilePTest()
{
	FILE f;
	FILE * fp;
	fp = fopen( "txtFile.txt", "r");	
	
	char* colName = ( char * ) malloc( 30 * sizeof(char) );		//正确
	int colNum,colNum2;

	if( fp == NULL )
	{
		printf("读不到文件！");
		return;
	}

	f = * fp;

	while( fscanf(fp,"%s %d %d",colName,&colNum,&colNum2) != EOF )				//&f失败，fp成功，&f 和 fp 不是一样吗？
	{
		printf("%s %d %d\n",colName,colNum,colNum2);
		
	}
	
	fclose( fp );	
}

//将数据写入文件中( fprintf )
void printDataToFile()
{
	FILE *fp = fopen("txtFile.txt","a");

	if( fp == NULL )
	{
		printf("文件读取失败！");
		return;
	}
	int i=10;
	if( fprintf( fp,"osijfiojfij %d", i ) );
	{
		printf("数据写入成功！");
	}
	fclose(fp);
}

//用fgets函数读文件, fputs函数写文件
//用fgetc读文件，用fputc写文件
void copyFile()
{
	FILE * fpSrc, * fpDest;								//定义源文件、目标拷贝文件的指针 
	
	//二进制读取方式打开txtFile.txt
	fpSrc = fopen( "txtFile.txt", "rb"); 
	if( fpSrc == NULL ) 
	{ 
		printf( "Source file open failure."); 
		return ; 
	 }
	
	//二进制写入方式打开copyFile.txt
	fpDest = fopen("copyFile.txt", "wb"); 
	if( fpDest == NULL) 
	{ 
		fclose( fpSrc); 
		printf( "Destination file open failure."); 
		return ; 
	}

	//用fgetc(),fputc拷贝
	/*
	int c; 
	while( ( c = fgetc(fpSrc)) != EOF)  
		fputc( c, fpDest); 
	*/

	//用fgets(),fputs()拷贝
	char szLine[200]; 
	while( fgets(szLine, 199, fpSrc)) 
	{ 
		fputs(szLine, fpDest); 
	} 
	 
	
	//关闭文件  
	fclose(fpSrc); 
	fclose(fpDest); 
	    
}



struct Student
{ 
	char colName[20]; 
	int colNum,colNum2; 
 
}; 
//用fread读文件，用fwrite写文件
/*
void freadAndWrite()
{
	FILE * fpSrc, * fpDest; 
	struct Student Stu; 
	fpSrc = fopen( "txtFile.txt", "rb"); 
	if( fpSrc == NULL ) 
	{ 
		printf( "Failed to open the file."); 
		return 0; 
	} 
	fpDest = fopen( "students .dat", "wb"); 
	if( fpDest == NULL) { 
	fclose( fpSrc); 
	printf( "Destination file open failure."); 
	return 0; 
	} 
	char szName[30], szGender[30]; 
	int nId, nBirthYear,   nBirthMonth, nBirthDay; 
	float fGPA;

	while( fscanf( fpSrc, "%s%d%s%d%d%d%f", szName, & nId,  
			szGender, & nBirthYear, & nBirthMonth, & nBirthDay, & fGPA) != EOF) { 
	strcpy(Stu.szName, szName); 
	Stu.nId = nId; 
	if( szGender[0] == 'f' ) 
	Stu.nGender = 0; 
	else 
	Stu.nGender = 1; 
	Stu.nBirthYear = nBirthYear; 
	Stu.nBirthMonth = nBirthMonth; 
	Stu.nBirthDay = nBirthDay; 
	fwrite( & Stu, sizeof(Stu), 1, fpDest); 
	} 
	fclose(fpSrc); 
	fclose(fpDest); 
	fpSrc = fopen( "students.dat", "rb"); 
	if( fpSrc == NULL ) { 
	printf( "Source file open failure."); 
	return 0; 
	} 
	fpDest = fopen( "students2.dat", "wb"); 
	if( fpDest == NULL) { 
	fclose( fpSrc); 
	printf( "Destination file open failure."); 
	return 0; 
	} 
	while(fread( & Stu, sizeof(Stu), 1 , fpSrc)) { 
	if( Stu.nBirthYear >= 1985 )  
	fwrite( & Stu, sizeof(Stu), 1, fpDest); 
	} 
	fclose( fpSrc); 
	fclose( fpDest); 



}
*/


//void fseek()
//{
//	FILE * fpSrc; 
//	 
//	fpSrc = fopen( "txtFile.txt", "r+b"); 
//	if( fpSrc == NULL ) { 
//	printf( "Failed to open the file."); 
//	return 0; 
//	} 
//	
//	fseek( fpSrc, sizeof(Student)* 4 , SEEK_SET); 
//	fread( aStu, sizeof(Student), 7, fpSrc); 
//	fseek( fpSrc, sizeof(Student) * 20,   SEEK_SET); 
//	fwrite( aStu, sizeof(Student), 7, fpSrc); 
//	
//	fclose( fpSrc); 
//
//}


int main()
{
	filePrintToScreen();			//读取文件，并将内容输出到屏幕上
	
	//FilePTest();					//测试使用File f作为操作对象			
	
	//printDataToFile();			//将数据写入文件中( fprintf )
	
	//copyFile();
	
	return 0;
}