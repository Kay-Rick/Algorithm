/**
 * @file Prim.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-29 22:02:16
 * @brief Prim算法
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 510;
const int M = 100010;
const int INF = 0x3f3f3f3f;

int n, m;
int dist[N];
bool st[N];
int g[N][N];

int prim() {
    // prim算法中dist[j]表示当前点到集合的距离
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for (int i = 0; i < n; i++) {
        // 找到距离集合最近的点
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        // 不是第一个点且dist[t]为正无穷的情况,说明没有找到
        if (i != 0 && dist[t] == INF)
            return INF;
        // 放在前面，防止有环的出现
        if (i != 0)
            res += dist[t];
        // 用t更新其他点到集合的距离
        for (int j = 1; j <= n; j++) {
            // Dijkstra算法找的是距起点的距离
            // Prim算法找的是距离集合的距离
            dist[j] = min(dist[j], g[t][j]);
        }

        st[t] = true;
    }
    return res;
}

int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();
    if (t == INF)
        cout << "impossible" << endl;
    else
        cout << t << endl;

    return 0;
}
