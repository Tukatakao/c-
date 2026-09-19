//std::string_view 第二部分

/*
视图类型：


所有者与查看者：
作为所有者，你要负责获取、管理并妥善处置你所拥有的对象。
作为查看者，你对所查看的对象不负任何责任，但同样也无法控制它们。


std::string 是所有者：
当一个对象被实例化时，系统会为它分配一块内存，用来存储其整个生命周期内所需使用的数据。
这块内存是为该对象预留的，并保证在对象存在期间一直存在。
这是一个安全的空间。std::string（以及大多数其他对象）会把传入的初始化值复制到这块内存中，
这样它就拥有了一份独立的值，可以随时访问和修改。
一旦复制完成，对象就不再以任何方式依赖于初始化值。

意思是变量初始化时会有一个初始化值，初始化完成这个初始化值还是传入者的，所有权会回到传入者手中，那我这个变量会受到影响。
所以初始化变量会将拷贝到新变量中，以获得所有权。

我们并不总是需要一份副本：所以会用std::string_view;
void printString(std::string str) // str 复制了传入的值
{
    std::cout << str << '\n';
}

int main()
{
    std::string s{ "Hello, world!" };
    printString(s);                      //只是输出一下就被销毁了

    return 0;
}




std::string_view 是查看者：
std::string_view 创建的是对字符串的廉价视图，而不是对字符串的昂贵副本。一旦初始化完成，就可以通过 std::string_view 来访问对应的字符串。
std::string_view 在其整个生命周期中，仍然依赖于它的初始化值。如果所查看的字符串在查看器仍在使用时被修改或销毁，就会导致意外结果或未定义行为。
std::string_view的字面值如果被更改，或者被销毁就会出问题，查看已销毁字符串的 std::string_view 有时被称为悬空视图（dangling view）。


std::string_view 最适合作为只读函数参数：
就是函数内不对其做出改变，就可以用sv
void printSV(std::string_view str) // std::string_view, 只是传入实参的一个视图
{
    std::cout << str << '\n';
}
由于函数参数 str 是在函数返回前被创建、初始化、使用并销毁的，因此不用担心在 str 使用期间，它所查看的字符串会被修改或销毁。
也就是在返回前，程序不会执行别的，所以如果函数内没有更改，那就是只读函数参数


std::string_view 的错误用法：
代码块就是一对 `{ }`，可以互相嵌套；每一对大括号就是一个独立作用域。
代码块内定义的变量会在该块内销毁：
如果
1.
int main()
{
    std::string_view sv{};

    {                                     // 创建一个嵌套的代码块
        std::string s{ "Hello, world!" }; // 创建一个局部的 std::string
        sv = s; // sv 现在是 s 的视图
    }                                     // s 被销毁, sv 正在查看一个已失效的字符串

    std::cout << sv << '\n';              // 未定义行为，在上个括号时已经销毁
    return 0;
}

2.std::string getName()
{
    std::string s { "Alex" };
    return s;
}

int main()
{
  std::string_view name { getName() }; // 用函数返回值初始化 name，但是函数返回值在该句函数结束时就销毁了
  std::cout << name << '\n';           // 未定义行为

  return 0;
}


3.
int main()
{
    using namespace std::string_literals;
    std::string_view name { "Alex"s }; // "Alex"s 创建了一个临时的 std::string
    std::cout << name << '\n';         // 未定义行为

    return 0;
}
不要使用 std::string 字面值来初始化 std::string_view。

可以使用 C 风格字符串变量或字面值、std::string 变量，或者 std::string_view 变量或字面值来初始化。



如果修改正在被查看的字符串，也会导致未定义行为：
修改一个 std::string 会使指向该 std::string 的所有视图失效。
int main()
{
    std::string s { "Hello, world!" };
    std::string_view sv { s }; // sv 正在查看 s

    s = "Hello, universe!";    // 修改 s, 会使 sv 失效 (s 本身仍然有效)
    std::cout << sv << '\n';   // 未定义行为

    return 0;
}



让失效的 std::string_view 重新生效:

int main()
{
    std::string s { "Hello, world!" };
    std::string_view sv { s }; // sv 现在查看 s

    s = "Hello, universe!";    // 修改 s, 使 sv 失效 (s 本身仍然有效)
    std::cout << sv << '\n';   // 未定义行为

    sv = s;                    // 让 sv 重新生效: sv 再次查看 s
    std::cout << sv << '\n';   // 打印 "Hello, universe!"

    return 0;
}
也就是查看后修改会失效，需要再次查看！！


谨慎返回 std::string_view：
因为不知道什么时候会失效，值的所有者不确定


*/