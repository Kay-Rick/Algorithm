/**
 * @file Floyd.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-30 00:42:40
 * @brief Floyd算法：多源最短路算法
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 210;
const int INF = 1e9;

int n, m, Q;
// d[i][j] 存储所有边，执行完floyd算法存的就是i到j的最短距离
int d[N][N];

// 求多源汇最短路floyd算法
void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                // 上一层：从i出发只经过i~k-1到j的距离
                // d[i][k] + d[k][j] 经过k的距离
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}

int main() {
    cin >> n >> m >> Q;
    // 邻接矩阵初始化
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    floyd();

    while (Q--) {
        int a, b;
        cin >> a >> b;
        int t = d[a][b];
        if (t > INF / 2)
            cout << "impossible" << endl;
        else
            cout << t << endl;
    }

    return 0;
}