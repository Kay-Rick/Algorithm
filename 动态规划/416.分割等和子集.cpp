/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (47.60%)
 * Likes:    306
 * Dislikes: 0
 * Total Accepted:    36.7K
 * Total Submissions: 76.5K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 注意:
 * 
 * 
 * 每个数组中的元素不会超过 100
 * 数组的大小不会超过 200
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1, 5, 11, 5]
 * 
 * 输出: true
 * 
 * 解释: 数组可以分割成 [1, 5, 5] 和 [11].
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1, 2, 3, 5]
 * 
 * 输出: false
 * 
 * 解释: 数组不能分割成两个元素和相等的子集.
 * 
 * 
 * 
 * 
 */

/**
 * @file 416.分割等和子集.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-26 19:37:52
 * @brief 背包问题变种：给⼀个可装载重量为 sum / 2 的背包和 N 个物品，每个物品的重量为nums[i] 。
 *          现在让你装物品，是否存在⼀种装法，能够恰好将背包装满？
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
    int sum;
    bool canPartition(vector<int>& nums) {
        for (int a : nums)
            sum += a;
        if (sum % 2)
            return false;
        sum /= 2;
        int n = nums.size();
        vector<bool> dp(sum + 1, false);
        // 边界
        dp[0] = true;
        // 枚举状态，计算各个状态
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};
// @lc code=end
/* 
class Solution {
  public:
    int sum;
    bool canPartition(vector<int> &nums) {
        for (int a : nums)
            sum += a;
        if (sum % 2)
            return false;
        sum /= 2;
        int n = nums.size();
        // dp[i][j]表示前i个物品当背包容量为j时能否恰好装满
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        // 边界
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        // 枚举状态，计算各个状态
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                // 背包容量不足，不能放入
                if (j < nums[i - 1])
                    dp[i][j] = dp[i - 1][j];
                // 装入或不装入背包
                else
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }

        return dp[n][sum];
    }
};
 */