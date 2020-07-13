/**
 * @file 期终成绩.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-13 22:55:23
 * @brief 结构体 + 哈希表 + 排序
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/*
    对于在中国大学 MOOC 学习“数据结构”课程的学生，想要获得一张合格证书，必须首先获得不少于 200 分的在线编程作业分，然后总评获得不少于 60 分（满分 100）。

    总评成绩的计算公式为 G=(Gmid−term×40%+Gfinal×60%)，如果 Gmid−term>Gfinal；否则总评 G 就是 Gfinal。

    这里 Gmid−term 和 Gfinal 分别为学生的期中和期末成绩。

    现在的问题是，每次考试都产生一张独立的成绩单。

    本题就请你编写程序，把不同的成绩单合为一张。

    输入格式
    输入在第一行给出 3 个整数，分别是 P（做了在线编程作业的学生数）、M（参加了期中考试的学生数）、N（参加了期末考试的学生数）。

    接下来有三块输入。

    第一块包含 P 个在线编程成绩 Gp；

    第二块包含 M 个期中考试成绩 Gmid−term；

    第三块包含 N 个期末考试成绩 Gfinal。

    每个成绩占一行，格式为：学生学号 分数。

    其中 学生学号 为不超过 20 个字符的英文字母和数字；分数 是非负整数（编程总分最高为 900 分，期中和期末的最高分为 100 分）。

    输出格式
    打印出获得合格证书的学生名单。

    每个学生占一行，格式为：

    学生学号 Gp Gmid−term Gfinal G
    如果有的成绩不存在（例如某人没参加期中考试），则在相应的位置输出“−1”。

    输出顺序为按照总评分数（四舍五入精确到整数）递减。

    若有并列，则按学号递增。

    题目保证学号没有重复，且至少存在 1 个合格的学生。

    数据范围
    1≤P,M,N≤10000
    输入样例：
    6 6 7
    01234 880
    a1903 199
    ydjh2 200
    wehu8 300
    dx86w 220
    missing 400
    ydhfu77 99
    wehu8 55
    ydjh2 98
    dx86w 88
    a1903 86
    01234 39
    ydhfu77 88
    a1903 66
    01234 58
    wehu8 84
    ydjh2 82
    missing 99
    dx86w 81
    输出样例：
    missing 400 -1 99 99
    ydjh2 200 98 82 88
    dx86w 220 88 81 84
    wehu8 300 55 84 84
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Student {
    string id;
    int p;
    int m;
    int f;
    int s;
    // 初始化
    Student() : p(-1), m(-1), f(-1), s(0) {}

    void calc() {
        if (f < m)
            s = round(m * 0.4 + f * 0.6);
        else
            s = f;
    }
    // 排序重载小于号
    bool operator<(const Student &t) const {
        // 总成绩越大的排在前面
        if (s != t.s)
            return s > t.s;
        // 总成绩相等，字典序小的放在前面
        return id < t.id;
    }
};

unordered_map<string, Student> mp;
vector<Student> students;

int main() {
    int p, m, n;
    cin >> p >> m >> n;
    string id;
    int s;

    for (int i = 0; i < p; i++) {
        cin >> id >> s;
        mp[id].id = id;
        mp[id].p = s;
    }

    for (int i = 0; i < m; i++) {
        cin >> id >> s;
        mp[id].id = id;
        mp[id].m = s;
    }

    for (int i = 0; i < n; i++) {
        cin >> id >> s;
        mp[id].id = id;
        mp[id].f = s;
    }

    for (auto item : mp) {
        auto stu = item.second;
        // 计算期末成绩
        stu.calc();
        // 成绩合格加入到清单中
        if (stu.p >= 200 && stu.s >= 60)
            students.push_back(stu);
    }

    sort(students.begin(), students.end());

    for (auto stu : students)
        cout << stu.id << ' ' << stu.p << ' ' << stu.m << ' ' << stu.f << ' ' << stu.s << endl;

    return 0;
}