//被重载函数之间互相区分

/*

函数重载允许我们创建同名：
只要参数类型不同，
或者其他区分



如何区分重载函数：
参数个数
参数类型
返回类型  不可以！！！！






基于参数个数的重载：
就是参数个数不同：

int add(int x, int y)
{
    return x + y;
}

int add(int x, int y, int z)
{
    return x + y + z;
}



基于参数类型的重载：
int add(int x, int y); // 整数版本
double add(double x, double y); // 浮点数版本
double add(int x, double y); // 整数与浮点数混合版本
double add(double x, int y); // 整数与浮点数混合版本






函数的返回类型不用于区分；
int getRandomValue();
double getRandomValue();
编译器会报错,因为返回类型不用于被区分；






类型签名：
函数的类型签名（type signature）被定义为
头文件中用于区分函数的部分；

*/