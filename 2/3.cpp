#include <iostream>
//局部变量
int add(int x,int y)    //这里a也不可被使用
{
    int z{x+y};        //这里的函数体中的变量z以及函数参数都是局部W
    return z;
}                      //在括号处实例变量以与创建相反的顺序逐个销毁           
int main()
{

    int a{};           //在这之后a才可以被使用，一直到末尾
    std::cout << a;    //尽可能在靠近首次使用的位置定义变量
    return 0;
}          