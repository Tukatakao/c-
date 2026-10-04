//全局随机数
/*

如果在多个地方使用随机数生成器：
1.如果在main创建播种prng，并传递，会造成代码混乱；
2.在需要的函数里创建局部static std::mt19937变量
静态变量使得其只播种和初始化一次。
但是每个函数里一个还是很浪费。


真正想要的是一个单一的PRNG对象，它可以跨越所有函数和文件，在任何地方共享和访问。这里的最佳选择是创建全局随机数生成器对象。
namespace Random
{
	// 返回一个播种好的 Mersenne Twister
	inline std::mt19937 generate()
	{
		std::random_device rd{};

		// 返回一个时间戳以及由7个std::random_device产出的随机数组成的种子序列
		std::seed_seq ss{
			static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
				rd(), rd(), rd(), rd(), rd(), rd(), rd() };

		return std::mt19937{ ss };
	}

	// 全局的 std::mt19937 对象.
	// inline 关键字，意味着该对象在整个程序中只有一个
	inline std::mt19937 mt{ generate() }; // 生成一个播种好的std::mt19937对象

	// 产出在 [min, max] 间的一个随机数
	inline int get(int min, int max)
	{
		return std::uniform_int_distribution{min, max}(mt);
	}
}
函数默认外联，但是我们的头文件要被include到不同的文件
所以要加显示内联 inline关键字，防止违反ODR规则



*/