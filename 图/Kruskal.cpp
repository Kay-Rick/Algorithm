/*
    给定一个n个点m条边的无向图，图中可能存在重边和自环，边权可能为负数。

    求最小生成树的树边权重之和，如果最小生成树不存在则输出impossible。

    给定一张边带权的无向图G=(V, E)，其中V表示图中点的集合，E表示图中边的集合，n=|V|，m=|E|。

    由V中的全部n个顶点和E中n-1条边构成的无向连通子图被称为G的一棵生成树，其中边的权值之和最小的生成树被称为无向图G的最小生成树。

    输入格式

    第一行包含两个整数n和m。

    接下来m行，每行包含三个整数u，v，w，表示点u和点v之间存在一条权值为w的边。

    输出格式

    共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出impossible。

    数据范围

    1≤n≤10^5 1≤n≤10^5,
    1≤m≤2∗10^5 1≤m≤2∗10^5,
    图中涉及边的边权的绝对值均不超过1000。

    输入样例：
    4 5
    1 2 1
    1 3 2
    1 4 3
    2 3 2
    3 4 4

    输出样例：
    6

*/
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