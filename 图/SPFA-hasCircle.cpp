/*
    给定一个n个点m条边的有向图，图中可能存在重边和自环，边权可能为负数。

    请你判断图中是否存在负权回路。

    输入格式

    第一行包含整数n和m。

    接下来m行每行包含三个整数x，y，z，表示存在一条从点x到点y的有向边，边长为z。

    输出格式

    如果图中存在负权回路，则输出“Yes”，否则输出“No”。

    数据范围

    1≤n≤20001≤n≤2000,
    1≤m≤100001≤m≤10000,
    图中涉及边长绝对值均不超过10000。

    输入样例：
    3 3
    1 2 -1
    2 3 4
    3 1 -4

    输出样例：
    Yes

*/
/**
 * @file SPFA-hasCircle.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-08 22:28:12
 * @brief SPFA判断回路里面是否有负环
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 2010, M = 10010;
typedef pair<int, int> PII;

int n, m;
vector<PII> g[N];
int dist[N];
// 记录最短路的边数，cnt[x] >= n 表示有环
int cnt[N];
bool st[N];

bool spfa() {
    queue<int> q;
    // 将所有点都入队：因为以前只是求固定一个点
    // 但存在负权回路的时候，不一定所有点都能经过负权回路
    for (int i = 1; i <= n; i++) {
        st[i] = true;
        q.push(i);
    }
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        // 出队了进行标记，没有在队列里面
        st[t] = false;

        for (int i = 0; i < g[t].size(); i++) {
            int j = g[t][i].first;
            int w = g[t][i].second;
            // 当前需要更新
            if (dist[j] > dist[t] + w) {
                dist[j] = dist[t] + w;
                cnt[j] = cnt[t] + 1;
                // 最短路的边数 >= n 表示存在环
                if (cnt[j] >= n)
                    return true;
                if (!st[j]) {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    if (spfa())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}