/*
    给定一个n个点m条边的有向图，图中可能存在重边和自环， 边权可能为负数。

    请你求出从1号点到n号点的最多经过k条边的最短距离，如果无法从1号点走到n号点，输出impossible。

    注意：图中可能 存在负权回路 。

    输入格式

    第一行包含三个整数n，m，k。

    接下来m行，每行包含三个整数x，y，z，表示存在一条从点x到点y的有向边，边长为z。

    输出格式

    输出一个整数，表示从1号点到n号点的最多经过k条边的最短距离。

    如果不存在满足条件的路径，则输出“impossible”。

    数据范围

    1≤n,k≤5001≤n,k≤500,
    1≤m≤100001≤m≤10000,
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
 * @file SPFA.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-08 21:07:47
 * @brief SPFA算法求最短路
 *          在Bellman-Ford算法中dist[b] = min(dist[b], dist[a] + w);
 *          如果dist[a]没有变小，那么这个操作一定会是无效的操作
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 100010;
// 第一个位置存储编号，第二个位置存储边权
typedef pair<int, int> PII;

int n, m;
vector<PII> g[N];
int dist[N];
bool st[N];

int spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;
    // 利用BFS的思想优化Bellman-Ford算法就是SPFA
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = 0; i < g[t].size(); i++) {
            int j = g[t][i].first;
            int w = g[t][i].second;
            // 队列中存的就是那些变小的节点：更新过谁，我再拿谁更新别人
            if (dist[j] > dist[t] + w) {
                dist[j] = dist[t] + w;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return dist[n];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // 加一条从a到b的边，边权为c
        g[a].push_back({b, c});
    }

    int t = spfa();

    if (t == 0x3f3f3f3f)
        cout << "impossible" << endl;
    else
        cout << t << endl;

    return 0;
}