/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (58.91%)
 * Likes:    325
 * Dislikes: 0
 * Total Accepted:    66.8K
 * Total Submissions: 112.8K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */

/**
 * @file 47.全排列-ii.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-28 21:34:55
 * @brief 保证相同数字的相对顺序不变，就不会出现重复
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<bool> st;
    vector<int> path;
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        if (nums.size() == 0) 
            return res;
        sort(nums.begin(), nums.end());
        st.resize(nums.size(), false);
        dfs (nums, path);
        return res;
    }
    /**
     * @brief 
     * @param nums 
     * @param path 
     */
    void dfs(vector<int>& nums, vector<int>& path) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!st[i]) {
                // 判断前面相同数字是否按顺序，如果没有按顺序，直接跳过
                if (i > 0 && nums[i - 1] == nums[i] && !st[i - 1])
                    continue;
                st[i] = true;
                path.push_back(nums[i]);
                dfs(nums, path);
                st[i] = false;
                path.pop_back();
            }
        }
    }
};
// @lc code=end

