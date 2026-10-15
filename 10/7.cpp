//typedef和类型别名
/*


类型别名：
可以使用using关键字为现有的数据类型创建别名：
using Distance = double;
将Distance数据类型定义为double的别名；
一旦定义，别名就可以在任何地方使用类型名；
Distance shuju{};
等效于
double shuju{};







命名类型别名规则:
其实起名并没有硬性规定：但是有约定俗成,
历史上
1.使用以“_t”后缀结尾的别名（“_t”是“Type”的缩写）。
2.使用以“_type”后缀结尾的别名。某些标准库类型（如std::string）使用此约定来命名嵌套类型别名（例如，std::string::size_type）。
3.使用不带后缀的别名。

现代C++的预定俗称：
命名自己定义的类型别名（或任何其他类型）时，以大写字母开头，不使用后缀。




类型别名不是不同的类型：
并不是一个新类型，而是只是给这个类型引入了一个新的标识符；
假如我们给同一个类型起了AB两个别名；
那么本质上AB还是同一类型；
可以相互运算，赋值；








类型别名的作用域：
类型名的作用域：
1.块中定义的仅在该块中可以使用；
2.全局命名空间中定义的是具有全局作用域；

如果需要在多个文件中使用同一个：
可以在头文件中定义，然后include到需要的代码文件中去；





类型定义：
typedef是为类型创建别名的较旧方法。要创建typedef别名，使用typedef关键字:
typedef long Miles;
using Miles = long;
这俩一样；










何时应使用类型别名？
使用类型别名进行与平台无关的编码
跨平台时，
有些类型的大小不同，直接移植时，可以使用别名
因为原来的类型名称看不出来大小
#ifdef INT_2_BYTES
using int8_t = char;
using int16_t = int;
using int32_t = long;
#else
using int8_t = char;
using int16_t = short;
using int32_t = int;
#endif
用宏来调整不同平台上相同类型名对应大小，即自动使用适合当前平台宽度的数据类型；


固定宽度整数类型（如std::int16_t和std::uint32_t）和size_t类型实际上只是各种基本类型的类型别名。
因此：
std::int8_t x{ 97 }; 
std::cout << x << '\n';
int8_t是char的别名，所以本质上是定义了个char
输出也将是a







使用类型别名使复杂类型更易于阅读：
有些类型很复杂，可以使用别名图个方便：
using VectPairSI = std::vector<std::pair<std::string, int>>;





使用类型别名来记录值的含义：
int gradeTest();
只知道返回整数值：
现在，让我们使用类型别名执行等效版本:
using TestScore = int;
TestScore gradeTest();
TestScore作为返回类型，使函数返回测试分数这一意图变得更加明显。

如果只是一个函数 为他创建一个别名不值得，但是如果多个函数传递或者返回这样的类型。
则是值得的；





使用类型别名以简化代码维护：
可以使用类型别名来更改对象的类型；
比如 一开始使用short来保存id
后来决定使用long
如果要更改，要更改大量代码；
如果一开始使用的是
using a = short；
我们可以改成using a = long；
这样所有被a类型值，本质数据类型会被从short改成long；

但是这样有时候程序行为也会被更改。需要留意，比如计算



缺点和结论：
如果引入一个别名
给程序可读性和可理解性带来提升
不能抵消
它带来的额外成本，则称弊大于利；




*/