//条件编译指令：
//允许指定在某些条件下编译或不编译某些代码

//目前最常用的三个：#ifdef、#ifndef和#endif。


//#ifdef预处理器指令允许预处理器检查某个标识符是否已被#define定义过。如果是，则编译#ifdef和匹配的#endif之间的代码。如果不是，则忽略这些代码。




/* 
#include <iostream>

#define PRINT_JOE

int main()
{
#ifdef PRINT_JOE
    std::cout << "Joe\n";       // PRINT_JOE被定义，这一行会被编译
#endif

#ifdef PRINT_BOB
    std::cout << "Bob\n";        // PRINT_BOB未被定义，这一行不会被编译
#endif

    return 0;
}



#ifndef与#ifdef相反，未定义才进行中间的指令
#ifndef #endif

#if 0 //从这里开始不需要编译

  。。。。。。。


#endif //到这里结束
要临时重新启用被#if 0包裹的代码，可以将#if 0改成#if 1
也可以用这个预处理指令来注释掉包括多行注释的代码   因为多行注释不可嵌套

`#ifdef` 只查第一件事：这个名字有没有 `#define`，**完全不管替换文本是什么，也不会做替换**。

预处理指令也可以放在函数内部，但是房外边不更好吗。

并且  一个文件中的定义指令，不会对其他文件产生作用：
比如 我在add 文件中设定 
#ifdef abc
   std::cout << yes;
#endif
#ifndef abc 
   std::cout << no;
#endif

在main函数中
#define abc    //此时abc 在main函数被宏
int main（）
{
   add();
   return 0;
}
程序进入add函数 发现add每define abc所以 add函数打印no
即使在main函数是define过的 但是他们各管各的


*/