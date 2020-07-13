/**
 * @file 连续因子.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-13 22:38:22
 * @brief 
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    在一个正整数 N 的所有因子中，可能存在几个连续的数字。

    例如，630 可以分解为 3×5×6×7，其中 5、6、7 是三个连续的数字。

    现在给定任意正整数 N，请你找到最大连续因子数，并列出连续因子的最小序列。

    输入格式
    一个正整数 N。

    输出格式
    第一行输出最大连续因子数。

    第二行以 factor[1]*factor[2]*...*factor[k] 的格式输出连续因子的最小序列。

    因子按升序排序，不包括 1。

    数据范围
    1<N<231
    输入样例：
    630
    输出样例：
    3
    5*6*7
*/

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int start;
    int length = 0;
    // 先枚举左端点
    for (int i = 2; i <= n / i; i++) {
        int sz = 0;
        if (n % i == 0) {
            int t = n;
            // 枚举区间长度
            for (int j = i; t % j == 0; j++) {
                sz++;
                t /= j;
            }
        }
        if (length < sz) {
            length = sz;
            start = i;
        }
    }
    if (length == 0) {
        cout << 1 << endl;
        cout << n << endl;
    } else {
        cout << length << endl;
        cout << start;
        for (int i = 1; i < length; i++)
            cout << '*' << start + i;
        cout << endl;
    }
    return 0;
}