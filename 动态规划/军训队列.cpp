/*
    有 n 名学生参加军训，军训的一大重要内容就是走队列，而一个队列的不整齐程度是该队中最高的学生的身高与最矮的学生的身高差值的平方。

    现在要将 n 名参加军训的学生分成 k 个队列，每个队列的人数可以是任意非负整数。

    在安排队列时希望所有队列的不整齐度之和尽量小，请问不整齐度之和最小可以是多少？

    输入格式
    第一行两个整数 n,k，表示学生人数和队列数。

    第二行 n 个整数，依次表示每名学生的身高。

    输出格式
    一个整数表示答案。

    数据范围
    对于10%的数据，k=1；
    对于另外10%的数据，k=2；
    对于另外10%的数据，k=3；
    对于另外10%的数据，k=4；
    对于另外10%的数据，1≤n,k≤5；
    对于另外10%的数据，1≤n,k≤10；
    对于另外20%的数据，1≤n,k≤100；
    对于另外5%的数据，n=k=500
    对于所有的数据，1≤n,k≤500，0≤ 学生身高 ≤200
    输入样例：
    3 2
    170 180 168
    输出样例：
    4
*/

/**
 * @file 军训队列.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-05 12:58:02
 * @brief f[i][j]表示所有只考虑前i个数且分成j组(每组至少一个人)的所有方案的集合
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510;

int n, m;
int h[N];
int f[N][N];

int main() {
    cin >> n >> m;
    if (m >= n)
        cout << 0 << endl;
    else {
        for (int i = 1; i <= n; i++)
            cin >> h[i];
        // 对数组要排个序
        sort(h + 1, h + n + 1);
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i && j <= m; j++) {
                for (int k = i; k >= j; k--)
                    f[i][j] = min(f[i][j], f[k - 1][j - 1] + (h[i] - h[k]) * (h[i] - h[k]));
            }
        }
        cout << f[n][m] << endl;
    }
    return 0;
}