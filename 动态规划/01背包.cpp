/*
    有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
    第 i 件物品的体积是 vi，价值是 wi。
    求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
    输出最大价值。

    输入格式
    第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
    接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。

    输出格式
    输出一个整数，表示最大价值。

    数据范围
    0<N,V≤1000
    0<vi,wi≤1000
    输入样例
    4 5
    1 2
    2 4
    3 4
    4 5
    输出样例：
    8
*/

/**
 * @file 01背包.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-05 12:05:30
 * @brief 动态规划01背包问题
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++) {
        // 做等价变形，j从m开始从后往前遍历
        for (int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}
/* 
#include <iostream>
using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            // 左边的子集：所有不选第i个物品
            f[i][j] = f[i - 1][j];
            // 右边的情况(不一定存在，要第i件物品体积要不超过j)
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}

 */