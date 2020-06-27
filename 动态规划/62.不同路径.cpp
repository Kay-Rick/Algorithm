/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (60.56%)
 * Likes:    577
 * Dislikes: 0
 * Total Accepted:    113.4K
 * Total Submissions: 186.8K
 * Testcase Example:  '3\n2'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 问总共有多少条不同的路径？
 * 
 * 
 * 
 * 例如，上图是一个7 x 3 的网格。有多少可能的路径？
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释:
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 * 
 * 
 * 示例 2:
 * 
 * 输入: m = 7, n = 3
 * 输出: 28
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= m, n <= 100
 * 题目数据保证答案小于等于 2 * 10 ^ 9
 * 
 * 
 */

/**
 * @file 62.不同路径.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-27 20:44:34
 * @brief 动态规划：dp[i][j]表示从(0, 0)走到(i, j)的方案数
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
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else {
                    if (i != 0)
                        dp[i][j] += dp[i - 1][j];
                    if (j != 0)
                        dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};

// @lc code=end
/* 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m));
        // 边界初始化
        for (int i = 0; i < n; i++) 
            dp[i][0] = 1;
        for (int i = 0; i < m; i++) 
            dp[0][i] = 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) 
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
        return dp[n - 1][m - 1];
    }
};
 */