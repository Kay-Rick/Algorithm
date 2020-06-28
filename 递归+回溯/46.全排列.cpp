/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (76.13%)
 * Likes:    757
 * Dislikes: 0
 * Total Accepted:    144.8K
 * Total Submissions: 189.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

/**
 * @file 46.全排列.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-28 21:05:08
 * @brief 全排列：暴力搜索 + 回溯
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
    vector<bool> st;
    vector<vector<int>> permute(vector<int> &nums) {
        if (nums.size() == 0)
            return res;
        vector<int> path;
        st.resize(nums.size(), false);
        dfs(nums, path);
        return res;
    }

    void dfs (vector<int>& v, vector<int>& path) {
        if (path.size() == v.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < v.size(); i++) {
            if (!st[i]) {
                path.push_back(v[i]);
                st[i] = true;
                dfs(v, path);
                st[i] = false;
                path.pop_back();
            }
        }
    }
};
// @lc code=end

