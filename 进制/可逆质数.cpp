/**
 * @file 可逆质数.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-15 16:02:51
 * @brief 进制转换
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    给定两个整数 N 和 D，如果 N 是一个质数，并且将 N 转化为 D 进制表示后，再进行反转，得到的新数字转化为十进制表示后如果也是一个质数，则称 N 在 D 进制系统中，是一个可逆质数。

    例如，N=73,D=10，则 73 是质数，其十进制表示反转后为 37 也是质数，所以 73 在十进制系统中是一个可逆质数。

    N=23,D=2，则 23 是质数，其二进制表示为 10111，反转后得到 11101，转化为十进制后为 29，这也是一个质数，所以 23 在二进制系统中是一个可逆质数。

    现在，请你判断所给 N 在 D 进制系统中是否是一个可逆质数。

    输入格式
    输入包含多组测试数据。

    每组数据共一行，包含两个整数 N 和 D。

    当输入一行为一个负数时，表示输入停止。

    输出格式
    对于每组数据，输出一个结果，占一行。

    如果所给 N 在 D 进制系统中是一个可逆质数，则输出 Yes，否则输出 No。

    数据范围
    1≤N<105,
    1<D≤10
    输入样例：
    73 10
    23 2
    23 10
    -2
    输出样例：
    Yes
    Yes
    No
*/

#include <iostream>

using namespace std;

typedef long long LL;

/**
 * @brief 检查n是否是质数
 * @param n 
 * @return true 
 * @return false 
 */
bool is_prime(int n) {
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool check(int n, int d) {
    if (!is_prime(n))
        return false;
    LL r = 0;
    // 秦九韶算法:这里将数翻转转换成r进制又转换成十进制
    while (n) {
        r = r * d + n % d;
        n /= d;
    }
    return is_prime(r);
}

int main() {
    int n, d;

    while (cin >> n >> d, n >= 1) {
        if (check(n, d))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}