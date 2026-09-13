#include<iostream>
int main()
{
    std::cout << "请输入一个数字：";
    int shuzi{};
    std::cin >> shuzi; 
    std::cout << "数字的双倍为" << shuzi*2 << '\n';           //输入箭头向右
    return 0;
}
