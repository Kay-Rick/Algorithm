/**
 * @file Kruskal.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-29 22:25:51
 * @brief Kruskal算法：有条件的加入n - 1条边
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 200010;

int n, m;
int p[N];

struct Edge {
    int a, b, w;
    // 重载小于号，方便排序
    bool operator< (const Edge &e) const {
        return w < e.w;
    }
} edges[N];

// 并查集找祖宗节点
int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    // 对边按权值大小排序
    sort(edges, edges + m);

    // 初始化并查集
    for (int i = 1; i <= n; i++)
        p[i] = i;

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a;
        int b = edges[i].b;
        int w = edges[i].w;

        // 找是否在一个集合中
        a = find(a);
        b = find(b);

        // 没有在一个集合当中，要再a和b之间加一条边, 边权已经排序，直接加入权值
        if (a != b) {
            p[a] = b;
            res += w;
            cnt++;
        }
    }

    if (cnt < n - 1)
        cout << "impossible" << endl;
    else
        cout << res << endl;
    return 0;
}