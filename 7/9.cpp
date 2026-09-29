//静态局部变量
/*
static 的目前两种:
1.全局变量具有静态存储期（static duration），这意味着它们在程序启动时创建，在程序结束时销毁。
2.static关键字如何让全局标识符具有内部链接，这意味着标识符只能在定义它的文件中使用。

将探索将static关键字应用于局部变量时的作用：
局部变量在默认情况下具有自动存储期，这意味着它们在定义点创建，并在退出代码块时销毁。
对局部变量使用static关键字会将其存储期从自动存储期更改为静态存储期。
也就是static加上之后 不会再在跟原来一样 跟随代码块在栈中创建销毁
而是在开始时分配好内存，创建时赋值，程序退出才销毁


void incrementAndPrint()
{
    int value{ 1 }; // 自动存储期（默认））
    ++value;
    std::cout << value << '\n';
} // value变量被销毁

int main()
{
    incrementAndPrint();         //value是局部变量 每次调用都会创建销毁
    incrementAndPrint();
    incrementAndPrint();

    return 0;
}


void incrementAndPrint()
{
    static int s_value{ 1 }; // 使用static，将s_value变为静态存储期，该变量只会初始化一次
    ++s_value;
    std::cout << s_value << '\n';
} // s_value 没有被销毁，但不可再被访问，因为已经离开了作用域

int main()
{
    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();

    return 0;
}
这次 不会再销毁 但是每次调用 value值都会加1
这个变量是在程序启动时被创建的 并且由于没赋值（也就是没=某个值 未显示初始化） 默认为0或者constexpr值,然后再第一次执行定义时才进行初始化


静态局部常数（const）：
就是 static 局部变量 初始化位常数；也就是const 不能修改变成一个常数  
如果程序频频需要一个常量数值，就可有定义一个static const 这样调用时就不会每次都创建销毁，而是重用,省资源

不要使用静态局部变量来控制程序行为：
就是 如果静态局部变量初始化为bool值
并用于if 
这样可以控制
但是这样会使得代码不好理解
比如
static bool = true；
if(bool)
 bool = false
else
 ...;

这样当两次调用这个条件判断时 第一次会执行true的语句
但是 true的语句是把bool改成false
但是因为是static值 所以第二次反而会执行false语句

最佳实践

避免静态局部变量，除非该变量从不需要重置。


*/