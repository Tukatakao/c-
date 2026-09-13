//n 字节 表示有符号数据范围 -2的n次方到2的n次方-1
/*整形有 short   2
         int     2/4
         long    4
         long long   8
         */ 
//溢出：超出范围就会溢出，会导致未定义


#include <iostream>

int main()                 
{
    std::cout << 8 / 5 << '\n';
    /*
         结果为1 因为8和5都是定义的整形，结果也为整形
         
    */
    return 0;
}