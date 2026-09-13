#include <iostream>//预处理指令必须单行防

int main() {
    int a,b;
    int c;
    int d;
    double e;
    int f=1;//初始化
    //列表初始化{}不会使数据窄化，比如小数变成整数
    //int g{1.2};错误，窄化，不会变成整数
    //int h(1.2)变成整数、
    //默认初始化后变量的值是不确定的。int a;
    //顺手直接初始化
    //int a,b=1;(a没有初始化，b初始化为1)
    //要在同一行上打印多个内容，可在单个语句中多次使用插入运算符（«）来连接多个输出
    std::cout << "Hello, World!" << std::endl;

    std::cout << "Hi!";
    std::cout << "My name is Alex.";
    //这俩会变成一行，没有endl换行
    //缓冲输出，程序积攒"一车数据 一起送到系统输出，无缓冲：有一个数据就发 cerr（紧急情况）！！！
    std::cout<<"omg"<<"\n";
    std::cout<<"omg\n";
    std::cin>>a;
    //如果c语言创建时自动初始化所有内存，没用，反正用的时候还要覆盖，为啥多覆盖一遍
    //变量不能以数字开头
    
    return 0;
}
