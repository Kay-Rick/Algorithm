/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (56.35%)
 * Likes:    457
 * Dislikes: 0
 * Total Accepted:    65.6K
 * Total Submissions: 116.1K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares = getSquares(n);
        queue<int> q;
        // 动态分配，初始化要带上()
        bool* st = new bool[n + 1]();
        q.push(n);
        st[n] = true;
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            level++;
            while(size-- > 0){
                int t = q.front();
                q.pop();
                for (int a : squares) {
                    int next = t - a;
                    if (next < 0)
                        break;
                    if (next == 0)
                        return level;
                    if (st[next])
                        continue;
                    st[next] = true;
                    q.push(next);
                }
            }
        }
        delete []st;
        return n;
    }
    /**
     * @brief Get the Squares object
     * @param n 
     * @return vector<int> 
     */
    vector<int> getSquares(int n) {
        vector<int> res;
        for (int i = 1; i * i <= n; i++)
            res.push_back(i * i);
        return res;
    }
};
// @lc code=end

