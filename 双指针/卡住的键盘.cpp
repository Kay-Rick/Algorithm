/**
 * @file 卡住的键盘.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-13 22:41:07
 * @brief 
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    在一个损坏的键盘上，某些键总是被卡住。

    因此，当你用该键盘输入一些句子时，与这些键相对应的字符将在屏幕上重复出现 k 次。

    现在，给定 k 以及最终屏幕显示的结果字符串，请你找出所有可能坏掉的按键，并给出原始字符串。

    注意，有些字符可能被重复键入。

    每当卡住的按键被按下时，其对应的字符将固定被输出 k 次。

    例如，当 k=3 时，从字符串 thiiis iiisss a teeeeeest，我们可以推断出 i 和 e 可能被卡住了，但是 s 并没有被卡住，尽管它也重复出现过。

    所以，原始字符串可能是 this isss a teest。

    输入格式
    第一行包含整数 k。

    第二行包含屏幕中显示的结果字符串，字符串中只包含 {a-z}, {0-9}, _。

    输出格式
    按照检测顺序在一行中输出所有可能卡住的按键，每个按键只需输出一次。

    第二行输出原始字符串。

    数据范围
    2≤k≤100,
    输入字符串非空且长度不超过 1000,
    至少包含一个卡住的按键。

    输入样例：
    3
    caseee1__thiiis_iiisss_a_teeeeeest
    输出样例：
    ei
    case1__this_isss_a_teest
*/

#include <iostream>
#include <string>

using namespace std;

const int N = 200;

string str;
int k;
int st[N];

int main() {
    cin >> k >> str;
    for (int i = 0; i < str.size(); i++) {
        // 双指针算法
        int j = i + 1;
        while (j < str.size() && str[j] == str[i])
            j++;
        int len = j - i;
        // 不是k的整倍数，说明键盘不是坏的
        if (len % k != 0)
            st[str[i]] = 1;
        // 跳到i - 1的位置，i++自动跳到j的位置
        i = j - 1;
    }

    for (int i = 0; i < str.size(); i++) {
        if (st[str[i]] == 0) {
            cout << str[i];
            st[str[i]] = 2;
        }
    }
    cout << endl;

    string res;
    for (int i = 0; i < str.size(); i++) {
        if (st[str[i]] == 1)
            res += str[i];
        else {
            res += str[i];
            i += k - 1;
        }
    }
    cout << res << endl;
    return 0;
}