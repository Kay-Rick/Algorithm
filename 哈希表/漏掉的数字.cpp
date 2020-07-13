/**
 * @file 漏掉的数字.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-13 22:52:43
 * @brief 
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    给定 N 个整数，请你找出最小的不在给定整数列表中的正整数。

    输入格式
    第一行包含整数 N。

    第二行包含 N 个整数，整数之间用空格隔开，所有数字都在 int 范围内。

    输出格式
    输出不在给定整数列表中的最小正整数。

    数据范围
    1≤N≤105
    输入样例：
    10
    5 -25 9 6 1 3 4 2 5 17
    输出样例：
    7
*/

#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> s;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        s.insert(num);
    }
    for (int i = 1;; i++) {
        if (!s.count(i)) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}