/**
 * @file 朋友数.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-13 22:52:03
 * @brief 
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    如果两个整数各位数字的和是一样的，则被称为是“朋友数”，而那个公共的和就是它们的“朋友证号”。

    例如 123 和 51 就是朋友数，因为 1+2+3=5+1=6，而 6 就是它们的朋友证号。

    给定一些整数，要求你统计一下它们中有多少个不同的朋友证号。

    输入格式
    输入第一行给出正整数 N。

    随后一行给出 N 个正整数，数字间以空格分隔。

    输出格式
    首先第一行输出给定数字中不同的朋友证号的个数；

    随后一行按递增顺序输出这些朋友证号，数字间隔一个空格，且行末不得有多余空格。

    数据范围
    1≤N≤10000,
    给定正整数均不超过 10000。

    输入样例：
    8
    123 899 51 998 27 33 36 12
    输出样例：
    4
    3 6 9 26
*/

#include <iostream>
#include <set>

using namespace std;

int n;
set<int> s;

int calu(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    cin >> n;
    while (n--) {
        int nums;
        cin >> nums;
        s.insert(calu(nums));
    }
    cout << s.size() << endl;
    bool is_first = true;
    for (auto a : s) {
        if (is_first) {
            cout << a;
            is_first = false;
        } else
            cout << ' ' << a;
    }
    return 0;
}