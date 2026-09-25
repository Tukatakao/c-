//自定义命名空间和作用域解析操作符
/*
int doSomething(int x, int y)
{
    return x + y;
}
int doSomething(int x, int y)
{
    return x - y;
}
这俩都叫doSomething,放在同一个项目中会冲突
解决此问题的一种方法是重命名其中一个函数，以便名称不再冲突。但这也需要更改所有调用该函数的地方，很麻烦，并且容易出错。避免冲突的更好方法是将函数放入自己的命名空间中。
基于这个原因，标准库被移动到std命名空间中。
也就是std::...  也就是用标准库里iostream里函数

定义自己的命名空间：
C++允许我们通过namespace关键字定义自己的命名空间。在程序中创建的命名空间称为用户定义命名空间。
命名空间的语法如下：
namespace 命名空间标识符
{
    // 命名空间中的内容
    int doSomething()
    {
    ....
    }
}
这样 引用函数时 命名::doSomething

使用域解析操作符（ :: ）访问命名空间：

在函数名左侧   namespace::hanshu 便可指定任一空间的任一函数
namespace Foo // 定义了命名空间 Foo
{
    // doSomething() 在命名空间 Foo 中
    int doSomething(int x, int y)
    {
        return x + y;
    }
}

namespace Goo // 定义了命名空间 Goo
{
    // doSomething() 在命名空间 Goo 中
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

int main()
{
    std::cout << Foo::doSomething(4, 3) << '\n'; // 使用的是命名空间 Foo 中的 doSomething
    std::cout << Goo::doSomething(4, 3) << '\n'; // 使用的是命名空间 Goo 中的 doSomething
    return 0;
}





使用无名称前缀的域解析操作符：
在main中
如果::前面啥也没写 
::doSomething 就是用全局命名空间里的
和doSomething 不加::的是一个意思


命名空间内的标识符解析：
如果在一个空间内
::doSomething 表示全局
doSomething表示该空间  没提供去哪找，便优先在该空间找

如果使用命名空间内的标识符，并且没有提供域解析限定，编译器将首先尝试在同一命名空间中查找匹配的声明。
namespace Foo
{
	void print() // 这个 print() 在 Foo 命名空间
	{
		std::cout << "Hello";
	}

	void printHelloThere()
	{
		print();   // 调用 Foo 命名空间中的 print()  这就叫没提供域解析限定
		::print(); // 调用 全局命名空间中的 print()
	}
}



命名空间中内容的前向声明：
命名空间也要有头文件
对于命名空间内的标识符，前向声明也需要在同一命名空间内：
原来声明：
int add(int x,int y);
现在声明
namespace my_space
{
int add(int x,int y);
}

函数体：
namespace my_space
{
int add(int x,int y)
    {
 
    }
}




单个命名空间可以存在多个文件中:
在多个位置（跨多个文件或同一文件中的多个位置）声明命名空间块是合法的。命名空间中的所有声明都被视为命名空间的一部分。
所有相同空间的是一个空间



嵌套命名空间：
namespace Foo
{
    namespace Goo // Goo 命名空间 在 Foo 命名空间 中
    {
        int add(int x, int y)
        {
            return x + y;
        }
    }
}

Foo::Goo::add(1,2);//这样解析




命名空间别名：
namespace Foo::Goo 等价于嵌套

namespace Active = Foo::Goo; // active 现在指代 Foo::Goo

Active::add(1,2);


何时应使用命名空间:
在应用程序中，命名空间可以用于将特定于应用程序的代码与可以重用的代码（例如，数学函数）分离开来。
当编写要分发给其他人的库或代码时，请始终将代码放在命名空间中。如果不遵守这个规则，则发生命名冲突的可能性很高。





*/