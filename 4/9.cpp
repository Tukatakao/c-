// IF条件
/*

1.IF：
if (条件表达式)
    true_对应的语句;
2.if-else:
if (条件表达式)
    true_对应的语句;
else
    false_对应的语句;
3.串联if语句


有时候，我们需要依次检查多个条件是否为真。我们可以通过
将if语句（或if-else）串联到前一个if-else之后来实现，如下所示：

#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    if (x > 0)
        std::cout << "The value is positive\n";
    else if (x < 0)
        std::cout << "The value is negative\n";
    else 
        std::cout << "The value is zero\n";

    return 0;


    其实是:
    if (X>0)
        std::cout <<
        else 
            if (x<0)
            ...
            else
            ....
    均是满足if 执行if 不满足，if里的全都跳过。。。。才进入else








4.BOOL返回值和if语句
#include <iostream>
 
// x与y相等返回true, 不然返回false
bool isEqual(int x, int y)
{
    return (x == y); // 操作符== ， x 等于y，返回true，否则返回false
}
 
int main()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;
 
    std::cout << "Enter another integer: ";
    int y {};
    std::cin >> y;
    
    if (isEqual(x, y))
        std::cout << x << " and " << y << " are equal\n";
    else
        std::cout << x << " and " << y << " are not equal\n";

    return 0;
}

   //条件表达式是对bool返回值的调用




5.IF语句和提前返回

不是函数中最后一个语句的return语句会导致函数提前返回。
这样的语句会使函数在执行到return时立即返回给调用方
（在函数正常执行完毕之前就返回了，因此称为”提前”返回）。

void print()
{
    std::cout << "A";

    return; // 函数在这里返回

    std::cout << "B"; // 这行不会执行到
}


#include <iostream>

// 返回函数 x的绝对值
int abs(int x) 
{
    if (x < 0)
        return -x; // 提前返回 (当 x < 0)

    return x;
}

int main()
{
    std::cout << abs(4) << '\n'; // 打印 4
    std::cout << abs(-3) << '\n'; // 打印 3

    return 0;
}










*/



