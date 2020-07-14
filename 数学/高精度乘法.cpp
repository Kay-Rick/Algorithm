/**
 * @file 高精度乘法.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-14 21:38:47
 * @brief 一个高精度的数乘2
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    请注意，数字 123456789 是一个 9 位数字，完全由 1 到 9 组成，没有重复。

    将其加倍，我们将获得 246913578，它恰好是另一个 9 位数字，恰好由 1 到 9 组成，只是排列不同。

    现在，给定你一个 k 位的数字，请你判断将其加倍以后得到的数字是否可以由原数字的各数位重新排列得到。

    输入格式
    共一行，包含一个整数。

    输出格式
    输出共两行

    如果原数字的各数位重新排列可以得到加倍后的数字，则在第一行输出 Yes，否则输出 No。

    第二行，输出加倍后得到的数字。

    数据范围
    输入数字不超过 20 位。

    输入样例：
    1234567899
    输出样例：
    Yes
    2469135798
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string nums;
    cin >> nums;
    vector<int> a, b;
    // 倒序存入数组，类比于多项式
    for (int i = nums.size() - 1; i >= 0; i--) {
        a.push_back(nums[i] - '0');
    }
    // 设置进位
    int con = 0;
    for (int i = 0; i < a.size(); i++) {
        int num = a[i] * 2 + con;
        b.push_back(num % 10);
        con = num / 10;
    }
    // 加入进位
    if (con == 1) {
        b.push_back(1);
    }
    // 若排序后数组是一样的，则说明满足条件
    vector<int> c = b;
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    if (a == c)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    for (int i = b.size() - 1; i >= 0; i--) {
        cout << b[i];
    }
    return 0;
}