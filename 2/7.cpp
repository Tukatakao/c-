// 类对象宏：替换文本作用
// 分为两类：
// #define wodemingzi                无替换文本
// #define wodemingzi wangguize      有替换文本  

// #define 标识符 替换文本 //预处理的内容
// 如#define wodemingzi "wangguize"

#include <iostream>
#define wodemingzi "wangguize"

int main()
{
    std::cout << wodemingzi << std::endl;
    return 0;
}

// 预处理器就开始吧代码中的wodemingzi都替换成wangguize
// 如果是 #define wodemingzi 那就是把所有都替换成空，也就是删除