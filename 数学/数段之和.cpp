/**
 * @file 数段之和.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-13 22:40:08
 * @brief 
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    给定一个正数序列，每个非空连续子序列都可被称作一个数段。

    例如，给定序列 { 0.1, 0.2, 0.3, 0.4 }，该序列共包含 10 个不同数段，(0.1)(0.1,0.2)(0.1,0.2,0.3)(0.1,0.2,0.3,0.4)(0.2)(0.2,0.3)(0.2,0.3,0.4)(0.3)(0.3,0.4)(0.4)。

    现在给定一个序列，请你求出该序列的所有数段中所有数字的总和。

    对于前面的示例，10 个数段的总和为 0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0。

    输入格式
    第一行包含正数 N，表示序列中元素的个数。

    第二行包含 N 个正数，均不超过 1.0，数字之间用空格隔开。

    输出格式
    输出所有数段中所有数字的总和。

    结果保留两位小数。

    数据范围
    1≤N≤105,

    输入样例：
    4
    0.1 0.2 0.3 0.4
    输出样例：
    5.00
*/