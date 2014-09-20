C经典实例代码
==============

##Content:
>###1_1_X

>>[1_1_0密文加密与解密](https://github.com/JamesonHuang/c_code/blob/master/C%E7%BB%8F%E5%85%B8%E5%AE%9E%E4%BE%8B%E4%BB%A3%E7%A0%81/1_1_X/1_1_0%E5%AF%86%E6%96%87%E5%8A%A0%E5%AF%86%E4%B8%8E%E8%A7%A3%E5%AF%86.cpp) 

>>>* 1、原文中每个字母用该字母之后的第五个字母替换
						
>>>* 2、原文字母都为大写

>>[1_1_1_变量（隐式）自动转换&位移运算](https://github.com/JamesonHuang/c_code/blob/master/C%E7%BB%8F%E5%85%B8%E5%AE%9E%E4%BE%8B%E4%BB%A3%E7%A0%81/1_1_X/1_1_1_%E5%8F%98%E9%87%8F%EF%BC%88%E9%9A%90%E5%BC%8F%EF%BC%89%E8%87%AA%E5%8A%A8%E8%BD%AC%E6%8D%A2%26%E4%BD%8D%E7%A7%BB%E8%BF%90%E7%AE%97.cpp)

>>>* 1、int型变量赋值给char型变量

>>>* 2、浮点型与整型之间的运算、转换

>>>* 3、左、右移运算

>>[1_1_2_字符数组-字符串](https://github.com/JamesonHuang/c_code/blob/master/C%E7%BB%8F%E5%85%B8%E5%AE%9E%E4%BE%8B%E4%BB%A3%E7%A0%81/1_1_X/1_1_2_%E5%AD%97%E7%AC%A6%E6%95%B0%E7%BB%84-%E5%AD%97%E7%AC%A6%E4%B8%B2.cpp)

>>>* 1、字符串处理

>>>* 2、gets() puts() / scanf() printf() / getchar() putchar()

>>[1_1_3_函数指针](https://github.com/JamesonHuang/c_code/blob/master/C%E7%BB%8F%E5%85%B8%E5%AE%9E%E4%BE%8B%E4%BB%A3%E7%A0%81/1_1_X/1_1_3_%E5%87%BD%E6%95%B0%E6%8C%87%E9%92%88.cpp) 

>>>* 1、利用函数指针，实现输出两数中最小值

>>>* 2、实现回调函数

>>[1_1_4_fileRW文件读写](https://github.com/JamesonHuang/c_code/tree/master/C%E7%BB%8F%E5%85%B8%E5%AE%9E%E4%BE%8B%E4%BB%A3%E7%A0%81/1_1_X/1_1_4_fileRW%E6%96%87%E4%BB%B6%E8%AF%BB%E5%86%99) 

>>>* 1、使用文件函数fopen(),fclose()

>>>* 2、使用文件函数fscanf(),fprintf()

>>>* 3、测试不操作File指针，而是操作File类型对象

>>>* 4、字符指针初始化相关

>>>* 5、用fgetc读文件，用fputc写文件

>>>* 6、用fgets函数读文件, fputs函数写文件

>>>* 7、用fread读文件，用fwrite写文件


>>[1_1_5_字符串转换函数atoi&命令行参数](https://github.com/JamesonHuang/c_code/blob/master/C%E7%BB%8F%E5%85%B8%E5%AE%9E%E4%BE%8B%E4%BB%A3%E7%A0%81/1_1_X/1_1_5_%E5%AD%97%E7%AC%A6%E4%B8%B2%E8%BD%AC%E6%8D%A2%E5%87%BD%E6%95%B0atoi%26%E5%91%BD%E4%BB%A4%E8%A1%8C%E5%8F%82%E6%95%B0.cpp) 

>>>* 1、使用atoi，atof，itoa函数

>>>* 2、使用命令行参数


>>[1_1_6_鸡兔同笼问题_HenAndRabbit](https://github.com/JamesonHuang/c_code/blob/master/C%E7%BB%8F%E5%85%B8%E5%AE%9E%E4%BE%8B%E4%BB%A3%E7%A0%81/1_1_X/1_1_6_%E9%B8%A1%E5%85%94%E5%90%8C%E7%AC%BC%E9%97%AE%E9%A2%98_HenAndRabbit.cpp) 

>>>笼子里有兔和鸡：
>>>>* 1、鸡、兔总数量为n，总腿数为m，求鸡、兔各自的数目

>>>>* 2、总腿数为a，求笼子里至少、至多有多少只动物

>>[1_1_7_相邻数字的基数等比](https://github.com/JamesonHuang/c_code/blob/master/C%E7%BB%8F%E5%85%B8%E5%AE%9E%E4%BE%8B%E4%BB%A3%E7%A0%81/1_1_X/1_1_7_%E7%9B%B8%E9%82%BB%E6%95%B0%E5%AD%97%E7%9A%84%E5%9F%BA%E6%95%B0%E7%AD%89%E6%AF%94.cpp) 

>>>1、读入三个整数p、q和r，求出一个进制B，使得在B进制下，p * q = r：
>>>>* 1、如果有多个进制符合，选最小进制

>>>>* 2、进制取值范围2-16

>>[1_1_8_实现atoi函数](https://github.com/JamesonHuang/c_code/blob/master/C%E7%BB%8F%E5%85%B8%E5%AE%9E%E4%BE%8B%E4%BB%A3%E7%A0%81/1_1_X/1_1_8_%E5%AE%9E%E7%8E%B0atoi%E5%87%BD%E6%95%B0.cpp) 

>>>* 1、测试系统自带的atoi函数

>>>* 2、自己实现atoi函数（注意负数）

>>>* Conclusion:		
>>>>- 1、实现函数的各种异常处理<br/>
>>>>（1）判断字符串非空<br/>
>>>>（2）注意去除空格<br/>
>>>>（3）注意正负数处理<br/>
>>>>（4）非整数型字符串的处理<br/>
>>>>- 2、转换公式：<br/>
>>>>（1）res += ( str[iterator] - '0' ) * pow(10.0,len-1-iterator);<br/>
>>>>（2）res = res *10 + ( str[iterator] - '0' ); <br/>

>>[1_1_9_统计字符数](https://github.com/JamesonHuang/c_code/blob/master/C%E7%BB%8F%E5%85%B8%E5%AE%9E%E4%BE%8B%E4%BB%A3%E7%A0%81/1_1_X/1_1_9_%E7%BB%9F%E8%AE%A1%E5%AD%97%E7%AC%A6%E6%95%B0.cpp)

>>>* 1、字符大小相关

>>>* 2、判断一个字符串（含a-z）中哪个字符出现的次数最多

>###1_2_X

>>[1_2_0_闰年-日历问题](https://github.com/JamesonHuang/c_code/blob/master/C%E7%BB%8F%E5%85%B8%E5%AE%9E%E4%BE%8B%E4%BB%A3%E7%A0%81/1_2_X/1_2_0_%E9%97%B0%E5%B9%B4-%E6%97%A5%E5%8E%86%E9%97%AE%E9%A2%98.cpp)

>>>* 1、判断闰年

>>>* 2、给定从公元2000年1月1号开始逝去的天数，判断这一天是哪年哪月哪日星期几

>>[1_2_1_斐波那契数列](https://github.com/JamesonHuang/c_code/blob/master/C%E7%BB%8F%E5%85%B8%E5%AE%9E%E4%BE%8B%E4%BB%A3%E7%A0%81/1_2_X/1_2_1_%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97.cpp)

>>>* 1、数列第一个和第二个数都为1
	
>>>* 2、接下来每个数都等于前面两个数字之和

>>[1_2_2_求二叉树节点间的父节点](https://github.com/JamesonHuang/c_code/blob/master/C%E7%BB%8F%E5%85%B8%E5%AE%9E%E4%BE%8B%E4%BB%A3%E7%A0%81/1_2_X/1_2_2_%E6%B1%82%E4%BA%8C%E5%8F%89%E6%A0%91%E8%8A%82%E7%82%B9%E9%97%B4%E7%9A%84%E7%88%B6%E8%8A%82%E7%82%B9.cpp)
>>>* 1、求二叉树任意两个结点间的共同父结点

>>[1_2_3_小白代码](https://github.com/JamesonHuang/c_code/blob/master/C%E7%BB%8F%E5%85%B8%E5%AE%9E%E4%BE%8B%E4%BB%A3%E7%A0%81/1_2_X/1_2_3_%E5%B0%8F%E7%99%BD%E4%BB%A3%E7%A0%81.cpp)

>>>* 1、分离百位、十位、个位，反转三位数
	
>>>* 2、不用临时变量来交换变量

>>>* 3、三整数排序

>>>* 4、习题实验

>>[1_2_4_小白代码2](https://github.com/JamesonHuang/c_code/blob/master/C%E7%BB%8F%E5%85%B8%E5%AE%9E%E4%BE%8B%E4%BB%A3%E7%A0%81/1_2_X/1_2_4_%E5%B0%8F%E7%99%BD%E4%BB%A3%E7%A0%812.cpp)


>>>* 1、测试程序运行时间
	
>>>* 2、测试cin的返回值

>>>* 3、输出整数的位数

>>>* 4、输出上三角、下三角、菱形

>>[1_2_5_测试指针变量的引用(int &p)](https://github.com/JamesonHuang/c_code/blob/master/C%E7%BB%8F%E5%85%B8%E5%AE%9E%E4%BE%8B%E4%BB%A3%E7%A0%81/1_2_X/1_2_5_%E6%B5%8B%E8%AF%95%E6%8C%87%E9%92%88%E5%8F%98%E9%87%8F%E7%9A%84%E5%BC%95%E7%94%A8(int%20%26p).cpp)

>>>- 1、测试指针变量的引用(int* &p)

>>[1_2_6_素数_欧几里得_随机数](https://github.com/JamesonHuang/c_code/blob/master/C%E7%BB%8F%E5%85%B8%E5%AE%9E%E4%BE%8B%E4%BB%A3%E7%A0%81/1_2_X/1_2_6_%E7%B4%A0%E6%95%B0_%E6%AC%A7%E5%87%A0%E9%87%8C%E5%BE%97_%E9%9A%8F%E6%9C%BA%E6%95%B0.cpp)

>>>* 1、测试生成随机数

>>>* 2、欧几里得算法

>>>* 3、判断素数

>>>* 4、输出程序运行时间
