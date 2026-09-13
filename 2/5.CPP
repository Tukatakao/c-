//跨文件前向声明
#include "add.h"                   //使用头文件进行声明
#include <iostream>
int add(int x,int y);              //声明的另一个文件的add函数
int main()
{
    std::cout << add (2,3);        //使用的另一个文件的add函数

    return 0;

}
//如果定义两次 即使未调用也会报错