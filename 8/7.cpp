//goto语句
/*

无条件跳转：
无条件跳转是通过goto语句实现的，跳转到的位置是通过使用语句标签来标识的。

int main()
{
    double x{};
tryAgain: // 这是标签语句
    std::cout << "Enter a non-negative number: "; 
    std::cin >> x;

    if (x < 0.0)
        goto tryAgain; // 这是goto语句

    std::cout << "The square root of " << x << " is " << std::sqrt(x) << '\n';
    return 0;
}



标签语句具有函数作用域：
标签语句使用函数作用域：这意味着标签在整个函数中都是可见的，甚至在其声明点之前也是可见的。
也就是goto和标签必须在一个函数里，并且前后可以颠倒；
所以可以向前跳转 也可以向回跳转




标签可以自己定义；并且标签必须关联语句(可以是空语句)；//下面的标签就叫skip
标签有两个限制
1.只能在单个函数内跳转
2.像前跳转的时候，中间不能跳过变量的显式初始化；
int main()
{
    goto skip;   // error: 这个跳转是非法的...
    int x { 5 }; // 因为这里的显式初始化会被跳过
skip:            
    x += 3;      // 这里的x的初始值设置的是多少?
    return 0;
}


避免使用goto：因为这样会使代码像意大利面条一样扭曲，用其他控制流
但是当你想退出嵌套时，可以用goto




*/