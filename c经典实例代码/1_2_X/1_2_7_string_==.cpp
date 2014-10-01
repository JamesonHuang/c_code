/*************************************************************************
	> File Name:        1_2_7_string_==.cpp
	
    > Description:      1.测试c++ string 的 == 和java区别 
	                    
                        2.
    > Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年10月01日 星期三 10时26分30秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

//测试str == 是比较值还是比较地址
int testStr()
{
    string str = "hello";
    string str_comp = "hello";
    
    cout << str << endl;
    cout << str_comp << endl;
    cout << &str << endl;
    cout << &str_comp << endl;

    if(str == str_comp)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    if(str.compare(str_comp))
    {
            cout << 1 << endl;
    }
    else
    {
            cout << 0 << endl;
    }

}

int main()
{
  
  testStr();
}
