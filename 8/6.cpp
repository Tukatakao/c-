//switch fallthrough机制与作用域
/*
探究为何要以break结尾；


Fallthrough机制：
当匹配上时：按顺序执行标签后的语句，
直到发生以下终止条件：
1.switch代码块结束
2.另一个控制流语句（通常是break或return）导致退出代码块或函数。
3.其他打断程序正常控制流的事情
如果都没有 会执行匹配的标签后的所有标签
switch (2)
    {
    case 1: // 不匹配
        std::cout << 1 << '\n'; // 跳过
    case 2: // 匹配
        std::cout << 2 << '\n'; // 从这里开始执行
    case 3:
        std::cout << 3 << '\n'; // 这里也会执行
    case 4:
        std::cout << 4 << '\n'; // 这里也会执行
    default:
        std::cout << 5 << '\n'; // 这里也会执行
    }
当执行从某个标签流下到后续标签时，这就称为fallthrough
break和return语句通常用于这种情况



[[fallthrough]]属性
因此我们可以利用这种属性，也就是有意设计fallthrough
但是编译器不知道我们是有意设计的 所以还是会报警
为了帮助解决这个问题，C++17添加了一个名为[[fallthrough]]的新属性。
属性是一种现代C++功能，它允许程序员向编译器提供一些有关代码的附加信息。要指定属性，请将属性名称放在双括号之间。
属性不是语句——相反，它们几乎可以用在任何上下文允许的位置。

 switch (2)
    {
    case 1:
        std::cout << 1 << '\n';
        break;
    case 2:
        std::cout << 2 << '\n'; // 这里开始执行
        [[fallthrough]]; // 有意的进行 fallthrough -- 注意这里的分号代表空语句
    case 3:
        std::cout << 3 << '\n'; // 这里也会执行到
        break;
    }
[[fallthrough]]这里指示泄露是有意的




连续case标签：
多个执行语句相同的case可以合并
switch (c)
    {
        case 'a': // if c is 'a'
        case 'e': // or if c is 'e'
        case 'i': // or if c is 'i'
        case 'o': // or if c is 'o'
        case 'u': // or if c is 'u'
        case 'A': // or if c is 'A'
        case 'E': // or if c is 'E'
        case 'I': // or if c is 'I'
        case 'O': // or if c is 'O'
        case 'U': // or if c is 'U'
            return true;
        default:
            return true；
}
执行会从匹配的case标签之后的第一条语句开始。
case标签不是语句（它们是标签），因此它们不算作语句。
可以“堆叠”case标签，让这些case标签共享后续的同一组语句。
这不被认为是fallthrough行为，
因此这里不需要使用注释或[[fallthrough]]。





switch语句中case的作用域:
if语句条件后只能有一句，也就是一个代码块
然后switch语句，标签后的都在switch块本身，不会隐式创建代码块。
switch (1)
{
    case 1: // 不会创建隐式块
        foo(); // 在switch的作用域内，而不是case 1内
        break; // 在switch的作用域内，而不是case 1内
    default:
        std::cout << "default case\n";
        break;
}
也就是break或者turn会直接结束整个switch函数，而不是单个函数块 因为没有函数快





case语句中的变量声明和初始化：
您可以在switch语句内、case标签之前或之后声明或定义变量(但不能初始化)；
switch (1)
{
    int a; // okay: case标签之前可以声明变量
    int b{ 5 }; // 不合法: case 标签之前，不可以初始化变量

    case 1:
        int y; // okay 但不推荐
        y = 4; // okay: 赋值语句可以
        break;

    case 2:
        int z{ 4 }; // 不合法: 后面还有case标签，不允许初始化变量
        y = 5; // okay: y 在上面声明，所以这里可以赋值
        break;

    case 3:
        break;
}
switch算作是一块作用域，所以前面定义的变量可以在后面使用和赋值；
声明本身不是运行时语句，是编译时语句，所以执行顺序不会影响。
但是初始化时运行时语句，所以有概率因为switch语句的执行顺序而不执行，后续可能显示未定义；
如果真的要在case标签内定义初始化，可以使用显示代码块，然后再在里面定义
  case 1:
    { // 这里有一个显示的代码块
        int x{ 4 }; // okay, 变量在一个新的代码块内初始化
        std::cout << x;
        break;
    }


    
*/

