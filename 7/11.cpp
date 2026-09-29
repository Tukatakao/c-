//using声明和using指令
/*
1.原来所有的标识符，都在全局命名空间
2.后来把通用功能移动到标准库里了
3.老代码里的函数就用不了了
4.所以一些老代码 前面才会声明 using namespace std；以包含原有的功能




限定与未限定的名称：
放在特定空间叫限定

使用:: 来解析命名空间
std::cout 就是解析std空间 意思是我要用std空间里的cout
::foo 解析的是全局空间 
名称也可以由类名限定，或者使用成员选择操作符（.或->）由类对象限定。
class c;

c::s_member;
c.s_member;
c->s_member;  
都可以



using声明：
每次都用std::太麻烦了
所以
using std::cout;
cout << "xx";  因为有声明了 所以这里cout自动解析cout
使用 using std::cout；告诉编译器我们将使用std命名空间中的对象cout。因此，每当它看到cout时，它都会假设我们是指std::cout。


using指令：
int main()
{
   using namespace std; // 这个using指令告诉编译器，std命名空间内的所有标识符，在using指令的作用域内，都可以无前缀使用
   cout << "Hello world!\n"; // 所以没有 std:: 前缀的版本，在这里可以使用

   return 0;
} //using指令，退出当前作用域，失效










using指令的问题（为什么应避免“using namespace std；”）
声明是声明其中一个
1.
using指令 是导入空间中所有的
那么其中很多你不用的就可能会与你的标识符冲突;
2.
又或者是 俩命名空间中如果有同名的 就会冲突
using namespace a;
using namespace b;
std::cout << x << '\n'; //a和b

此时要使用显示的 a::x 或者 b::x;
或者使用声明；





using声明和using指令的作用范围：
1.块中使用 则仅适用于块
2.全局空间中使用 则全局


取消或替换using语句：
一旦声明了using语句，就无法在声明它的范围内取消它或用其他using语句替换它。
域内无法更改;
只能有意识的限制：
比如每个using都放在一个单独的块中：
int main()
{
    {
        using namespace Foo;
        // 这里调用 Foo:: stuff
    } // using namespace Foo 失效
 
    {
        using namespace Goo;
        // 这里调用 Goo:: stuff
    } // using namespace Goo 失效

    return 0;
}






*/