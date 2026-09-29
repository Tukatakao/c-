//未命名与内联的命名空间

/*
未命名（匿名）命名空间：
是定义时没有名称的命名空间
namespace // 未命名的命名空间
{
    void doSomething() // 只能在本文件中访问
    {
        std::cout << "v1\n";
    }
}

int main()
{
    doSomething(); // 使用doSomething()，可以不用带命名空间限定符

    return 0;
}


这里会输出v1
1.这里dosomething放在了一个未命名的空间
2.本身函数也可以在父空间中被访问
3.这里dosomething的空间未命名
4.所以他的父空间是全局
5.所以main函数能识别


这并非没用，放在空间中的函数具有内部链接
约等于加了个static 




内联命名空间：
void doSomething()
{
    std::cout << "v1\n";
}

int main()
{
    doSomething();

    return 0;
}



假如对doSomething()不满意 ，那么贸然修改会对程序造成伤害，因为会对其他引用该函数的位置造成破坏
1.第一种方法 复制一份函数的新副本 只改新副本
2.另一种方法是使用内联命名空间。内联命名空间是通常用于版本内容的命名空间。与未命名命名空间很相似，在内联命名空间内声明的任何内容都被视为父命名空间的一部分。然而，与未命名命名空间不同，内联命名空间不影响链接。

也就是说一般命名空间里的函数要加空间域
内联的可以不加 相当于定义在父空间
而普通定义的 必须加空间域才能用
举例

namespace Foo
{
  inline namespace Goo
  {
  dosomething();
  }
  namespace Hoo
  {
  dosomething();
  }
 }

调用内连的
可以 Foo::dosomething();此函数链接在父空间下   内联不改变链接属性
调用普通的
必须 Foo::Goo::dosomething();普通空间又给函数加了一层限制


只要在未命名空间 就有内部链接
内联未命名是一样的
*/