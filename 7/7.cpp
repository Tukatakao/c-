//外部链接和变量前向声明
/*
具有外部链接的标识符既可以从定义它的文件中看到，也可以从其他代码文件中使用（通过前向声明）。


默认情况下，函数具有外部链接:
函数可以跨文件使用，但是要放前向声明

具有外部链接的全局变量：也叫外部变量
使用extern关键字：
extern const int g_y { 3 };

内部链接的叫内部变量


也就是说int x;全局变量 跨文件可用 默认的就是全局变量
static int x；内部变量

const int x；内部变量 默认的
extern const int x;外部可用

函数同第一种；

通过extern关键字进行变量前向声明:
但是 你可以在很多地方int x；
因为外部链接只是属性，并不是类型，相当于一个接口
只有你
extern int x； 表示去寻找名叫x的全局变量



extern关键字在不同的上下文中具有不同的含义：
在某些上下文中，extern意味着“为该变量提供外部链接”。在其他上下文中，extern意味着“这是在其他地方定义的外部变量的前向声明”。
函数前向声明不需要extern关键字——编译器能够根据是否提供函数体来判断您是在定义新函数还是在进行前向声明。


非常量(不是const)默认是外部变量；
extern 进行前向声明；
初始化不用extern；

常量(const）默认是内部变量；自带static
extern进行初始化，和前向声明（看后面有没有数值）

函数默认是外部；
前向声明直接声明；

1和3内部要用static；




int g_x;                       // 定义未初始化的外部全局变量 (默认初始化为0)
extern const int g_x{ 1 };     // 定义初始化了的 const 外部 全局变量 
extern constexpr int g_x{ 2 }; // 定义初始化了的 constexpr 外部 全局变量

// 前向声明
extern int g_y;                // 前向声明 非常量 全局变量
extern const int g_y;          // 前向声明 const 全局变量
extern constexpr int g_y;      // 不被允许: constexpr 变量 不能被前向声明




*/
