/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 *
 * https://leetcode-cn.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (54.77%)
 * Likes:    233
 * Dislikes: 0
 * Total Accepted:    21.6K
 * Total Submissions: 39K
 * Testcase Example:  '"bbbab"'
 *
 * 给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。
 * 
 * 
 * 
 * 示例 1:
 * 输入:
 * 
 * "bbbab"
 * 
 * 
 * 输出:
 * 
 * 4
 * 
 * 
 * 一个可能的最长回文子序列为 "bbbb"。
 * 
 * 示例 2:
 * 输入:
 * 
 * "cbbd"
 * 
 * 
 * 输出:
 * 
 * 2
 * 
 * 
 * 一个可能的最长回文子序列为 "bb"。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 只包含小写英文字母
 * 
 * 
 */

/**
 * @file 516.最长回文子序列.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-26 22:34:45
 * @brief 状态f[i][j] 表示 s 的第 i 个字符到第 j 个字符组成的子串中，最长的回文序列长度是多少。
 *        转移方程如果 s 的第 i 个字符和第 j 个字符相同的话f[i][j] = f[i + 1][j - 1] + 2
 *        如果 s 的第 i 个字符和第 j 个字符不同的话f[i][j] = max(f[i + 1][j], f[i][j - 1])
 *        然后注意遍历顺序，i 从最后一个字符开始往前遍历，j 从 i + 1 开始往后遍历，这样可以保证每个子问题都已经算好了。
 *        初始化f[i][i] = 1 单个字符的最长回文序列是 1
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        // 遍历从大到小还是从小到大：根据我们画出矩形图，一层一层遍历来看
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][n - 1];
    }
};
// @lc code=end

