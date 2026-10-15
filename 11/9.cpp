//非类型模板参数
/*
前面的模板函数
我们都是里面的参数类型未固定

但是也可以又非类型的模板参数
可以是：
整型
枚举类型
std::nullptr_t
浮点类型（自C++20）
指向对象的指针或引用
指向函数的指针或引用
指向成员函数的指针或引用
字面值类类型（自C++20）




定义我们自己的非类型模板参数：
template <int N> // 声明一个非类型模板参数，类型是 int，名称是 N
void print()
{
    std::cout << N << '\n'; // 在这里使用N
}
这里的N不是一个类型，而是一个数据
也就是从现在开始，我们自定义的可以不仅仅只是类型了
还可以是函数体里的内容






非类型模板参数有哪些用途？
不要给函数参数constexpr
函数参数本质是变量


double getSqrt(double d)
{
    assert(d >= 0.0 && "getSqrt(): d must be non-negative");

    // 上面的assert在非debug环境可能不会编译进来
    if (d >= 0)
        return std::sqrt(d);

    return 0.0;
}

int main()
{
    std::cout << getSqrt(5.0) << '\n';
    std::cout << getSqrt(-5.0) << '\n';

    return 0;
}
是这样的：
1.对于第二个调用，传入的是负数，所以会触发断言
2.但是这个错误只有运行时才能看到
3.因为assert只有运行时输入负数才能触发
4.如果我们使用static_assert则可以在编译期间，将static_assert编译
5.但是static_assert()中的表达式要求必须是static
6.但是函数参数又不能是constexpr
7.所以可以使用非类型的模板参数

写成这样
template <double D> // 需要 C++20 才能使用浮点非类型模板参数
double getSqrt()
{
    static_assert(D >= 0.0, "getSqrt(): D must be non-negative");

    if constexpr (D >= 0) // 忽略这里的 constexpr
        return std::sqrt(D);

    return 0.0;
}
int main()
{
    std::cout << getSqrt<5.0>() << '\n';
    std::cout << getSqrt<-5.0>() << '\n';

    return 0;
}
这样就可以在编译期测试static_assert()；










非类型模板参数的隐式转换可选：
非类型的模板参数允许隐式转换：
template <int N> // int 非类型模板参数
void print()
{
    std::cout << N << '\n';
}

int main()
{
    print<5>();   // 无需转换
    print<'c'>(); // 'c' 被转为 int, 打印 99

    return 0;
}




如果定义了俩相同名称的模板：
会导致不匹配
emplate <int N> // int 非类型模板参数
void print()
{
    std::cout << N << '\n';
}

template <char N> // char 非类型模板参数
void print()
{
    std::cout << N << '\n';
}

int main()
{
    print<5>();   // 不明确的匹配 int N = 5 与 char N = 5
    print<'c'>(); // 不明确的匹配 int N = 99 与 char N = 'c'

    return 0;
}










使用auto (C++17)对非类型模板参数进行类型推导：
同样的非类型的模板参数也可以使用auto
template <auto N> // 针对模板参数的类型，让编译器从调用自动推导
void print()
{
    std::cout << N << '\n';
}

int main()
{
    print<5>();   // N 被推导为 int `5`
    print<'c'>(); // N 被推导为 char `c`

    return 0;
}

*/