//@description:		4、自定义复制构造函数（浅复制、深复制）

#include<iostream>
using namespace std ;
class  Location 
{
public :
      Location ( int xx = 0, int yy = 0 )  
	  { 
		  X = xx ;  
		  Y = yy ; 
		  cout << "constructor called." << endl ; 
	  }
      //自定义复制构造函数
	  Location ( const Location  & p ) 
      { 
		  X = p.X ;  
		  Y = p.Y ;   
		  cout << "Copy_constructor called." << endl ; 
	  }
	  
      int GetX() 
	  { 
		  return  X ; 
	  }
      int GetY() 
	  { 
		  return  Y ; 
	  }
private :  
	int  X ,  Y ;
} ;
 
