/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Github: https://github.com/Kay-Rick
 * @Date: 2020-03-26 17:42:53
 * @LastEditors: Rick
 * @LastEditTime: 2020-03-26 19:28:18
 * @FilePath: /LeetCode/Users/rick/Desktop/GitHub_Reposity/Algorithm/src/LeetCode/Test0022.cpp
 * @Description: Description
 */
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (72.59%)
 * Likes:    816
 * Dislikes: 0
 * Total Accepted:    89.2K
 * Total Submissions: 121.1K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        _generate(0, 0, n, "");
        return result;
    }
    /**Test0141.java
     * @brief 产生结果的递归函数
     * @param left 放入左括号的个数
     * @param right 放入右括号的个数
     * @param n 层数
     * @param s 正在处理的结果集
     */
    void _generate(int left, int right, int n, string s) {
        // 递归终止条件
        if (left == n && right == n) {
            result.push_back(s);
            return;
        }
        // 关注本层递归逻辑处理，这里对结果合法性的判断
        if (left < n)       /* 只要左括号没有超标那么就可以放左括号 */
            _generate(left + 1, right, n, s + "(");
        if (left > right)   /* 右括号个数没有超过左括号个数就可以放右括号 */
            _generate(left, right + 1, n, s + ")");
    }
private:
    vector<string> result;
};
// @lc code=end