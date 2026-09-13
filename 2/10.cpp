//头文件保护
/*
square.h：
int getSquareSides()
{

    return 4;
}

wave.h：
#include "square.h"

main.cpp：
#include "square.h"          //此时square中包含了函数定义       函数定义第一次被引用
#include "wave.h"            //而wave.h包含额square.h,         函数定义第二次被引用


int main()
{
    return 0;
}
    */


//通过头文件保护来避免
//如下：

/*
#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE

// 这里放置你的声明

#endif

*/
//所有头文件都应有头文件保护。SOME_UNIQUE_NAME_HERE可以取任何名称


//头文件保护不会阻止头文件被不同文件各包含一次！！
//将函数定义放在.cpp文件中，头文件只包含前向声明；
//声明可以重复！！，所以头文件只放声明，就不担心违反ord了，
#pragma once
//现代编译器使用#pragma预处理器指令支持更简单的替代形式的头文件保护