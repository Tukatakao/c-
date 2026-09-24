//关系运算符和浮点比较

/*
< > <=  >= == != 
真则返回true 假则返回false


布尔条件值：
默认情况下，if语句或条件运算符（以及其他一些位置）中的条件会被求值为布尔值。


比较浮点值可能会有问题:
浮点值实际上会有误差，所以比较会有误差；

浮点小于和大于:
a < b
如果ab不相似 那就是可信的
如果相似 就可能会有错误，但是有些时候这些错误如果不耽误事 其实可以忽略


浮点等式和不等式：
只有两边完全相等时才返回true
所以这俩运算符放在浮点数里风险很高，不应该用
可以将低精度（只有几个有效数字）浮点数字面值与相同类型的相同字面值进行比较。
比如判断一个浮点值 a == 1.0；


比较浮点数:
是使用一个函数来查看两个数字是否几乎相同。
如果它们“足够接近”，那么称它们相等。用于表示“足够接近”的值传统上称为epsilon。Epsilon通常被定义为一个小正数（例如0.00000001，有时写为1e-8）。

bool approximatelyEqualAbs(double a, double b, double absEpsilon)
{
    // 如果a与b的差值的绝对值，小于一个范围，则认为是足够接近
    return std::abs(a - b) <= absEpsilon;
}
bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
	return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}
将这个标准与两个值挂钩，便可以自动缩放这个标准


*/