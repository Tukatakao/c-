//Constexpr if语句
/*
也就是编译时运行if函数


通常，if语句的条件在运行时求值。
但是如果条件是常量 也就是编译器就知道值
constexpr double gravity{ 9.8 };             //定义常量
if (gravity == 9.8) // 常量表达式，结果永远为true
	std::cout << "Gravity is normal.\n";   // 永远会执行
else
	std::cout << "We are not on Earth.\n"; // 不会执行到
这是非常浪费的



Constexpr if语句
该语句要求条件必须是常量表达式。
constexpr if语句的条件表达式会在编译时求值。
该语句在编译期求出来值之后 只会留下跑通的语句 不符的会删掉
最佳实践
当条件表达式是常量表达式时，优先使用constexpr if语句。




现代编译器，与语句常量条件表达式的if语句：
出于优化目的，现代编译器可能会把非constexpr if 语句当作constepxr if 处理，在编译期就处理好，但是不一定会这么做


*/