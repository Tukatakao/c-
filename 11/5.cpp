//默认参数
/*
默认参数是为函数参数提供的默认值。

void print(int x, int y=10) // 10 是默认的参数值
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

如果调用时，调用方传入了对应值，则以传递的值为准。不提供则使用默认值
请注意，必须使用等号来指定默认参数。使用括号或大括号不符合语法：
默认参数由编译器在函数调用点处理。
比如print(3);会被重写为 
print(3,4),再传递；



何时使用默认参数：
当函数需要合理默认值，
又希望调用方可以跟据需要覆盖该值时。



多个默认参数：
函数可以具有多个具有默认值的参数：
void print(int x=10, int y=20, int z=30)
{
}
print(1, 2, 3); // 全部显式传值
print(1, 2); // z 使用默认参数
print(1); // y z 使用默认参数
print(); // x y z 使用默认参数
没传入的将会使用默认值；
但是不支持print(, , 3)
如果一个参数使用了默认值，那么后面的所有都得用默认认知
因此定义时，默认值也要放在后面
void print(int x=10, int y); // 不允许





无法重新声明默认参数：
同一文件中，默认参数只能声明一次
因此我们要在前向声明中声明
而不是函数定义中声明
在foo.h中：
void print(int x, int y=4);
在main.cpp中
void print(int x, int y)
{
函数体；
}





默认参数和函数重载：
可以重载具有默认参数的函数：
void print(std::string)
{
}
void print(char=' ')
{
}
print() 是第二个
print("随便什么")  是第一个




具有默认值的重载函数
void print(int x);
void print(int x, int y = 10);
void print(int x, double y = 20.5);
上面这样的声明可以通过编译；
然而这会导致不明确匹配的风险
比如
print(1);
可能是第一个 第二个 第三个

*/