/**
 * @file Dijkstra.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-07 18:10:32
 * @brief Dijkstra堆优化算法
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
// first存储边权，second存储节点编号
typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n, m;
// 使用邻接表来存储
int h[N], w[N], e[N], ne[N], idx;
// 保存最短距离
int dist[N];
// 用来判断是否有加入到集合中
bool st[N];

/**
 * @brief 领接表的加边操作
 * @param a 
 * @param b 
 * @param c 
 */
void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
 
    while (heap.size()) {
        // 每次heap的top就是最小节点
        auto t = heap.top();
        heap.pop();
        int distance = t.first;
        int ver = t.second;
        // 已加入S这个集合中，跳出本次循环
        if (st[ver])
            continue;
        st[ver] = true;

        // 更新最短路
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}

int main() {
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    cout << dijkstra() << endl;

    return 0;
}