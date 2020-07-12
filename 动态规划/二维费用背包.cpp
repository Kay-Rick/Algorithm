/**
 * @file 二维费用背包.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-12 19:15:32
 * @brief 二维费用的背包问题
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    有 N 件物品和一个容量是 V 的背包，背包能承受的最大重量是 M。

    每件物品只能用一次。体积是 vi，重量是 mi，价值是 wi。

    求解将哪些物品装入背包，可使物品总体积不超过背包容量，总重量不超过背包可承受的最大重量，且价值总和最大。
    输出最大价值。

    输入格式
    第一行两个整数，N，V,M，用空格隔开，分别表示物品件数、背包容积和背包可承受的最大重量。

    接下来有 N 行，每行三个整数 vi,mi,wi，用空格隔开，分别表示第 i 件物品的体积、重量和价值。

    输出格式
    输出一个整数，表示最大价值。

    数据范围
    0<N≤1000
    0<V,M≤100
    0<vi,mi≤100
    0<wi≤1000
    输入样例
    4 5 6
    1 2 3
    2 4 4
    3 4 5
    4 5 6
    输出样例：
    8
*/
#include <iostream>

using namespace std;

const int N = 1010;

// 物品的数量、最大容积、最大重量
int n, v, m;
// f[i][j] 表示容积为i重量为j的最大价值
int f[N][N];
// 对应每件物品的体积、重量、价值
int vol[N], weight[N], value[N];

int main() {
    cin >> n >> v >> m;
    for (int i = 1; i <= n; i++)
        cin >> vol[i] >> weight[i] >> value[i];

    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= vol[i]; j--) {
            for (int k = m; k >= weight[i]; k--)
                f[j][k] = max(f[j][k], f[j - vol[i]][k - weight[i]] + value[i]);
        }
    }
    cout << f[v][m] << endl;
    return 0;
}