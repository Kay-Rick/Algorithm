/**
 * @file 多项式乘法.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-14 21:34:54
 * @brief 
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    给定两个多项式 A 和 B，计算 A×B 的结果。

    输入格式
    共两行，每行包含一个多项式的信息，格式如下：

    K N1 aN1 N2 aN2 … NK aNK
    其中，K 表示多项式中非零项的数量，Ni 和 aNi 分别表示其中一个非零项的指数和系数。

    输出格式
    按照与输入相同的格式，输出 A×B 的结果。

    结果中的各项的系数均保留一位小数。

    数据范围
    K 为整数，1≤K≤10。
    Ni 为整数，0≤NK<⋯<N2<N1≤1000。
    aNi 为浮点数，−100≤aNi≤100。

    输入样例：
    2 1 2.4 0 3.2
    2 2 1.5 1 0.5
    输出样例：
    3 3 3.6 2 6.0 1 1.6
*/

#include <iostream>
using namespace std;

const int N = 2010;
double a[N], b[N], c[N];

int main() {
    int k;
    cin >> k;
    // 读入第一个多项式
    while (k--) {
        int u;
        double v;
        cin >> u >> v;
        a[u] = v;
    }
    cin >> k;
    // 读入第二个多项式
    while (k--) {
        int u;
        double v;
        cin >> u >> v;
        b[u] = v;
    }
    k = 0;
    // 多项式乘法
    for (int i = 0; i < N; i++) {
        if (a[i]) {
            for (int j = 0; j < N; j++) {
                if (b[j]) {
                    c[i + j] += a[i] * b[j];
                }
            }
        }
    }
    // 计算有多少项
    for (int i = 0; i < N; i++) {
        if (c[i])
            k++;
    }

    cout << k;
    // 从高位到低位输出结果
    for (int i = N - 1; i >= 0; i--) {
        if (c[i])
            printf(" %d %.1lf", i, c[i]);
    }
    return 0;
}