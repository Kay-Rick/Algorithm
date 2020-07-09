/*
    求有边数限制的最短路

    给定一个n个点m条边的有向图，图中可能存在重边和自环，边权可能为负数。

    请你求出从1号点到n号点的最多经过k条边的最短距离，如果无法从1号点走到n号点，输出impossible。

    注意：图中可能存在负权回路 。

    输入格式

    第一行包含三个整数n，m，k。

    接下来m行，每行包含三个整数x，y，z，表示存在一条从点x到点y的有向边，边长为z。

    输出格式

    输出一个整数，表示从1号点到n号点的最多经过k条边的最短距离。

    如果不存在满足条件的路径，则输出“impossible”。

    数据范围

    1≤n,k≤500,
    1≤m≤10000,
    任意边长的绝对值不超过10000。

    输入样例：
    3 3 1
    1 2 1
    2 3 1
    1 3 3
    输出样例：
    3

*/
/**
 * @file Bellman-Ford.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-08 21:30:56
 * @brief Bellman-Ford算法求有边数限制的最短路
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 10010;

int n, m, k;
int dist[N], backup[N];

struct Edge {
    int a;
    int b;
    int w;
} edge[M];

int bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < k; i++) {
        // 做数组拷贝，防止在下面的更新操作中被串联更新
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j++) {
            auto e = edge[j];
            dist[e.b] = min(dist[e.b], backup[e.a] + e.w);
        }
    }
    // 这里不直接写等于无穷：是因为有可能距离无穷的那个节点在里层的for循环会更新下一个无穷的节点
    if (dist[n] > 0x3f3f3f3f / 2)
        return -1;
    else
        return dist[n];
}

int main() {

    cin >> n >> m >> k;
    // 读入m条边
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edge[i] = {a, b, w};
    }

    int t = bellman_ford();
    if (t == -1)
        cout << "impossible" << endl;
    else
        cout << t << endl;
    return 0;
}