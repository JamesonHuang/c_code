/*********************************************************************
	@ Title:		& VS &&

	@ Description:		1、测试 & VS &&
						2、内存分配空间方式：返回指针
	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/09/19
**********************************************************************/
#include <iostream>
#include<cstdlib>
using namespace std;

struct linkList
{
    int value;
    linkList* next;
};

//分配空间、初始化后，返回指针对象，该指针就不会被回收
linkList* initList()
{
    linkList *tmp = (linkList *)malloc(sizeof(linkList)); 
    tmp->value = 11;
    tmp->next = NULL;
    return tmp;
}

int main()
{
    /*cout << (2 && 3) << endl;
    cout << (2 & 3) << endl;
    */
    linkList *L = initList();
    cout << L->value << endl;
    cout << L->next << endl;


    return 0;
}
