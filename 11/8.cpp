//具有多个模板类型的函数模板
/*


前面编写了以下模板来计算最大值
template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}
其中T是模板类型
我们max<>(); 
尖括号中填入类型或者隐式实例化都可以用

但是如果我们隐式实例化时
std::cout << max(2, 3.5) << '\n';  // 编译失败
我们未指定类型
所以他将推导
第一个int 第二个时double
但是我们模板里俩参数的类型是一样的，因此会报错

我们有三种方法：


1.使用static_cast将参数转化为对应的类型
std::cout << max(static_cast<double>(2), 3.5)
这样俩参数都是double
编译器就能推导了


2.提供显式类型模板参数
std::cout << max<double>(2, 3.5) << '\n';
这样2就会被隐式转换为double


3.具有多个模板类型参数的函数模板
template <typename T, typename U> // 使用两个模板类型参数 T 和 U
T max(T x, U y) // x 是类型 T, y 是类型 U
{
    return (x < y) ? y : x; // uh，这里有个隐式的窄化转换
}
这里直接定义俩占位符，以说明x和y的类型可以分别独立解析


但是这样会产生问题，函数返回类型不一定会是什么
我们可以使用auto
让编译器根据返回的值自动推导
也就是
template <typename T, typename U>
auto max(T x, U y)
{
    return (x < y) ? y : x;
}
这样俩参数的类型都自由了
并且返回值也可以根据情况自己推导了







函数模板简化:
C++20引入了auto的新用法
auto max(auto x, auto y)
{
    return (x < y) ? y : x;
}
直接就是一个简写函数模板

也不需要定义模板参数



*/