/**
 * @file 多项式加法A+B.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-14 21:32:10
 * @brief 高精度：一个数组存系数，一个数组存指数，相同指数项的系数相加问题
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    给定两个多项式 A 和 B，计算 A+B 的结果。

    输入格式
    共两行，每行包含一个多项式的信息，格式如下：

    K N1 aN1 N2 aN2 … NK aNK
    其中，K 表示多项式中非零项的数量，Ni 和 aNi 分别表示其中一个非零项的指数和系数。

    输出格式
    按照与输入相同的格式，输出 A+B 的结果。

    结果中的各项的系数均保留一位小数。

    数据范围
    K 为整数，1≤K≤10。
    Ni 为整数，0≤NK<⋯<N2<N1≤1000。
    aNi 为浮点数，−100≤aNi≤100。

    输入样例：
    2 1 2.4 0 3.2
    2 2 1.5 1 0.5
    输出样例：
    3 2 1.5 1 2.9 0 3.2
*/

#include <iostream>
using namespace std;

const int N = 1010;
// c[i]表示指数为i的数据的系数
double c[N];

int main() {
    int k;
    cin >> k;
    while (k--) {
        int u;
        double v;
        // 读入指数和系数
        cin >> u >> v;
        c[u] = v;
    }
    cin >> k;
    while (k--) {
        int u;
        double v;
        cin >> u >> v;
        c[u] += v;
    }
    k = 0;
    for (int i = 0; i < N; i++) {
        if (c[i])
            k++;
    }
    cout << k;
    for (int i = N - 1; i >= 0; i--) {
        if (c[i])
            printf(" %d %.1lf", i, c[i]);
    }
}