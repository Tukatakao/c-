#include <iostream>
#include <iomanip>
//对象大小和sizeof
//bit 就是一个0/1
//字节 就是8个bit 00000000-11111111
//内存是字节可寻址的，因此最小的对象是1个字节。



//std::stew(a) 
//std::setw(n) :来自 **`<iomanip>`**，作用是设置**下一个**输出项占多少字符宽度，
//不够就用填充字符补齐。做日志对齐、打印表格非常常用。




int main()
{
    sizeof(0);        //括号里填数据类型或者变量名,计算数据的长度。
    return 0;
}
