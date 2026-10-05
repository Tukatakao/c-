//代码测试简介
/*

代码编译好了，看起来也能运行。
如果只用一次，工作基本上做完了
但是很多代码，要求在不同的情况下都可以使用，就需要一些主动测试：
程序能对一组输入正常工作，并不意味着它在所有情况下都能正确工作。
软件测试（也称为软件验证）是确定软件是否实际按预期工作的过程。




测试所面临的挑战:
#include <iostream>

void compare(int x, int y)
{
    if (x > y)
        std::cout << x << " is greater than " << y << '\n'; // 情况 1
    else if (x < y)
        std::cout << x << " is less than " << y << '\n'; // 情况 2
    else
        std::cout << x << " is equal to " << y << '\n'; // 情况 3
}

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another number: ";
    int y{};
    std::cin >> y;

    compare(x, y);

    return 0;
}
这是一个测试输入的两个数是否相等的程序，
假设输入是4字节整数，那么就有18446744073709551616（约1.8千亿亿）个可能的输入，我们不可能每种情况都输入，然后测试一遍。
直觉告诉我们，假如 输入x>y的一种情况 可以运行，那么所有x>y的情况都正常
所以 只需要三次
x>y
x<y
x=y
就可以有较多的把握该程序可以正常运行。
我们可以用类似的技巧；




在小代码段中测试程序：
相比于写完所有代码再测试，我们可以一小段一小段测试；
假如不这么干，全都写完再测试的话，出了问题也不好确定哪里出问题了;
即使各个环节测试正常，但是整体依旧可能出故障，但是风险已经被降到了最低；
写完函数或者类时，立即编译并测试；
这种以部分代码为单位测试叫单元测试；





非正式测试：
一种方法是 在编写时进行非正式测试。
在编写代码单元时，可以编写一些代码来测试刚刚添加的单元，
测试完成后再删掉；
bool isLowerVowel(char c)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

int main()
{
    // 临时的测试代码，测试函数是否工作
    std::cout << isLowerVowel('a') << '\n'; // 应该产出 1
    std::cout << isLowerVowel('q') << '\n'; // 应该产出 0

    return 0;
}
临时给予参数，测试输出是否正常。






保留测试代码：
临时编写测试代码快速而简单，但是没考虑后续再次测试的情况，
比如给函数多加了功能什么的。
可以将测试代码写成函数，而不是临时测试再删掉。
bool isLowerVowel(char c)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}
void testVowel()               //测试函数
{
    std::cout << isLowerVowel('a') << '\n'; // 临时测试代码，应该产出 1
    std::cout << isLowerVowel('q') << '\n'; // 临时测试代码，应该产出 0
}
需要的时候，main函数中可以调用测试函数，以完成测试目的；








自动化测试函数：
上述测试的问题是，我们要手动调用函数，还要记住什么输出时正常的，并进行比较。

我们也可以把测试答案包含进测试函数。
bool isLowerVowel(char c)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

// 如果对应的测试样例失败，返回对应的编号, 全部测试通过，返回0
int testVowel()
{
    if (!isLowerVowel('a')) return 1;         //输入a返回false是错的， 
    if (isLowerVowel('q')) return 2;          //输入q返回true是错的，


    return 0;                                 //a返回true b返回false 就会到这一步

}
在main函数中判断该函数的返回值是不是0 或者是不是1或2就知道哪里出错了



单元测试框架：
以上用一个函数测试 非常常见有用，因此有一些完整的框架(称之为单元测试框架)用来简化这个过程
这涉及一些第三方软件。


集成测试：
每个单元测试都通过，就可以进行集成测试(集成到程序中并测试)
通常，集成后运行几次就行了。



*/