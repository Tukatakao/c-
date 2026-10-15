//函数的类型推导
/*


int add(int x, int y)
{
    return x + y;
}

编译此函数时，return的值确定为int
然后与开头的int类型匹配；

我们因此可以用auto
它将从return的数据中自动推断；
auto add(int x, int y)
{
    return x + y;
}//编译器推断是int


但是如果有多个return，且返回的类型不同，将会错误：
auto someFcn(bool b)
{
    if (b)
        return 5; // return 类型 int
    else
        return 6.7; // return 类型 double
}


使用auto的缺点是：
在使用函数之前 必须完全定义它们，仅仅有声明在前是不够的
整个函数的声明和定义都要在调用点之前；
否则auto无法推断类型；




尾部返回类型语法：
就是可以这样写
auto hanshu1(int) -> int;
把函数返回类型写后面，这种情况下auto相当于占位符；
这样可以使得代码美观；
所有都会对齐;





类型推导不能用于函数参数的类型:
void addAndPrint(auto x, auto y)
{
    std::cout << x + y << '\n';
}
不可以用来推导函数参数；
*/