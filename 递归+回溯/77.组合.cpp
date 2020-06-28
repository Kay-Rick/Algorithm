/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (73.74%)
 * Likes:    293
 * Dislikes: 0
 * Total Accepted:    57.3K
 * Total Submissions: 77.5K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */

/**
 * @file 77.组合.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-28 23:13:06
 * @brief 回溯
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0 || n < k)
            return res;
        dfs(n, 1, k, path);
        return res;

    }
    
    void dfs (int n, int begin, int level, vector<int>& path) {
        if (path.size() == level) {
            res.push_back(path);
            return;
        }
        // 剪枝操作，删掉不需要进行的循环操作
        for (int i = begin; i <= n - (level - path.size()) + 1; i++) {
            path.push_back(i);
            dfs(n, i + 1, level, path);
            path.pop_back();
        }
    }
};
// @lc code=end
/* 
class Solution {
  public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0 || n < k)
            return res;
        dfs(n, 1, k, path);
        return res;
    }

    void dfs(int n, int begin, int level, vector<int> &path) {
        if (path.size() == level) {
            res.push_back(path);
            return;
        }
        for (int i = begin; i <= n; i++) {
            path.push_back(i);
            dfs(n, i + 1, level, path);
            path.pop_back();
        }
    }
};
 */