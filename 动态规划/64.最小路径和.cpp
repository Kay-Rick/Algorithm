/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (65.62%)
 * Likes:    495
 * Dislikes: 0
 * Total Accepted:    94.6K
 * Total Submissions: 143.7K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */

/**
 * @file 64.最小路径和.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-27 21:03:17
 * @brief 动态规划：dp[i][j]表示从(0, 0)走到(i, j)路径之和的最小值
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
    int minPathSum(vector<vector<int>> &grid) {
        int n = grid.size();
        if (!n)
            return 0;
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT32_MAX));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 处理边界：相当于初始化
                if (i == 0 && j == 0)
                    dp[i][j] = grid[0][0];
                else {
                    if (i != 0)
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
                    if (j != 0)
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};
// @lc code=end
