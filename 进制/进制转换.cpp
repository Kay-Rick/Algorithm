/**
 * @file 进制转换.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-15 15:59:36
 * @brief 秦九韶算法
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    给定一对正整数，例如 6 和 110，此等式 6=110 是否成立？

    答案是可以成立，当 6 是十进制数字，110 是二进制数字时等式得到满足。

    现在，给定一个正整数数对 N1,N2，并给出其中一个数字的进制，请你求出另一个数字在什么进制下，两数相等成立。

    输入格式
    输入共一行，包含四个正整数，格式如下：

    N1 N2 tag radix
    N1 和 N2 是两个不超过 10 位的数字，radix 是其中一个数字的进制，如果 tag 为 1，则 radix 是 N1 的进制，如果 tag 为 2，则则 radix 是 N2 的进制。

    注意，一个数字的各个位上的数都不会超过它的进制，我们用 0∼9 表示数字 0∼9，用 a∼z 表示 10∼35。

    输出格式
    输出使得 N1=N2 成立的另一个数字的进制数。

    如果等式不可能成立，则输出 Impossible。

    如果答案不唯一，则输出更小的进制数。

    数据范围
    2≤radix≤36
    输入样例1：
    6 110 1 10
    输出样例1：
    2
    输入样例2：
    1 ab 1 2
    输出样例2：
    Impossible
*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef long long LL;

// 将进制表示的符号映射到10进制下的进制表示
int get(char c) {
    if (c <= '9')
        return c - '0';
    return c - 'a' + 10;
}

// 秦九韶算法求n在r进制下的十进制数是多少
LL calc(string n, LL r) {
    LL res = 0;
    for (auto c : n) {
        if ((double)res * r + get(c) > 1e16)
            return 1e18;
        res = res * r + get(c);
    }
    return res;
}

int main() {
    string n1, n2;
    cin >> n1 >> n2;
    int tag, radix;
    cin >> tag >> radix;

    if (tag == 2)
        swap(n1, n2);
    // 计算n1在radix进制下十进制数是多少
    LL target = calc(n1, radix);

    // 二分找结果
    LL l = 0;
    LL r = max(target, 36ll);
    // 找到n2的最小进制数
    for (auto c : n2)
        l = max(l, (LL)get(c) + 1);

    while (l < r) {
        LL mid = l + r >> 1;
        if (calc(n2, mid) >= target)
            r = mid;
        else
            l = mid + 1;
    }

    if (calc(n2, r) != target)
        cout << "Impossible" << endl;
    else
        cout << r << endl;
    return 0;
}