//std::string_view简介


/*
在初始化 s 时，C 风格的字符串字面值 “Hello, world!” 会被复制到为 std::string s 分配的内存中。
与基本类型不同，std::string 的初始化和复制是比较慢的。

#include <iostream>
#include <string>

void printString(std::string str)       // str 拷贝了传入的实参
{
    std::cout << str << '\n';
}

int main()
{
    std::string s{ "Hello, world!" };    // s 拷贝了初始值
    printString(s);

    return 0;
}

为了解决 std::string 初始化（或复制）开销大的问题，
C++17 引入了 std::string_view（位于 <string_view> 头文件中）。
std::string_view 提供了对已有字符串（C 风格字符串、std::string 或另一个 std::string_view）的只读访问能力，而不需要复制字符串。
“只读”的意思是我们可以访问和使用它所查看的值，但不能修改它。

把传入字符串的变量的类型改为std::string_view 那么这个类型的值就是去读那个字符串而不是复制一份
当你需要一个只读字符串时，尤其是作为函数参数时，优先使用 std::string_view 而非 std::string。
std::string s{"1"};
std::string_view sv=s;


sv="2"; 改不了s，是把sv又指向了字面量“2”，这个量存储在只读常量里，在编译时就存进去了；
s="2";  能改！改的直接是那块内存的值！！

可以使用多种不同类型的字符串来初始化 std::string_view
右值可以是“hello” 字面量 
   可以是另一个std::string
   也可以是另一个std::string_view
    
   
   
  //std::string_view s1 { "Hello, world!" }; // 使用 C 风格字符串初始化
    std::cout << s1 << '\n';

    std::string s{ "Hello, world!" };
    std::string_view s2 { s };  // 使用 std::string 初始化
    std::cout << s2 << '\n';

    std::string_view s3 { s2 }; // 使用 std::string_view 初始化
    std::cout << s3 << '\n';
正因如此当这个类型多为函数参数时也可以接受多种类型的实参：
void printSV(std::string_view str)
{
    std::cout << str << '\n';
}

int main()
{
    printSV("Hello, world!"); // 使用 C 风格字符串调用

    std::string s2{ "Hello, world!" };
    printSV(s2); // 使用 std::string 调用

    std::string_view s3 { s2 };
    printSV(s3); // 使用 std::string_view 调用
       
    return 0;
}




std::string_view 不会隐式转换为 std::string：
如果std::string_view sa={"hello"};  //sa为string_view 类型
做隐式转换不可以比如
void aaa(std:string str);
aaa(sa);  aaa的函参是string sa传入string_view,并且还没明面上写，所以是隐式，不允许！！！
std::string a=sa；  是允许的 这是显示转换      要把sa 转换成string 类型 允许！！！



std::string_view 量修改，不是更改那块内存的值，而是指向新的值
比如string a=“1”；
string_view b{a};
b="2";
//a 还是1，只不过b指向改了，与一般的修改不同


std::string_view 的字面值
默认情况下，双引号括起的字符串是 C 风格字符串。我们可以在双引号字符串之后加上 sv 后缀，
来创建类型为 std::string_view 的字符串字面值。
这样编译期就可以进行长度测量，比较省运行时性能

constexpr std::string_view：完全支持在编译时使用
因为sv本身指向的就是字面量，而字面量在编译时就确定


*/