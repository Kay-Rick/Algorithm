/**
 * @file 质数.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-13 22:43:58
 * @brief 筛质数等相关算法
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1010, M = 40000;

bool st[M];
int primes[M];
int cnt;

// 判断一个数是否是质数
bool isPrime(int x) {
    if (x == 1)
        return false;
    else if (x == 2)
        return true;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

// 筛出1 ~ M之间的所有质数
void init() {
    for (int i = 2; i < M; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            // 从 2 开始所有是 i 的倍数的数都不是质数
            for (int j = i * 2; j < M; j += i)
                st[j] = true;
        }
    }
}

// 检查数x是否是质数,我们只需要枚举1~根号x之间质数是否可被相除
bool check(int x) {
    for (int i = 0; primes[i] <= x / primes[i]; i++) {
        if (x % primes[i] == 0)
            return false;
    }
    return true;
}
