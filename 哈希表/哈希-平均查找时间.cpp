/**
 * @file 哈希-平均查找时间.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-13 22:57:11
 * @brief 
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    这个问题的任务很简单：

    首先将一个由若干个不同正整数构成的整数序列插入到一个哈希表中，然后尝试从表中查找另一个整数键值序列，并输出平均查找时间（查找时间指查找某个值是否在表中所进行的比较操作的次数）。

    哈希函数定义为 H(key)=key%TSize，其中 TSize 是哈希表的最大大小。

    利用只具有正增量的二次探测法来解决冲突。

    注意，哈希表的大小最好是素数，如果用户给出的最大大小不是素数，则必须将表大小重新定义为大于用户给出的大小的最小素数。

    输入格式
    第一行包含三个正整数 MSize,N,M，分别表示用户定义的表的大小，插入整数的数量，查找键值的数量。

    第二行包含 N 个不同的正整数，表示插入序列。

    第三行包含 M 个正整数，表示键值序列。

    同行数字之间用空格隔开，两个序列中包含的整数均不超过 105。

    输出格式
    如果无法插入一些数字，则将其按顺序以如下格式输出，每个数字占一行：

    X cannot be inserted.
    其中 X 表示无法插入的数字。

    最后一行输出 M 次查找的平均查找时间，保留一位小数。

    注意： 如果查找了 TSize 次，每次查找的位置上均有数，但都不等于要查找的数，则认为查找时间是 TSize+1。

    数据范围
    1≤MSize,N,M≤104
    输入样例：
    4 5 4
    10 6 4 15 11
    11 4 15 2
    输出样例：
    15 cannot be inserted.
    2.8
*/

#include <iostream>
#include <unordered_set>

using namespace std;

const int N = 10010;

int ms, n, m;
bool st[N];
int h[N];

// 筛出质数
void init() {
    st[1] = false;
    for (int i = 2; i < N; i++) {
        if (!st[i]) {
            for (int j = i * 2; j < N; j += i)
                st[j] = true;
        }
    }
}

int reset(int x) {
    if (!st[x])
        return x;
    else {
        int i = x;
        while (st[i])
            i++;
        return i;
    }
}

pair<int, int> find(int x) {
    int key = x % ms;
    // 进行平方探测
    int k;
    for (k = 0; k < ms; k++) {
        int i = (key + k * k) % ms;
        // 插入的是不同的整数，查找和插入可在这里合并
        if (h[i] == 0 || h[i] == x)
            return {i, k + 1};
    }
    return {-1, ms + 1};
}

int main() {
    init();
    cin >> ms >> n >> m;
    // 重设hash表长度
    ms = reset(ms);

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        auto t = find(num);
        if (t.first == -1)
            cout << num << ' ' << "cannot be inserted." << endl;
        else
            h[t.first] = num;
    }

    int sum = 0;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        auto t = find(num);
        sum += t.second;
    }
    printf("%.1lf\n", (double)sum / m);
    return 0;
}