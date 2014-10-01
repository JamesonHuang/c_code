#include <iostream>
using namespace std;

class CExample {
private:
    int a;
public:
      //构造函数
    CExample(int b)
    { a = b;}

      //一般函数
    void Show ()
    {
        cout<<a<<endl;
     }
};

