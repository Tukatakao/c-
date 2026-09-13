//发起调用的函数是调用者，被调用的是被调用者
//定义函数只能在外边定义，不能嵌套
//模块化！！！
#include <iostream>
void hanshu1()                                 //不用写return 0,void表示啥也不会返回
{
    std::cout << "我帧率" << '\n';
    
}
int main()
{
    std::cout << "我要说真心话："; 
    hanshu1();                                  //调用hanshu1,main是调用者，当进行函数调用时，不要忘记在函数名后包含括号()。
    hanshu1();                                  //多次调用
    hanshu2();                                  //虽然调用但是hanshu2本身没有打印功能
    std::cout << "继续真心话";
    int a{hanshu3()};
    return 0;
}




//定义带返回值的新函数
int hanshu2()
{
    return 5;  
}



int hanshu3()
{
    int shuzi{};
    std::cout << "请输入数字：";
    std::cin >> shuzi;
    return shuzi;
}