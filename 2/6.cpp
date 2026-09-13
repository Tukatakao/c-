// 命名空间
#include <iostream>
int x{}; // 全局变量
int main()
{
    int x{5};         // 不和全局变量冲突
    std::cout << x;   // 打印局部变量
    std::cout << ::x; // 打印全局变量
}