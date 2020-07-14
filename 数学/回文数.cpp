/**
 * @file 回文数.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-14 21:49:07
 * @brief 高精度加法问题
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    如果一个数字从前往后读和从后往前读都一样，那么这个数字就是回文数字。

    所有一位数字都是回文数字。

    非回文数字可以通过一系列的操作与回文数字配对。

    首先，将非回文数字反转，让反转后的数字与原数字相加，得到一个新的数字。

    如果新的数字不是回文数字，那么就重复此操作，直到得到回文数字为止。

    例如，我们从 67 开始，经过两次操作可以得到一个回文数字：67+76=143，143+341=484。

    对于给定的任意正整数 N，请你找到它的配对回文数并输出得到该回文数需要的操作次数。

    输入格式
    共一行，包含两个整数 N 和 K，分别表示给定整数以及最大操作次数。

    输出格式
    共两行，第一行输出配对回文数。

    第二行输出得到配对回文数所需要的操作次数。

    如果经过 K 次操作后，仍然无法得到回文数字。

    那么，第一行输出 K 次操作后得到的数字。

    第二行输出 K。

    数据范围
    1≤N≤1010
    1≤K≤100
    输入样例1：
    67 3
    输出样例1：
    484
    2
    输入样例2：
    69 3
    输出样例2：
    1353
    3
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 检查序列是否是回文序列
 * @param num 
 * @return true 
 * @return false 
 */
bool check(vector<int> &num) {
    for (int i = 0, j = num.size() - 1; i < j; i++, j--)
        if (num[i] != num[j])
            return false;
    return true;
}

/**
 * @brief 高精度加法
 * @param a 
 * @param b 
 * @return vector<int> 
 */
vector<int> add(vector<int> &a, vector<int> &b) {
    vector<int> c;
    for (int i = 0, t = 0; i < a.size() || i < b.size() || t; i++) {
        int s = t;
        if (i < a.size())
            s += a[i];
        if (i < b.size())
            s += b[i];
        c.push_back(s % 10);
        t = s / 10;
    }
    return c;
}

int main() {
    string n;
    int k;
    cin >> n >> k;

    vector<int> a;
    for (int i = n.size() - 1; i >= 0; i--)
        a.push_back(n[i] - '0');

    int cnt = 0;
    if (!check(a)) {
        while (cnt < k) {
            // 将a反向存入到b中
            vector<int> b(a.rbegin(), a.rend());
            a = add(a, b);
            cnt++;
            if (check(a))
                break;
        }
    }

    for (int i = a.size() - 1; i >= 0; i--)
        cout << a[i];

    cout << endl
         << cnt << endl;

    return 0;
}