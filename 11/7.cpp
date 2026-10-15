//函数模板实例化
/*

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}
如何使用它呢


使用函数模板：
max<实际类型>(参数一, 参数二);
std::cout << max<int>(1, 2) << '\n';

则会将所有T设为int 然后将1，2传入

std::cout << max<int>(4, 3) << '\n';    // 调用已经实例化的函数 max<int>(int, int)
std::cout << max<double>(1, 2) << '\n'; // 实例化并调用函数 max<double>(double, double)
注意到的是第二个我们提供的是int 参数 他们会被隐式转换为double










模板参数推导：
一般调用：
std::cout << max<int>(1, 2) << '\n'; 
// 显式标记我们要调用 max<int>

可以是：
std::cout << max<>(1, 2) << '\n';
std::cout << max(1, 2) << '\n';
编译器会自动推导，然后自动实例




具有非模板参数的函数模板：
也可以给模板里写上非模板参数
template <typename T>
int someFcn (T, double)
{
    return 5;
}
其中模板参数可以匹配任何类型
非模板参数匹配的方式类似于普通函数的参数；
someFcn(1, 3.4); // 匹配 someFcn(int, double)
someFcn(1, 3.4f); // 匹配 someFcn(int, double) -- float 被提升为 double
someFcn(1.2, 3.4); // 匹配 someFcn(double, double)
someFcn(1.2f, 3.4); // 匹配 someFcn(float, double)
someFcn(1.2f, 3.4f); // 匹配 someFcn(float, double) -- float 被提升为 double
也就是第一个随便
第二个必须经过四个步骤后能匹配上








实例化函数不一定能通过编译：
因为假如函数体内某些运算是针对于数字的
而模板参数为字符串
但是字符串不能运算
编译就错了





实例化函数在语义上可能并不总是有意义:
template <typename T>
T addOne(T x)
{
    return x + 1;
}

int main()
{
    std::cout << addOne("Hello, world!") << '\n';

    return 0;
}
允许将整数值加到字符串字面值中
语法上没错 语义上不对










在多个文件中使用函数模板：
main.cpp:
template <typename T>
T addOne(T x); // 函数模板前向声明

int main()
{
    std::cout << addOne(1) << '\n';
    std::cout << addOne(2.3) << '\n';

    return 0;
}


add.cpp：
template <typename T>
T addOne(T x) // 函数模板定义
{
    return x + 1;
}

如果是普通函数
则会将add.cpp里的定义调用到main
但是模板函数不行，会报错
他看不见模板函数的定义，无法实例化
解决方法是
将模板定义放在头文件中
add.h:
#ifndef ADD_H
#define ADD_H

template <typename T>
T addOne(T x) // 函数模板定义
{
    return x + 1;
}

#endif
在main中直接包含


*/