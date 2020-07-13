/**
 * @file 哈希.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-13 22:54:20
 * @brief 
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    将一个由若干个不同正整数构成的整数序列插入到一个哈希表中，然后输出输入数字的位置。

    哈希函数定义为 H(key)=key%TSize，其中 TSize 是哈希表的最大大小。

    利用只具有正增量的二次探测法来解决冲突。

    注意，哈希表的大小最好是素数，如果用户给出的最大大小不是素数，则必须将表大小重新定义为大于用户给出的大小的最小素数。

    输入格式
    第一行包含两个整数 MSize 和 N，分别表示用户定义的表的大小以及输入数字的数量。

    第二行包含 N 个不同的正整数，数字之间用空格隔开。

    输出格式
    在一行中，输出每个输入数字的相应位置（索引从 0 开始），数字之间用空格隔开，行尾不得有多余空格。

    如果无法插入某个数字，则输出 -。

    数据范围
    1≤MSize≤104,
    1≤N≤MSize,
    输入数字均在 [1,105] 范围内。

    输入样例：
    4 4
    10 6 4 15
    输出样例：
    0 1 4 -
*/

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

const int N = 10010;

int m, n;
bool st[N];
int primes[N], cnt;
int h[N];
unordered_set<int> S;

// 筛选出1~N之间的所有质数
void init() {
    st[1] = true;
    for (int i = 2; i < N; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            for (int j = i * 2; j < N; j += i)
                st[j] = true;
        }
    }
}
// 对hash表大小进行重新设置
int reset(int x) {
    if (!st[x])
        return x;
    else {
        int i = 0;
        while (primes[i] <= x)
            i++;
        return primes[i];
    }
}

// 平方探测
int find(int x) {
    int t = x % m;
    for (int k = 0; k < m; k++) {
        int i = (t + k * k) % m;
        if (h[i] == 0)
            return i;
    }
    return -1;
}

int main() {
    init();
    cin >> m >> n;
    m = reset(m);
    cout << m << endl;
    string res;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        int t = find(num);
        if (t == -1)
            cout << '-';
        else {
            h[t] = num;
            cout << t;
        }
        if (i != n - 1)
            cout << ' ';
    }
    cout << endl;
    return 0;
}