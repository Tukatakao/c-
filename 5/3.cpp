//Constexpr


/*
constexpr关键字


有些时候不好看出一个变量的表达式是不是常变量
比如 const int w{add()};
这里不好判断add()的返回值是不是编译时常量
所以加个
constexpr int w{add()};   如果add的返回值不是编译时常量就会报错，可以确保时编译时常量
如：
#include <iostream>

int five()  返回值是整形5            改成constexpr int five()
{
    return 5;
}

int main()
{
    constexpr double gravity { 9.8 }; // ok: 9.8 是常量表达式
    constexpr int sum { 4 + 5 };      // ok: 4 + 5 是常量表达式
    constexpr int something { sum };  // ok: sum 是常量表达式

    std::cout << "Enter your age: ";
    int age{};             
    std::cin >> age;

    constexpr int myAge { age };      // 编译报错: age 不是常量表达式
    constexpr int f { five() };       // 编译报错: five() 的返回值不是常量表达式

    return 0;
}

最佳：
任何在初始化之后不会修改、并且初始值在编译时就能确定的变量，都应声明为 constexpr。
任何在初始化之后不会修改、但初始值在编译时无法确定的变量，则应声明为 const。



const 和 constexpr 的函数参数
普通函数调用是在运行时求值的。
这意味着即使实参本身是编译时常量，函数参数也会被当作运行时常量来处理。


int add(int x)
{
return x;
}

int main()
{
   add(5);     //即使5为编译时常量，但是编译时add 并没有运行所以x还是没有值
               //此时x为运行时常量
}



常量表达式究竟何时被求值？
当上下文要求常量表达式的结果必须是一个常量时（例如用于编译时常量的初始化），编译器就会对常量表达式进行求值：

constexpr int x { 3 + 4 }; // 3 + 4 必然在编译时计算
const int x { 3 + 4 };     // 3 + 4 必然在编译时计算


1. 函数的 `constexpr`：是**能力许可**，这个函数可以在编译时被求值
2.变量的constexpr 是要求 要求右值必须算出






常量折叠（Constant folding）
 但是 `std::cout << ...` 是**调用输出运算符函数**，这个操作会产生**运行时副作用**：向控制台打印文字。
 C++ 常量表达式规则：**常量表达式不能带有运行时副作用（IO、修改变量、分配内存等）**。
只要表达式里面包含 IO 操作，整个表达式直接就不是常量表达式。
答案通常是“会”。编译器很早就具备了优化常量子表达式的能力，
即使整个完整表达式是运行时表达式也是如此。这个优化过程被称为“常量折叠”。






*/