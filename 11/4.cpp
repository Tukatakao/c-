//函数的delete说明符
/*
在某些情况下，我们不希望编写的函数被某些类型的参数调用。



使用=delete说明符删除函数
void printInt(char) = delete; 
匹配到时将会报错


已删除函数
在函数决议时仍然会被视为候选函数。




删除所有不匹配的重载：
希望某个函数只能在精准匹配时调用：
可以使用函数模板来实现；
// 这个函数优先使用int参数来匹配
void printInt(int x)
{
    std::cout << x << '\n';
}

// 这个函数模板将会匹配其他所有类型
// 因为这个函数模板被删除，因此匹配到它将会导致编译失败
template <typename T>
void printInt(T x) = delete;

int main()
{
    printInt(97);   // okay
    printInt('a');  // 编译报错
    printInt(true); // 编译报错
    
    return 0;
}
*/