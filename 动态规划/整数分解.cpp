/**
 * @file 整数分解.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-13 22:42:03
 * @brief 等价于二维完全背包
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    正整数 N 的 K−P 分解，是将 N 写为 K 个正整数的 P 次幂的和。

    请你编写一个程序，给定 N,K,P 的情况下，找到 N 的 K−P 分解。

    输入格式
    共一行，包含三个整数 N,K,P。

    输出格式
    如果存在 N 的 K−P 分解，则以如下格式输出：

    N = n[1]^P + ... n[K]^P
    其中，n[i] 是第 i 个因子，所有因子必须按照不升序顺序输出。

    注意，答案也许不唯一。

    例如，169 的 5−2 分解共有 9 种，如 122+42+22+22+12，112+62+22+22+22 等等。

    你需要输出各因子之和最大的一种解法。

    如果仍不能确定唯一解法，则选择因子序列更大的解法。

    我们称序列 {a1,a2,…,aK} 大于序列 {b1,b2,…,bK}，当且仅当存在 1≤L≤K，满足当 i<L 时，ai=bi 且 aL>bL。

    如果无解，则直接输出 Impossible。

    数据范围
    1≤K≤N≤400,
    2≤P≤7
    输入样例1：
    169 5 2
    输出样例1：
    169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
    输入样例2：
    169 167 3
    输出样例2：
    Impossible
*/

#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 410;
int n, p, k;

/*
背包容量为N，重量不超过k
每个物品i从1到20中选，每个物品i对应的体积为i^p，重量为1，价值为i
设f[i][j][k]为从前i个物品中选，体积恰好为j重量恰好为k的最大价值的方案
f[21][410][410]
*/
int f[21][N][N];
int vol[N], weight[N], value[N];

int main() {
    cin >> n >> k >> p;
    // 初始化
    memset(f, -0x3f, sizeof f);
    f[0][0][0] = 0;

    // 记录最终状态需要几轮
    int cnt = 0;
    // 自己计算出对应物品的体积、重量和价值
    for (int i = 1; i <= 20; i++) {
        if (pow(i, p) > n)
            break;
        vol[i] = pow(i, p);
        weight[i] = 1;
        value[i] = i;
        cnt++;
    }

    for (int i = 1; i <= cnt; i++) {
        for (int j = 0; j <= n; j++) {
            for (int m = 0; m <= k; m++) {
                f[i][j][m] = f[i - 1][j][m];
                if (j >= vol[i] && m >= weight[i])
                    f[i][j][m] = max(f[i][j][m], f[i][j - vol[i]][m - weight[i]] + value[i]);
            }
        }
    }

    if (f[cnt][n][k] < 0)
        cout << "Impossible" << endl;
    else {
        bool is_first = true;
        for (int i = cnt, j = n, m = k; i && j && m; i--) {
            // 看状态是否可以转移过来
            while (f[i][j][m] == f[i][j - vol[i]][m - weight[i]] + value[i]) {
                if (is_first) {
                    cout << n << " = " << i << "^" << p;
                    is_first = false;
                } else {
                    cout << " + " << i << "^" << p;
                }
                j -= vol[i];
                m -= weight[i];
            }
        }
    }

    return 0;
}