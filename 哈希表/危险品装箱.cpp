/**
 * @file 危险品装箱.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-13 22:53:32
 * @brief 
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    集装箱运输货物时，我们必须特别小心，不能把不相容的货物装在一只箱子里。

    比如氧化剂绝对不能跟易燃液体同箱，否则很容易造成爆炸。

    本题给定一张不相容物品的清单，需要你检查每一张集装箱货品清单，判断它们是否能装在同一只箱子里。

    输入格式
    输入第一行给出两个正整数：N 是成对的不相容物品的对数；M 是集装箱货品清单的单数。

    随后数据分两大块给出。第一块有 N 行，每行给出一对不相容的物品。

    第二块有 M 行，每行给出一箱货物的清单，格式如下：

    K G[1] G[2] ... G[K]
    其中 K 是物品件数，G[i] 是物品的编号。

    简单起见，每件物品用一个 5 位数的编号代表。

    两个数字之间用空格分隔。

    输出格式
    对每箱货物清单，判断是否可以安全运输。

    如果没有不相容物品，则在一行中输出 Yes，否则输出 No。

    数据范围
    1≤N≤104,
    1≤M≤100,
    1≤K≤1000
    输入样例：
    6 3
    20001 20002
    20003 20004
    20005 20006
    20003 20001
    20005 20004
    20004 20006
    4 00001 20004 00002 20003
    5 98823 20002 20003 20006 10010
    3 12345 67890 23333
    输出样例：
    No
    Yes
    Yes
*/

#include <iostream>
#include <unordered_set>

using namespace std;

const int N = 10010;

int n, m;
int a[N], b[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i], &b[i]);
    while (m--) {
        int k;
        scanf("%d", &k);
        unordered_set<int> S;
        while (k--) {
            int x;
            scanf("%d", &x);
            S.insert(x);
        }
        bool success = true;
        for (int i = 0; i < n; i++)
            // 不相容物品对同时出现在物品清单中
            if (S.count(a[i]) && S.count(b[i])) {
                success = false;
                break;
            }

        if (success)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
