/**
 * @file Dijkstra.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-07 18:10:32
 * @brief Dijkstra算法
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 510;

int n, m;
// 使用邻接矩阵来存储
int g[N][N];
// 保存最短距离
int dist[N];
// 用来判断是否有加入到集合中
bool st[N];

int dijkstra() {
    // 先初始化为正无穷
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        // 找到不在集合S中距离最近的点
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        // 将t加入到集合
        st[t] = true;
        // 用t来更新其他点距离
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}