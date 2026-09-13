#include <iostream>
// void 无类型，纯执行,无法实例化
//常用于不返回值的函数
void print()
{
    std::cout << "wozuishuai" << std::endl;
    //return 0; 这样会导致错误
}

//使用空参数列表而不是void来指示函数没有参数。
int a()                              //而不是int a(void)   这样也表示不用外部传递参数，但是不好
{
    std::cout << "这个函数不用参数！"; //起码不需要外部传递参数
    int x{};
    return x;

}
