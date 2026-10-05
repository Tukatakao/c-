//代码覆盖率
/*
代码覆盖率用于描述测试时执行了多少程序源代码。
也就是测试了多少源代码；
这个有很多不同的衡量方式；
介绍几种：




语句覆盖率:
代码中被测试例程执行过的语句所占的百分比。

int foo(int x, int y)
{
    int z{ y };
    if (x > y)
    {
        z = x;
    }
    return z;
}
这个函数测试时输入(1,0)调用，所有语句会被完全覆盖；
bool isLowerVowel(char c)
{
    switch (c) // 语句 1
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true; // 语句 2
    default:
        return false; // 语句 3
    }
}
至少两次才能调用才能测试所有语句；
一次只会执行语句2或者3；





分支覆盖率：
指已执行分支所占的百分比，每个可能的分支都会单独计数。
if有两个分支：true或false
switch可以有多个分支；
int foo(int x, int y)
{
    int z{ y };
    if (x > y)
    {
        z = x;
    }
    return z;
}
前面foo(1,0)的调用虽然提供了语句全覆盖，但是分支没有全覆盖
我们可以foo(0,1)再次测试另一个分支；



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
两次调用才有100%分支覆盖率。
一次测试return true；
一次测试return false；
多个case对应一组执行语句时，只需要为其中一个case编写测试代码即可；




void compare(int x, int y)
{
	if (x > y)
		std::cout << x << " is greater than " << y << '\n'; // 情况 1
	else if (x < y)
		std::cout << x << " is less than " << y << '\n'; // 情况 2
	else
		std::cout << x << " is equal to " << y << '\n'; // 情况 3
}
需要三次调用才能100%分支覆盖率。






循环覆盖率：
如果代码中有循环，则应确保在循环0次，1次，2次都能正常工作，
如果2次可以工作，通常大于2时所有迭代都能工作。
因此这三次测试涵盖了所有关键可能性；


void spam(int timesToPrint)
{
    for (int count{ 0 }; count < timesToPrint; ++count)
         std::cout << "Spam! ";
}
确保调用spam(0)spam(1)spam(2)都能正常工作；







测试不同类别的输入：
编写有参数的函数时，或者需要用户输入时，需要考虑不同类别的输入；
我们用“类别”来表示具有类似特征的输入；
下面是类别测试的一些基本准则：
对于输入是整数，请确保考虑函数如何处理负值、零值和正值。如果可能，还应该检查溢出。
对于输入是浮点数，请确保考虑函数如何处理存在精度问题的值。
比如0.1 -0.1 0.6 -0.6 
对于输入是字符串，请确保考虑函数如何处理空字符串、含字母和数字的字符串、包含空格的字符串（前导、尾随和内部空格），以及全部为空格的字符串。

*/