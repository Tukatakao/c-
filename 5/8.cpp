//Constexpr和consteval函数


/*
constexpr 函数是指其返回值可以在编译时计算的函数
要想有资格进行编译时计算，函数必须具有 constexpr 返回类型，
并且在编译时求值过程中不能调用任何非 constexpr 函数。


此外，对函数的调用必须传入 constexpr 参数。也就是实参必须用constexpr 创建好；
但是一般不直接设置constexpr int add(constexpr x) 这样是不对的
你可以 constexpr int x = 5;
       constexpr int g {constexpr int add (x)};
       这样g就会在编译时被计算好;


Constexpr 函数也可以在运行时求值
具有 constexpr 返回值的函数同样可以在运行时求值，此时它返回的是非 constexpr 的结果


#include <iostream>

constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    int x{ 5 }; // 不是 constexpr
    int y{ 6 }; // 不是 constexpr

    std::cout << greater(x, y) << " is greater!\n"; // 直到运行时才会被计算

    return 0;
}
也就是正常调用 

允许 constexpr 返回类型的函数在编译时或运行时求值，这样同一个函数便可以同时满足两种场景。

否则，你就得写两个独立的函数（一个有 constexpr 返回类型，一个没有）。这不仅会导致代码重复，而且这两个函数还必须使用不同的名字！

这也解释了 C++ 为何不允许 constexpr 的函数参数。因为如果参数是 constexpr，就意味着只能用 constexpr 实参来调用函数。
但事实并非如此——当函数在运行时求值时，可以用非 constexpr 的实参来调用 constexpr 函数。



也就是说constexpr使得函数可以在编译时被运行求值
constexpr 定义的变量 右值必须为编译时常量，也就是表达式必须是常量表达式，嵌套的所有都需要是嵌套表达式
想要使得一个constexpr编译时运行，需要将他放在编译时运行的上下文语境里
constexpr int g { greater(5, 6) };              // case 1: 编译时求值,也就是上下文是constexpr参数调用；

int x{ 5 }; // 不是 constexpr
std::cout << greater(x, 6) << " is greater!\n"; // case 2: 运行时求值,非 constexpr 的参数调用 greater()。因此 greater() 无法在编译时求值，只能在运行时求值。
                  
std::cout << greater(5, 6) << " is greater!\n"; // case 3: 可能在编译时求值，也可能在运行时求值，满足编译时求值的条件 但是没有强制语境


//只有当返回值被用在需要常量表达式的地方时，有资格进行编译时计算的 constexpr 函数才一定会在编译时求值。否则，无法保证一定会在编译时计算。

//因此，把 constexpr 函数理解为“可以在常量表达式中使用”比理解为“会在编译时求值”更合适。
也就是用在编译时常量的右值，也就是上下文是编译时进行语境，constexpr才会进行编译时进行






一个判断该函数是在编译时运行还是运行时运行的函数
std::is_constant_evaluated()（定义在 <type_traits> 头文件中），它会返回一个布尔值，指示当前函数调用是否在常量上下文中执行。
编译时返回true 运行时返回false


constexpr int idd()
{
if (is_constant_evaluated())
  .....                         //你想让其编译时做的事
  else
  .....                         //运行时做的事
}






//Consteval
关键字 consteval，用于指定函数必须在编译时求值，否则会导致编译错误。此类函数被称为即时函数.


#include <iostream>

consteval int greater(int x, int y) // 该函数现在是 consteval
{
    return (x > y ? x : y);
}

int main()
{
    constexpr int g { greater(5, 6) };              // ok: 在编译时求值
    std::cout << g << '\n';

    std::cout << greater(5, 6) << " is greater!\n"; // ok: 在编译时求值

    int x{ 5 }; // 不是 constexpr,不是编译时常量，编译时常量右值必须为常量表达式，右值为常量表达式不一定为编译时常量，只是有成为编译时常量的资格
    std::cout << greater(x, 6) << " is greater!\n"; // error: consteval 函数必须在编译时求值 但是此时传入的函数有一个不是编译时常量

    return 0;
}



利用 consteval 使 constexpr 在编译时执行::
#include <iostream>

// 使用函数模板 (C++20) 和 `auto` 返回类型，使该函数可以作用于任意类型
// 你不需要关心这个函数为什么能正常工作
consteval auto compileTime(auto value)
{
    return value;
}

constexpr int greater(int x, int y) // 该函数是 constexpr
{
    return (x > y ? x : y);
}

int main()
{
    std::cout << greater(5, 6) << '\n';              // 可能在编译时求值
    std::cout << compileTime(greater(5, 6)) << '\n'; // 保证在编译时求值                 
    也就是compileTime是一个conteval函数 所以是一个编译时运行语境   greater是一个编译时函数参数调用，将 constexpr 函数的返回值作为 consteval 函数的参数，所以他也得编译时执行
    

    int x { 5 };
    std::cout << greater(x, 6) << '\n';              // greater 函数仍可在运行时求值

    return 0;
}   




Constexpr/consteval 函数是隐式内联的：：
因为编译时不能跨文件进行编译，
所以文件中调用的编译时函数需要在被引用的头文件中被定义，
所以每个cpp中都会有一份定义，这一份是预处理造成的，
由于编译时函数有inline隐式关键字，所以不同文件中被复制的多份相同的定义被豁免，
然后开始文件内编译，编译时内联展开，被复制到调用点；


但是运行函数不需要再头文件中被定义，因为他只在运行时运行，都已经编译链接完了，如果头文件中有定义
他又没有隐式inline关键字，所以会报错，运行时可以通过声明区别的文件找定义，所以只需要一个定义
内联展开编译器会自己解决。



最佳实践
如果 constexpr/consteval 函数只在单个源文件（.cpp）中使用，则需要在使用之前就在该文件中定义它。
如果 constexpr/consteval 函数会在多个源文件中使用，则应将其定义在头文件中，以便能够被各个源文件包含。



constexpr/consteval 函数的参数不是 constexpr，但可以作为参数传给其他 constexpr 函数：
1.如果写定参数是constexpr int 那只能编译时使用了。所以他的参数一定不是constexpr，可以为const 运行时常量，这样运行时可用，
因为有些函数不是只用一次，可能编译和运行用同一个
但是如果
2.一种特殊情况：就是constexpr函数将自身的参数传递给另一个，形式是这样的：
              constexpr int add(int x)
              {
                   return x+1；
              
              }
              constexpr int bbb(int y)
              {
              
                  return add(y);

              }
             

              constexpr int a=bbb(10);          
        
此时bbb自身参数为10，又传给add，里面可以叠加很多，这样一整串编译时函数的参数就由最外层传入的参数决定，传入编译时常量，一整串在编译时运行，传入运行时常量或者变量就在运行时运行
# 核心好处一句话
**一套函数代码，一条调用链，自动支持两种模式：编译期预计算（省运行时开销） OR 运行时计算（处理动态输入），不用维护两套独立逻辑。**




也许会令人意外的是，consteval 函数的参数同样不被视为 constexpr 变量（尽管 consteval 函数本身只能在编译时求值）。
这一决定是为了保持一致性。



constexpr 函数可以调用非常量表达式函数吗？
可以 












*/