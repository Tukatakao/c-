//std::cin和处理无效输入
/*
std::cin输入非常自由，可以输入任何内容，用户很容易输入不符合预期的内容
一个良好的程序会预判用户的输入，并且优雅的处理




std::cin、缓冲区和提取：
std::cin >> 是如何工作的：
操作符>> 将用户输入放入变量，成为提取。
当用户输入内容时，数据会被放入std::cin内部的缓冲区，
缓冲区是临时存储的地方，在这里，用户输入被暂时保存，并且等待被提取到变量中。
使用提取操作符时，会进行以下过程：
1.如果缓冲区已有数据，则将该数据进行提取。
2.如果缓冲区不包含数据，则要求用户输入，并且用户点击enter时，在缓冲区放置"\n"字符
3.操作符>>将尽可能多的数据从输入缓冲区提取到变量中(忽略任何前导空格字符）
4.无法提取的任何数据都留在缓冲区，供下一次提取使用

例如：
int x{};
std::cin >> x;
如果输入5a
则提取5 将a\n保留在缓冲区
如果只输入a
则提取失败，至少要能提取一个字符



验证输入：
检查用户输入是否符合程序期望。
三种基本输入验证方法：
用户边输入边校验：
1.阻止用户输入无效的字符
用户输入完成后再校验:
2.将用户输入的所有内容保存到字符串中，然后验证字符串是否有效。如果有效，再将字符串转换成最终格式。
3.让用户任意输入，使用std::cin和operator»提取数据，同时处理提取失败的情形



1.一些高级的图形用户界面和高级文本界面允许输入时边输入边验证。
程序员会提供一个验证函数，该函数接受用户目前为止的输入，
输入有效返回true，无效返回false，每次按下按键都会调用此函数，
返回为true，则接受刚才的按键，返回为false则丢弃。
不幸的时std::cin 不支持这种类型的验证


2.字符串对可输入字符没有限制，使用>>将输入提取到字符串中(会跳过前导空白字符，到下一个空白字符停止)
提取完成后，程序解析字符串，判断是否有效。
但是解析字符串并将其转换为其他类型比较困难，这种方式只在少数使用。


3.最常见的做法是就用std::cin >> 让他俩尽可能提取，然后在提取失败时处理后果。








示例程序：
double getDouble()
{
    std::cout << "Enter a decimal number: ";
    double x{};
    std::cin >> x;
    return x;
}
 
char getOperator()
{
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char op{};
    std::cin >> op;
    return op;
}
 
void printResult(double x, char operation, double y)
{
    switch (operation)
    {
    case '+':
        std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        std::cout << x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        std::cout << x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " is " << x / y << '\n';
        break;
    }
}
 
int main()
{
    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };
 
    printResult(x, operation, y);
 
    return 0;
}


无效文本输入的类型：
1.输入提取成功，但输入对程序没有意义（例如，输入“k”作为数学运算符）。
2.输入提取成功，但用户后续输入了其他输入（例如，输入“*q hello”作为数学运算符）。
3.输入提取失败（例如，尝试在数字输入中输入“q”）。
4.输入提取成功，但输入数值发生了溢出。



错误情况1：提取成功，但输入无意义：
Enter a decimal number: 5
Enter one of the following: +, -, *, or /: k
Enter a decimal number: 7
预算符输入的时k 可以提取，但是没有意义
没有case是k 所以没有任何输出。


结局方案很简单：进行输入验证，通常有3部分
1，检查用户的输入是否是我们所期望的
2. 如果是的话，执行后续流程
3. 如果不是，提示用户，并让用户进行重试

while (true) // 无限循环，直到用户输入有效的数据
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char operation{};
        std::cin >> operation;

        // 检查用户输入是否有效
        switch (operation)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return operation; // 将有效的输入返回
        default: // 否则提示用户输入有误
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
无限循环直到输入有效数据








错误情况2：提取成功，但有多余的输入：

Enter a decimal number: 5*7
此时5*7\n在缓冲区
将5提取到x,
将*提取到op,
提取y时，
由于用户在输入op时没有机会输入并enter，
所以第二句和第三句在同一行


解决办法：忽略输入中的任何无关字符
std::cin.ignore(100, '\n');  // 清空缓存中的100个字符，或者直到一个 '\n' 被清除
前面是忽略的最长长度，后面是结束的标志
如果超过100个就会失效
但是可以定制
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
可以包装在函数里，


*/
