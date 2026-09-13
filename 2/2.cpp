#include <iostream>
int dezhihanshu()
{
    std::cout << "请输入";
    int shuru;
    std::cin >> shuru;
    return shuru;
}

void dayinhanshu()
{
    std::cout << "输入的数字为：" << dezhihanshu() << '\n';

}


void hancanhanshu(int x)
{
    std::cout << "给我一个数字";
    std::cout << "原来你给了一个：" << x;
    
}


int main()
{   
    hancanhanshu(dezhihanshu());                       //调用参数函数时不需要再写创建
}


//参数函数的参数也是本函数的先计算参数！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！