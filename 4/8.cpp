// 布尔变量
/*
布尔值就是false和true。




1。声明
bool a;


2.初始化
bool a { true };
bool b { false };
b1 = false;
bool b3 {};    ///默认初始化是false


逻辑NOT运算符（！）可以用于将布尔值从true翻转为false，或从false翻转为true：
bool a1 { !false }; 也就是true
//bool值存储的时候true是1，false是0；


3.打印bool值
打印布尔值时，std::cout用0表示false，用1表示true：
std::cout << true; 输出1


如果希望std::cout打印“true”或“false”，而不是0或1，则可以使用std::boolalpha。下面是一个示例：
#include <iostream>

int main()
{
    std::cout << true << '\n';                                        //输出1
    std::cout << false << '\n';                                       //输出0

    std::cout << std::boolalpha; // 以  true ， false 格式打印bool      //修饰
            
    std::cout << true << '\n';                                         //输出true或者flase
    std::cout << false << '\n';
    return 0;
}







4.整数到bool转换
列表初始化不允许将整数转化成bool；
bool a { 4 }；   //会报错
拷贝初始化可以 
>0  转化为true
=0  转化为false





5。输入bool值





//

#include <iostream>

int main()
{
	bool b{}; // 列表初始化默认为 false
	std::cout << "Enter a boolean value: ";
	std::cin >> b;
	std::cout << "You entered: " << b << '\n';

	return 0;
}
Enter a Boolean value: true
You entered: 0
//


使用std::cin输入bool值时，时采用的0和1 ，所以如果填true或false，都会读取失败，静默赋值false，输出位0

要允许std::cin接受”false”和”true”作为输入，必须启用std::boolalpha选项：
#include <iostream>

int main()
{
	bool b{};
	std::cout << "Enter a boolean value: ";

	// 允许用户输入 'true' or 'false' 作为bool变量的值
	// 大小写敏感, True or TRUE 都不行
	std::cin >> std::boolalpha;                              //启用输出转换 std::cout << std::boolalpha
	std::cin >> b;

	std::cout << "You entered: " << b << '\n';

	return 0;
}
启用std::boolalpha后将仅接受小写的”false”或”true”作为输入，不接受大写字母






6.bool返回值
布尔值通常用作判断某些条件是否为真的函数的返回值。此类函数通常以is（例如isEqual）或has（例如hasCommonDivisor）开头命名。
返回的是true or flase



bool isEqual(int x, int y)
{
    return (x == y);                        // 操作符== ， x 等于y，返回true，否则返回false
}








*/
