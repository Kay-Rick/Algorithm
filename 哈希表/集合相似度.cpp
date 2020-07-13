/**
 * @file 集合相似度.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-13 22:50:17
 * @brief 求两个集合交集中元素个数和并集中元素个数
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    给定两个整数集合，两个集合的相似度定义为 Nc/Nt×100%，其中 Nc 是两个集合中都存在的不同整数的数量，Nt 是两个集合中不同整数的数量。

    现在，请你计算给定集合的相似度。

    输入格式
    第一行包含整数 N，表示集合数量。

    接下来 N 行，每行包含一个集合的信息，首先包含一个整数 M，表示集合中的数的个数，然后包含 M 个整数，表示集合中的每个元素。

    再一行，包含整数 K，表示询问次数。

    接下来 K 行，每行包含一组询问，包括两个整数 a 和 b，表示询问集合 a 和集合 b 的相似度。

    所有集合的编号为 1∼N。

    输出格式
    每行输出一个询问的结果，保留一位小数。

    数据范围
    1≤N≤50,
    1≤M≤10000,
    1≤K≤2000,
    集合中的元素取值均在 [0,109] 范围内。

    输入样例：
    3
    3 99 87 101
    4 87 101 5 87
    7 99 101 18 5 135 18 99
    2
    1 2
    1 3
    输出样例：
    50.0%
    33.3%
*/

#include <iostream>
#include <unordered_set>

using namespace std;

const int N = 55;

int n;
unordered_set<int> S[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        while (m--) {
            int num;
            cin >> num;
            S[i].insert(num);
        }
    }

    int k;
    cin >> k;
    while (k--) {
        int a, b;
        cin >> a >> b;
        int nc = 0;
        int nt = 0;
        // nc求出两个集合交集元素有多少
        for (auto item : S[a]) {
            if (S[b].count(item))
                nc++;
        }
        // nt求出两个集合中不同元素一共有多少
        nt = S[a].size() + S[b].size() - nc;

        printf("%.1lf%\n", (double)nc / nt * 100);
    }

    return 0;
}