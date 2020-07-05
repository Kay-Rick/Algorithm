/**
 * @file kmp.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-04 16:55:19
 * @brief KMP算法：时间复杂度O(n)
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>

using namespace std;

const int N = 100010, M = 1000010;

int n, m;
char p[N], s[M];
int ne[N];

int main() {
    cin >> n >> p + 1 >> m >> s + 1;

    // 求next数组：相当于匹配过程
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }

    // KMP匹配过程，j从0开始
    for (int i = 1, j = 0; i <= m; i++) {
        // 没有匹配上，j后退到next[j]的位置
        while (j && s[i] != p[j + 1])
            j = ne[j];
        // 匹配上了
        if (s[i] == p[j + 1])
            j++;
        if (j == n) {
            // 输出起点位置
            cout << i - n << ' ';
            // j往后面走，继续匹配看是否还存在匹配的串
            j = ne[j];
        }
    }
    return 0;
}