/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (53.62%)
 * Likes:    768
 * Dislikes: 0
 * Total Accepted:    125.4K
 * Total Submissions: 233.2K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

/**
 * @file 17.电话号码的字母组合.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-28 15:51:28
 * @brief 
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */

/**
 * @file 17.电话号码的字母组合.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-28 15:52:50
 * @brief dfs
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> res;
    // 使用字符串数组
    string strs[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return res;
        dfs (digits, 0, "");
        return res;
    }

    /**
     * @brief DFS搜索
     * @param digits 字符串
     * @param u 当前层数(加入了几个节点)
     * @param path 记录结果
     */
    void dfs(string& digits, int u, string path) {
        if (u == digits.size())
            res.push_back(path);
        else {
            for (auto c : strs[digits[u] - '0']) {
                dfs(digits, u + 1, path + c);
            }
        }
    }
};
// @lc code=end

