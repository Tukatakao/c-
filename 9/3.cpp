//常见的语义错误
/*
语法错误：语法不对时，编译器会提示
语义错误：程序出现非预期结果。

介绍常见语义错误




1.条件逻辑错误：
错误编写条件或循环的逻辑：


int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    if (x >= 5) // oops, 错误的使用 >= 而不是 >
        std::cout << x << " is greater than 5\n";

    return 0;
}
上述错误就是当输入5时 也能输出5大于5
也就是算法写错了；

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    // oops, 使用了 > 而不是 <
    for (int count{ 1 }; count > x; ++count)
    {
        std::cout << count << ' ';
    }

    std::cout << '\n';

    return 0;
}
上述错误是 循环条件写错了 
输入的是循环次数
count要小于设定的x时才输出 








2.死循环:

int main()
{
    int count{ 1 };
    while (count <= 10) // 这个条件语句永远不会是 false
    {
        std::cout << count << ' '; // 这一行会一直重复执行
    }
 
    std::cout << '\n'; // 这一行不会执行到

    return 0; // 这一行不会执行到
}
没有递增count变量 ，所以count<=10 会一直满足，循环一直打印




int main()
{
    for (unsigned int count{ 5 }; count >= 0; --count)
    {
        if (count == 0)
            std::cout << "blastoff! ";
        else
          std::cout << count << ' ';
    }

    std::cout << '\n';

    return 0;
}
count是无符号整数，count永远大于0，循环一直打印







3.循环迭代次数错误：
循环次数不正确：
int main()
{
    for (int count{ 1 }; count < 5; ++count)
    {
        std::cout << count << ' ';
    }

    std::cout << '\n';

    return 0;
}
想打印12345 但是当count累加到5时 count < 5就为false
所以 count应该是 count <= 5;




4.运算符优先级不正确：
int main()
{
    int x{ 5 };
    int y{ 7 };

    if (!x > y) // oops: 运算符优先级问题
        std::cout << x << " is not greater than " << y << '\n';
    else
        std::cout << x << " is greater than " << y << '\n';

    return 0;
}
not运算符大于>
所以会(!x)>y;
会将非0 的x变为0




5.浮点类型的精度问题
int main()
{
    float f{ 0.123456789f };
    std::cout << f << '\n';

    return 0;
}
数字会被稍微舍入，输出为0.123457


int main()
{
    double d{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 }; // should sum to 1.0

    if (d == 1.0)
        std::cout << "equal\n";
    else
        std::cout << "not equal\n";

    return 0;
}
浮点数运算越多，积累的舍入误差越多；






6.整数除法：
int main()
{
    int x{ 5 };
    int y{ 3 };

    std::cout << x << " divided by " << y << " is: " << x / y << '\n'; // 整数除法

    return 0;
}
5和3都是整数，所以是整数除法，最终算出来的值是1，小数部分舍去了。






7.意外的空语句：
void blowUpWorld()
{
    std::cout << "Kaboom!\n";
} 

int main()
{
    std::cout << "Should we blow up the world again? (y/n): ";
    char c{};
    std::cin >> c;

    if (c=='y');       // 意外的空语句
        blowUpWorld(); // 所以这一行会执行到，因为它不是if语句的一部分        
    return 0;
}
由于if后面有个分号空语句，所以条件语句的执行语句被挤出if条件
blowUpWorld()始终会被执行;






8.需要复合语句时不使用复合语句
void blowUpWorld()
{
    std::cout << "Kaboom!\n";
} 

int main()
{
    std::cout << "Should we blow up the world again? (y/n): ";
    char c{};
    std::cin >> c;

    if (c=='y')
        std::cout << "Okay, here we go...\n";
        blowUpWorld(); // oops, 这一行也会永远执行到
 
    return 0;
}
if后面只能是一个单语句
所以要执行多个语句    要用函数块包起来；


*/