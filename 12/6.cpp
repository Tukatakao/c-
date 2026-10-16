//通过常量左值引用传递函数参数

/*
上一章讲的是
把非const变量传到非const引用
以达到节省存储，可以直接操作原始数据的目的


现在我们使用const引用：
他能绑定const变量 或者 非const变量
或者const右值

void printValue(const int& y) // y 是常量引用
{
    std::cout << y << '\n';
}

int main()
{
    int x { 5 };
    printValue(x); // ok: x 是可修改的左值

    const int z { 5 };
    printValue(z); // ok: z 是不可修改的左值

    printValue(5); // ok: 5 是右值

    return 0;
}
并且在函数内 参数是const
可以享受引用带来的好处，也可以保证被引用的不会被
不小心修改；



void addOne(const int& ref)
{
    ++ref; // 不被允许: ref 是 const
}
函数内ref是const 不管引用的是啥
函数块内都不可更改；






混合使用按值传递与按引用传递参数：
可以混合使用：
一些参数按值 一些参数引用
void foo(int a, int& b, const std::string& c)
{
}

int main()
{
    int x { 5 };
    const std::string s { "Hello, world!" };

    foo(5, x, s);

    return 0;
}







何时使用（常量）引用传递参数：
1.避免对大体量参数的昂贵复制时候，可以使用
2.如果参数只是基本类型，可以直接按值传递



对于函数参数，在大多数情况下，首选std::string_view而不是const std::string&：
对于字符串：
我们一般不使用引用，而是使用视图：

*/