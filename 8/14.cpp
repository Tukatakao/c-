//使用Mersenne Twister生成随机数
/*
如何使用随机数：
为了使用C++中的随机化功能，需要引入标准库的头文件。


使用Mersenne Twister在C++中生成随机数：
mt随机数超级流行：c++自带的随机库
#include <random>
包含两个随机：
1.mt19937      生成32位无符号整数
2.mt19937_64   生成64位无符号整数
使用
std::mt19937 mt{};  //初始化一个mt引擎
std::cout << mt();  //产出一个随机数




使用Mersenne Twister掷骰子：
32位数字很大，如果我们想限制结果的范围：
PRNG本身无法做到，我们要其他方法，但是这并不简单
但是！！！
random库支持指定随机数分布：
有一个随机数分布器很有用：均匀分布
以相等的概率在两个数字之间产生输出，
就是把prng的产出值作为输入按照概率分布转换到范围里
使用随机数分布器：
std::mt19937 mt{};   //创建引擎
std::uniform_int_distribution die6{ 1, 6 }; //归一化到1-6
std::cout << die6(mt)；  将引擎套入壳中



上面的程序并不像看上去那样随机：
由于起始种子一致，所以每次序列都是完全相同的
所以我们需要种子也不是固定的，当然不可以种子也用随机数生成器，这样不也一样吗
只不过是多套了一层罢了
有两种：
1.使用系统时钟
2.使用系统的随机设备




使用系统时钟播种：
使用时间作为种子，通常序列是不同的
C和C++长期以来都有使用当前时间播种PRNG的做法（使用std::time()函数）

如果程序快速连续运行，时间精度太小 
那相邻的也会相同，所以时间精度应比较高
std::mt19937 mt{ static_cast<std::mt19937::result_type>(
		std::chrono::steady_clock::now().time_since_epoch().count()
		) };
时间播种mt随机数生成;
std::uniform_int_distribution die6{ 1, 6 }; 
分布器；
std::cout << die6(mt) << '\t';
生成限定范围内的随机数；

列表初始化详解：
static_cast<目标类型>（值）；    //c++类型安全转换
<std::mt19937::result_type>     //要转换成与状态值相同类型的量
(std::chrono::steady_clock::now().time_since_epoch().count())
//要转换的值 










使用随机设备播种：
随机库包含一个名为std::random_device的类型，
std::mt19937 mt{ std::random_device{}() };
std::random_device{}() 先创建对象然后调用重载的运算符（）；




仅为PRNG播种一次：
许多prng可以第二次播种，本质上就是重新初始化其状态。
通常不能这么做，除非有明确理由；
int getCard()
{
    std::mt19937 mt{ std::random_device{}() }; // 每次函数调用，都生成一个PRNG，并重新播种
    std::uniform_int_distribution card{ 1, 52 };
    return card(mt);
}

int main()
{
    std::cout << getCard() << '\n';

    return 0;
}
该程序将随机数初始化和调用封装在一起，
每次调用都会初始化，这是低效的




Mersenne Twister与播种不足的问题：
mt内部状态位624字节，但是我们用时钟或设备（32位整数初始化）时候，
会种子不足。
随机库会尽可能用随机的数据填补剩下的，但这不能十全十美。
如何解决呢？
1.先讨论一下“种子序列”  ，这个序列需要我们先传入种子不足的种子，
然后他会尽可能生成  无偏 种子 ，以来初始化prng状态；
2.我们传入的不足的种子 越长越好。
std::random_device rd{};
std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
比std::seed_seq ss{ rd() }要好 这个只有1位 






预热PRNG：
当种子不足时，丢弃前N个结果可能会更好。
这样有助于混合内部状态，以提高结果质量;
使用种子序列初始化的prng会自动执行预热，因此不需要显示预热;




*/