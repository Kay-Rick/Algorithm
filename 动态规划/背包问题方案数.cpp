/**
 * @file 背包问题方案数.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-12 17:03:02
 * @brief 背包问题求解方案数：状态转移时，加一个状态数组进行记录
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。

    第 i 件物品的体积是 vi，价值是 wi。

    求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。

    输出 最优选法的方案数。注意答案可能很大，请输出答案模 109+7 的结果。

    输入格式
    第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。

    接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。

    输出格式
    输出一个整数，表示 方案数 模 109+7 的结果。

    数据范围
    0<N,V≤1000
    0<vi,wi≤1000
    输入样例
    4 5
    1 2
    2 4
    3 4
    4 6
    输出样例：
    2
*/

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1010;
const int mod = 1e9 + 7;
const int inf = 1e6;

int n, m;
int v[N], w[N];

int f[N];
// 体积恰好是j的方案数为g[j]
int g[N];

int main() {
    cin >> n >> m;
    g[0] = 1;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            int temp = max(f[j], f[j - v[i]] + w[i]);
            int sum = 0;
            // 从f[j]转移过来
            if (temp == f[j])
                sum += g[j];
            // 从f[j - v[i]]转移过来
            if (temp == f[j - v[i]] + w[i])
                sum += g[j - v[i]];
            if (sum >= mod)
                sum -= mod;
            f[j] = temp;
            g[j] = sum;
        }
    }

    // 不一定是容积最大时达到最大值
    int maxw = 0;
    for (int i = 0; i <= m; i++)
        maxw = max(maxw, f[i]);
    int res = 0;
    for (int i = 0; i <= m; i++) {
        if (maxw == f[i]) {
            res += g[i];
            if (res >= mod)
                res -= mod;
        }
    }
    cout << res << endl;
    return 0;
}