//Switch语句基础
/*
将许多if语句串起来，难以阅读 又效率低下

switch语句背后的思想很简单：
计算表达式（有时称为条件）以产生值。
如果表达式的值等于任何case标签之后的值，
则执行匹配的case标签后面的语句。
如果找不到匹配的值并且存在默认标签，
则改为执行默认标签之后的语句。

switch (x)
    {
        case 1:
            std::cout << "One";    
            return;
        case 2:
            std::cout << "Two";
            return;
        case 3:
            std::cout << "Three";
            return;
        default:
            std::cout << "Unknown";
            return;
    }
输入x 挨个判断是不是x后面的值都不是则 defaultl;
做多个选择比较时，首选switch语句而不是多个if-else。



使用switch语句:
switch(表达式)
{
  case 取值：
    .....;
    return;
  case 取值2:
  .....
  default:
    .....;
    return;
}

*******条件必须求值为整数类型或枚举类型;转换的也可以


1.case标签
使用case关键字声明，后跟常量表达式。
会执行符合条件的后面的语句，按顺序执行


2.default标签
如果条件表达式与任何case标签都不匹配，
并且存在default标签，则从default标签之后的第一条语句开始执行。
default标签是可选的，每个switch语句只能有一个default标签。
按照惯例，default情况会放在switch块的最后。


3.没有匹配的case标签，也没有default标签
则不会执行switch内的任何语句。






break关键字：
在switch语句中，我们使用return来终止，但是switch之后的语句也不会执行了
所以使用break语句来完成switch执行，并且执行下一条语句
void printDigitName(int x)
{
    switch (x) // x 是 3
    {
        case 1:
            std::cout << "One";
            break;
        case 2:
            std::cout << "Two";
            break;
        case 3:
            std::cout << "Three"; // 从这里开始执行
            break; // 跳出switch代码块
        default:
            std::cout << "Unknown";
            break;
    }

    // 从这里继续执行
    std::cout << " Ah-Ah-Ah!";
}



}





*/