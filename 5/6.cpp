//条件运算符


/*


1.符号    ？：

形式     a?b:c
         a为true 运算b 否则运算c


         x>0?x-1:x+1

         判断x是否大于0
         true x-1
         false x+1
    三元运算符：相当于if-else
    IF(a)
       ...b
    else
       ...c

if-else else及其语句可以不存在
但是三元运算符不可


2.条件运算符是一个表达式而不是语句，最终运算玩是一个量/值
所以要当操作数
      x=x>0?x+1:x-1;
      如果没有x=
      就是一个值，没有任何操作


列如初始化变量时，条件判断初始化不同的值
constexpr bool inBigClassroom { false };                  //给予inbigclassroom false
constexpr int classSize { inBigClassroom ? 30 : 20 };     //因为inbigclassroom 是false 所以值为20


3.用圆括号包裹条件运算符
int z { 10 - x > y ? x : y };
要改成int z{ 10 - (x > y ? x : y)}；
规则：
1.如果条件运算符作为子表达式使用，应用圆括号将整个条件运算符括起来。
2.为了提高可读性，若条件表达式中含有任何运算符（函数调用运算符除外），也应用圆括号将其括起来。

1.当别的操作符的右操作数时就要整体加括号
比如
int x=（三元）   std::cout << (三元)  
2.条件表达式中还有子表达式 
子表达式要加括号，函数引用除外


4.表达式的类型必须匹配，或可以相互转换
为了符合 C++ 的类型检查规则，必须满足以下条件之一：

第二个和第三个操作数的类型相同。
编译器能找到一种方式，将第二个和第三个操作数中的一个或两个转换为一致的类型。
std::cout << (true ? 1 : 2) << '\n';    // okay: 两个操作数的类型都是 int

std::cout << (false ? 1 : 2.2) << '\n'; // okay: int 1 被转换为 double

std::cout << (true ? -1 : 2u) << '\n';  // 令人意外: -1 被转换为 unsigned int, 发生溢出

std::cout << (x != 5 ? std::to_string(x) : std::string{"x is 5"}) << '\n';
字符串类型 std::to_string(x) 将括号里的值转为字符串 也就是输出x的值
std::string{“x is 5”}也就是创建字符串并且输出





*/
