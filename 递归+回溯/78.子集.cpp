/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (77.36%)
 * Likes:    619
 * Dislikes: 0
 * Total Accepted:    100.2K
 * Total Submissions: 129.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

/**
 * @file 78.子集.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-28 23:18:06
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
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) 
            return res;
        dfs(nums, 0, path);
        return res;
    }

    void dfs(vector<int>& nums, int level, vector<int> path) {
        if (nums.size() == level) {
            res.push_back(path);
            return;
        }
        // 相当于选择列表：两种情况：选或者不选
        dfs(nums, level + 1, path);
        path.push_back(nums[level]);
        dfs(nums, level + 1, path);
        path.pop_back();
    }
};
// @lc code=end
