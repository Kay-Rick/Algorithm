/**
 * @file 质因子.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-13 22:34:46
 * @brief 分解质因子
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    给定一个整数 N，找出它的所有质因子，并按如下格式输出：

    N=pk11×pk22×…×pkmm
    注意: 如果 N=1 则输出 1=1。

    输入格式
    一个整数 N。

    输出格式
    输出时，按 N=p1^k1*p2^k2*...*pm^km 的格式输出答案。

    其中 pi 是质因子，应按照递增顺序排列，ki 是 pi 的指数，如果 ki 为 1，则不必输出。

    数据范围
    1≤N≤231−1
    输入样例：
    97532468
    输出样例：
    97532468=2^2*11*17*101*1291
*/

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n << '=';

    if (n == 1)
        cout << 1 << endl;
    else {
        bool is_first = true;
        // 从最小的质数2开始分解，分解到 根号n
        for (int i = 2; i <= n / i; i++) {
            // 如果满足就一直先分解下去
            if (n % i == 0) {
                // 记录每次分解的次数
                int k = 0;
                while (n % i == 0) {
                    k++;
                    n /= i;
                }
                if (!is_first)
                    cout << '*';
                else
                    is_first = false;
                cout << i;
                if (k > 1)
                    cout << '^' << k;
            }
        }
        if (n > 1) {
            if (!is_first)
                cout << '*';
            cout << n;
        }
    }

    return 0;
}