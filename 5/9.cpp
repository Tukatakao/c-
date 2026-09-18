//std::string

/*

1.
std::string 位于<string>头文件中
std::string name {}; //创建空字符串
std::string name {"fly"}; //初始化
name = “wgz”   //拷贝赋值



2.std::cout 输出字符串：
std::string name {"fly"};
std::cout << "My name is"<< name << '\n';
空字符串则不会输出任何内容


3.std::string 可以处理不同长度的字符串
他没有长度限制
比如:
你想保存一个5bit整形，但是int只有4 bit ，你就可以使用字符串来保存


4.使用 std::cin 读取字符串输入
std::string name{};
std::cin >> name;          //不会按预期工作 std::cin 遇到空白字符停止读取；只能输入不带空格的字符串
不然会把空格之后的部分直接读取给下次std::cin 比如你输入john doe 只会把john赋值给name doe留在缓冲区直接给你下个要std::cin的值赋值


不好使！！！


5.使用 std::getline() 读取整行文本，以换行'\n'作为终止，而不是空格避免了以上
std::string name{};
std::getline(std::cin >> std::ws, name);


6.关于std::ws
类似于输出操纵器：std::setprecision() 来改变 std::cout 显示的精度位数。
std::ws是输入操纵器：std::ws 输入操纵器告诉 std::cin 在提取之前忽略所有前导空白字符。
前导空白是指出现在字符串开头的任何空白字符（空格、制表符、换行符）。
可以避免上次输入留下的‘\n'导致的无法输入。


std::getline(std::cin >>name);
std::getline(std::cin >>color);
假如我们第一次输入w gz 并且回车 实际上写入的是 w gz\n,std::getline 以换行终止，所以提取了w gz留下了\n
那第二次std::getline 直接读取到了上次留下的\n 直接提取了
std::ws作用就在于忽略字符串之前的空白 只看字符串之后的空白




如果使用 std::getline() 读取字符串，
请使用 std::cin » std::ws 输入操纵器来忽略前导空白。每次调用 std::getline() 都需要重新添加，
因为 std::ws 的设置不会在新的调用中保留。
不会存档，每次都要操纵



7.std::string 的长度
std::string name {"wgz"};
std::cout << name << "has" << name.length() << "chararcters'\n'";
调用方式并不是 length(name)，而是 name.length()。


length是std::string的一个成员函数，也就是定义std::string这个类时里面的函数
且它的返回值时无符号整数值,如果要把这个值赋值给int变量 使用static_cast类型转换函数进行转换
int length {static_cast<int>(name.length)}


我的理解：定义一个类型/类 就像int啥的一样叫std::string 
想int x;一样std::string name;
int 和std::string 就是变量x和name 的类型；
std::length.length() 应用到name上就是 name.length() 前面的对象名要改为具体名


对于普通函数，我们的调用方式是 function(object)。而对于成员函数，我们的调用方式是 object.function()。




8.初始化 std::string 的开销很大:
每次初始化 std::string 时，都会复制一份用于初始化它的字符串。复制字符串的代价是很大的，因此我们应当尽量减少复制的次数。


9.不要按值传递 std::string
按值传递就是复制传递，普通的传递方法
int change（int x）
{

。。。。

}


int a = 10；
change（a）；
std::cout << a;
将a的值10复制一份传给change 的形参x，change函数操作的是传递的形参x
又因为复制字符串开销大，所以不要按值传递，就是把值复制一份给下一个参数
可以用地址啥的，数据就一份，新参数拿着地址去找


最佳实践

不要按值传递 std::string，因为这样会生成昂贵的副本。在大多数情况下，请改用 std::string_view 参数（在——std::string_view 简介——中介绍）。





10.返回 std::string
当 return 语句的表达式结果属于下列情况之一时，按值返回 std::string 是可以的：

1.类型为 std::string 的  局部变量,就是函数运行完内存就被释放的那种变量，生命周期比较短。（也就是函数内定义的字符串）

2.由函数调用或运算符按值返回的 std::string。 
                                  
3.作为 return 语句的一部分所创建的 std::string。 return std::string{"wgz"};   //return 复制完毕，到函数结束的花括号就会释放内存，也可以

除此之外的大多数场景下，不要按值返回 std::string，因为这样会产生昂贵的副本。




11.std::string 的字面值
我们可以在双引号字符串后面加上 s 后缀，来创建类型为 std::string 的字符串字面值。



12.constexpr 字符串 ，   编译时常量字符串
constexpr std::string name{ "Alex"s }; //编译失败
 C++17 及更早的版本根本不支持 constexpr std::string，而在 C++20/23 中也仅在非常有限的场景下才支持。
 如果需要 constexpr 字符串，请改用 std::string_view。
 constexpr std::string_view {"wgz"s};
 

*/