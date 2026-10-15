//使用auto关键字的对象类型自动推导
/*

double d{ 5.0 };
我们常常这样显示定义类型
但是字面值5.0里已经隐式具有了类型；
所以实际上是提供了两次类型信息；


初始化变量的类型推导:
允许编译器从对象的初始值所隐含的数据类型推导类型；
我们可以使用
auto  d{5.0};   //double
auto i{ 1 + 2 }; //int
auto x { i };   //int



并且函数调用
也就是 hanshu()；
所返回的的值也可以用auto
auto sum { add(5, 6) }; // add() 返回 int, 所以 sum 是 int 类型

由于auto是根据初始值的隐式数据类型推导的
所以不适用没有初始值或者空初始值，同时初始值是void时 也不起作用；

有些数据类型很长，可以用auto来节省输入；








类型推导会删除const/constexpr限定符：
在大多数情况下，类型推导将从推导的类型中删除const或constexpr限定符。
const int x { 5 }; // x 的类型是 const int
auto y { x };      // y 的类型是 int (const 限定符被丢掉)

原本如果不用auto y是不可能改的，因为x不可更改；
后面如果对y进行拷贝赋值，或者啥的都不起作用
但是如果用auto就可以更改,并且改的只是y，x不变；


这种情况可以
const auto y{x};









字符串字面值的类型推导：
由于历史原因，C++中的字符串字面值具有奇怪的类型。
auto s { "Hello, world" }; // s 的类型是 const char*, 而不是 std::string
如果希望推导出来的是std::string或std::string_view
使用s或sv后缀




类型推导的优点和缺点：
1.提高可读性
// 不容易阅读
int a { 5 };
double b { 6.7 };
// 对齐，容易阅读
auto c { 5 };
auto d { 6.7 };
2.可以避免无意的未初始化:
int x; // oops, 忘记了初始化 x, 但编译器不会警告
auto y; // 编译器会报错，因为无法推导出变量y的类型
3.可以保证不出现意外的转换以影响性能


缺点：
1.掩盖了对象的类型；




*/