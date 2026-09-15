//类型转换
/*


1.隐式类型转换：
当类型不匹配
编译器在未经我们明确要求的情况下进行的类型转换，称为隐式类型转换



2.类型转换会生成新值
类型转换实际上并不会更改原始值或其类型。相反，要转换的值被用作输入，
转换操作会产生一个目标类型的新值,而不会改变原本的值


由于将浮点值转换为整数值会导致小数部分被丢弃
所以会警告。
某些类型转换始终是安全的（例如int到double），而另一些可能会导致值在转换过程中发生改变（例如double到int）。不安全的隐式转换通常会生成编译器警告，
或（在列表初始化的情况下）产生错误。



int main()
{
    double d { 5 }; // okay: int 转 double 安全
    int x { 5.5 }; // error: double 转 int 不安全

    return 0;
}


显式类型转换。显式类型转换允许我们（程序员）明确地告诉编译器将值从一种类型转换为另一种类型，并且我们对转换结果承担全部责任
（这意味着，如果转换导致值的丢失，那是我们自己的责任）。
要执行显式类型转换，在大多数情况下我们会使用static_cast操作符。
其语法看起来有点特别：
static_cast<新类型>(表达式)



#include <iostream>

void print(int x)                   //这里要求传入int
{
	std::cout << x << '\n';
}

int main()
{
	print( static_cast<int>(5.5) ); // 显示的将 double 值 5.5 转换为 int

	return 0;
}




#include <iostream>

int main()
{
    char ch{ 97 }; // 97 是 ASCII 码 'a'
    std::cout << ch << " has value " << static_cast<int>(ch) << '\n'; // 将 ch 转换为 int

    return 0;
}
直接打印ascii码的值；





将无符号数字转换为有符号数字
#include <iostream>

int main()
{
    unsigned int u { 5 };
    int s { static_cast<int>(u) }; // 将变量 u 的值转换为 int

    std::cout << s << '\n';
    return 0;

*/
