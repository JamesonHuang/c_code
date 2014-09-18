//@description:1、写一个含有构造函数、析构函数的类
class Date
{ 
public:
      Date() ;
      ~Date() ;
	  Date(int,int,int) ;


      void SetDate( int y, int m, int d ) ;
      int IsLeapYear() ;
      void PrintDate() ;

private:
      int year, month, day ;
} ;