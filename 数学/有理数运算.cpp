/**
 * @file 有理数运算.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-13 22:36:18
 * @brief 有理数的四则运算(注意辗转相除求最大公约数)
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    给定两个有理数，你的任务是实现基本算术，即计算它们的和，差，积和商。

    输入格式
    共一行，以 a1/b1 a2/b2 的形式给出两个有理数。

    分子和分母都在 long int 范围内，如果存在负号，则只能出现在分子前面，分母保证为非零数字。

    输出格式
    分别在四行输出两个有理数的和，差，积和商。

    每行的格式为 number1 operator number2 = result。

    请注意，所有有理数都必须采用最简形式，k a/b，其中 k 是整数部分，而 a/b 是最简分数部分。

    如果数字为负，则必须将其包含在一对括号中。

    如果除法中除数为 0，则输出 Inf 作为结果。

    确保所有输出整数都在 long int 范围内。

    输入样例1：
    2/3 -4/2
    输出样例1：
    2/3 + (-2) = (-1 1/3)
    2/3 - (-2) = 2 2/3
    2/3 * (-2) = (-1 1/3)
    2/3 / (-2) = (-1/3)
    输入样例2：
    5/3 0/6
    输出样例2：
    1 2/3 + 0 = 1 2/3
    1 2/3 - 0 = 1 2/3
    1 2/3 * 0 = 0
    1 2/3 / 0 = Inf
*/

#include <iostream>
#include <string>

using namespace std;

typedef long long LL;
string str1, str2;

// 求最大公约数
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

void print(LL a, LL b) {
    LL t = gcd(a, b);
    a /= t;
    b /= t;
    // 把负号转到分子上面来
    if (b < 0) {
        a *= -1;
        b *= -1;
    }
    bool flag = a < 0;
    // 对负号加括号处理
    if (flag)
        cout << '(';
    if (b == 1)
        cout << a;
    else {
        // 存在整数部分，先输出整数部分
        if (abs(a) >= b) {
            cout << a / b << ' ';
            a = abs(a) % b;
        }
        cout << a << '/' << b;
    }

    // 对符号加括号处理
    if (flag)
        cout << ')';
}

// a/b + c/d
void add(LL a, LL b, LL c, LL d) {
    print(a, b);
    cout << " + ";
    print(c, d);
    cout << " = ";
    a = a * d + b * c;
    b = b * d;
    print(a, b);
    cout << endl;
}

// a/b - c/d
void sub(LL a, LL b, LL c, LL d) {
    print(a, b);
    cout << " - ";
    print(c, d);
    cout << " = ";
    a = a * d - b * c;
    b = b * d;
    print(a, b);
    cout << endl;
}

// a/b * c/d
void mul(LL a, LL b, LL c, LL d) {
    print(a, b);
    cout << " * ";
    print(c, d);
    cout << " = ";
    a = a * c;
    b = b * d;
    print(a, b);
    cout << endl;
}

// a/b / c/d
void div(LL a, LL b, LL c, LL d) {
    print(a, b);
    cout << " / ";
    print(c, d);
    cout << " = ";
    if (c == 0)
        cout << "Inf" << endl;
    else {
        a = a * d;
        b = b * c;
        print(a, b);
        cout << endl;
    }
}
int main() {
    LL a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    add(a, b, c, d);
    sub(a, b, c, d);
    mul(a, b, c, d);
    div(a, b, c, d);

    return 0;
}