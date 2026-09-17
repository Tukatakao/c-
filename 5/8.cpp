//Constexpr和consteval函数


/*
constexpr 函数是指其返回值可以在编译时计算的函数
要想有资格进行编译时计算，函数必须具有 constexpr 返回类型，
并且在编译时求值过程中不能调用任何非 constexpr 函数。
此外，对函数的调用必须传入 constexpr 参数。

Constexpr 函数也可以在运行时求值
具有 constexpr 返回值的函数同样可以在运行时求值，此时它返回的是非 constexpr 的结果
#include <iostream>

constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    int x{ 5 }; // 不是 constexpr
    int y{ 6 }; // 不是 constexpr

    std::cout << greater(x, y) << " is greater!\n"; // 直到运行时才会被计算

    return 0;
}
也就是正常调用 

允许 constexpr 返回类型的函数在编译时或运行时求值，这样同一个函数便可以同时满足两种场景。

否则，你就得写两个独立的函数（一个有 constexpr 返回类型，一个没有）。这不仅会导致代码重复，而且这两个函数还必须使用不同的名字！

这也解释了 C++ 为何不允许 constexpr 的函数参数。因为如果参数是 constexpr，就意味着只能用 constexpr 实参来调用函数。
但事实并非如此——当函数在运行时求值时，可以用非 constexpr 的实参来调用 constexpr 函数。


*/