/**
 * @file 1的个数.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-13 22:32:34
 * @brief 
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    给定一个数字 N，请你计算 1∼N 中一共出现了多少个数字 1。

    例如，N=12 时，一共出现了 5 个数字 1，分别出现在 1,10,11,12 中。

    输入格式
    包含一个整数 N。

    输出格式
    输出一个整数，表示 1 的个数。

    数据范围
    1≤N≤230
    输入样例：
    12
    输出样例：
    5
*/

#include <iostream>
#include <vector>

using namespace std;

int cacl(int x) {
    // 存放每一个位数
    vector<int> nums;
    int res = 0;

    while (x) {
        nums.push_back(x % 10);
        x /= 10;
    }

    for (int i = nums.size() - 1; i >= 0; i--) {
        int digit = nums[i];
        int left = 0;
        int right = 0;
        int power = 1;
        // 记录该位左边的数字
        for (int j = nums.size() - 1; j > i; j--)
            left = left * 10 + nums[j];
        // 记录该位右边的数字
        for (int j = i - 1; j >= 0; j--) {
            right = right * 10 + nums[j];
            power *= 10;
        }
        if (digit == 0)
            res += left * power;
        else if (digit == 1) {
            res += left * power;
            res += right + 1;
        } else
            res += (left + 1) * power;
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    cout << cacl(n) << endl;

    return 0;
}