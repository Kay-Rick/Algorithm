/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (51.32%)
 * Likes:    2108
 * Dislikes: 0
 * Total Accepted:    264.1K
 * Total Submissions: 512.9K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */

/**
 * @file 53.最大子序和.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-26 20:36:14
 * @brief 动态规划
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
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> dp(n);
        dp[0] = nums[0];
        // dp[i]存放以nums[i]结尾的连续序列的最大和
        for (int i = 1; i < n; i++)
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        int pos = 0;
        for (int i = 1; i < n; i++) {
            if (dp[i] > dp[pos])
                pos = i;
        }
        return dp[pos];
    }
};
// @lc code=end

