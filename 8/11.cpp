//break与continue

/*
break语句会结束while循环、do-while循环、for循环或switch语句，
并继续执行循环或switch之后的下一条语句。




switch中的break：
switch中 
通常每个case的语句末尾都有一个break来表示case已完成
（防止fallthrough）

switch (ch)
    {
    case '+':
        std::cout << x << " + " << y << " = " << x + y << '\n';
        break; // 不会 fall-through 到下一个标签
    case '-':
        std::cout << x << " - " << y << " = " << x - y << '\n';
        break; // 不会 fall-through 到下一个标签
    case '*':
        std::cout << x << " * " << y << " = " << x * y << '\n';
        break; // 不会 fall-through 到下一个标签
    case '/':
        std::cout << x << " / " << y << " = " << x / y << '\n';
        break;
    }



break跳出循环：
用来结束循环，并且执行循环后的下一句，但是不会退出函数

 for (int count{ 0 }; count < 10; ++count)
    {
        std::cout << "Enter a number to add, or 0 to exit: ";
        int num{};
        std::cin >> num;

        // 用户输入0，直接跳出循环
        if (num == 0)
            break; // 跳出循环

        // 将用户输入的值累加
        sum += num;
    }
std::cout << "The sum of all the numbers you entered is: " << sum << '\n';  跳出后执行这一句

break也是主动跳出无限循环的常见方法：
    while (true) // 无限循环
    {
        ......
        // 用户输入0，直接跳出循环
        if (num == 0)
            break;
    }








break与return:
break语句只会跳出循环或switch语句，
而return语句会结束整个函数的执行，并返回到调用该函数的地方。





continue:
只是结束当前迭代，不结束循环
for (int count{ 0 }; count < 10; ++count)
    {
        // 如果count被4整除, 结束本轮迭代
        if ((count % 4) == 0)
            continue; // 进入下一次迭代

        // 否则正常执行
        std::cout << count << '\n';

        // 后续的其他可能的语句
    }
也就是不输出4和8，因为直接continue了，跳过了输出

for循环时 continue后 循环递增/递减仍然会执行
但如果是while和do-while循环，
continue后，循环变量的递增/递减不会执行，可能死循环





提前返回：
只要不是最后一句，都叫提前

*/