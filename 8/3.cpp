// 常见的if语句问题
/*



嵌套的if语句和悬空的else问题:
 if (x >= 0) // 外层if条件
        // 这样的嵌套if代码样式，非常差
        if (x <= 20) // 内层if语句
            std::cout << x << " is between 0 and 20\n";

如果此时在后面加上else语句：
 if (x >= 0) // 外层if条件
        // 这样的嵌套if代码样式，非常差
        if (x <= 20) // 内层if语句
            std::cout << x << " is between 0 and 20\n";

    // 这个else语句，属于哪个if条件呢？
    else
        std::cout << x << " is negative\n";
此时else会与最后一个尚未匹配的if配对 也就是内部if
所以 最好将内部的if语句连同他的else放在一个块中
 if (x >= 0)
    {
        if (x <= 20)
            std::cout << x << " is between 0 and 20\n";
        else // 与内层if语句对应
            std::cout << x << " is greater than 20\n";
    }
    else // 与外层else语句对应
        std::cout << x << " is negative\n";
内外else对应明确




展平嵌套if语句：
嵌套的if语句通常可以通过重新组织逻辑来展平；
就是把代码块里的整合在外层
if()
else if ()
else ...

或者往后延续
if()
else if ()
else if ()
else ..




空语句（Null statements）：
空语句是仅由分号组成的表达式语句：

if (x > 10)
    ; // 这是一个空语句
不执行任何此操作，但是有些时候语言要求必须有语句，所以空语句独占一行；


if (nuclearCodesActivated());
    blowUpTheWorld();
这里if末尾多打了一个分号
等同于
if (nuclearCodesActivated())
    ;             //这个单独空语句会被识别为if的执行语句
blowUpTheWorld(); //这个会被挤出去 成为外部的语句




条件表达式中，运算符== 与 运算符=：
 if (x = 0) // oops, 这里使用赋值，而不是相等性测试
        std::cout << "You entered 0\n";
    else
        std::cout << "You entered 1\n";
==才是判断 =是赋值 如果赋值的是0 就是false 赋值为非0则视为true 

*/