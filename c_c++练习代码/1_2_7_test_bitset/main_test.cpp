/*************************************************************************
	> File Name:        main_test.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2015年03月16日 星期一 19时13分39秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
#include <bitset>

using namespace std;

int main()
{
    //initial method 1
    bitset<4> bit(0xf);
    //initial method 2
    string s = "1001";
    bitset<4> bitvec(s);
    for(int i = 0; i < 4; ++i){
        cout << bit[i] << "\t";
    }
    cout << endl;
    for(int i = 0; i < 4; ++i){
        cout << bitvec[i] << "\t";
    }
    cout << endl; 
    //initial method 3
    bitset<10> bit_vec2;
    for(int i = 0; i < 10; ++i){
        bit_vec2[i] = 0;
        cout << bit_vec2[i] << "\t";
    }
    return 0;
}
