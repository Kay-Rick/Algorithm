/*
 * @lc app=leetcode.cn id=1458 lang=cpp
 *
 * [1458] 两个子序列的最大点积
 *
 * https://leetcode-cn.com/problems/max-dot-product-of-two-subsequences/description/
 *
 * algorithms
 * Hard (40.29%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    2.4K
 * Total Submissions: 6K
 * Testcase Example:  '[2,1,-2,5]\r\n[3,0,-6]\r'
 *
 * 给你两个数组 nums1 和 nums2 。
 * 
 * 请你返回 nums1 和 nums2 中两个长度相同的 非空 子序列的最大点积。
 * 
 * 数组的非空子序列是通过删除原数组中某些元素（可能一个也不删除）后剩余数字组成的序列，但不能改变数字间相对顺序。比方说，[2,3,5] 是
 * [1,2,3,4,5] 的一个子序列而 [1,5,3] 不是。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [2,1,-2,5], nums2 = [3,0,-6]
 * 输出：18
 * 解释：从 nums1 中得到子序列 [2,-2] ，从 nums2 中得到子序列 [3,-6] 。
 * 它们的点积为 (2*3 + (-2)*(-6)) = 18 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [3,-2], nums2 = [2,-6,7]
 * 输出：21
 * 解释：从 nums1 中得到子序列 [3] ，从 nums2 中得到子序列 [7] 。
 * 它们的点积为 (3*7) = 21 。
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums1 = [-1,-1], nums2 = [1,1]
 * 输出：-1
 * 解释：从 nums1 中得到子序列 [-1] ，从 nums2 中得到子序列 [1] 。
 * 它们的点积为 -1 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 500
 * -1000 <= nums1[i], nums2[i] <= 100
 * 
 * 
 * 
 * 
 * 点积：
 * 
 * 
 * 定义 a = [a1, a2,…, an] 和 b = [b1, b2,…, bn] 的点积为：
 * 
 * 
 * 
 * 这里的 Σ 指示总和符号。
 * 
 * 
 */

/**
 * @file 1458.两个子序列的最大点积.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-12 20:17:50
 * @brief DP问题(参考最长公共子序列问题)
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
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        // DP数组
        vector<vector<int>> f(n + 1, vector<int>(m + 1, -0x3f3f3f));
        for (int i = 0; i <= n; i++)
            f[i][0] = 0;
        for (int i = 0; i <= m; i++)
            f[0][i] = 0;
        
        int res = INT32_MIN;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                int t = f[i - 1][j - 1] + nums1[i - 1] * nums2[j - 1];
                res = max(res, t);
                f[i][j] = max(f[i][j], t);
            }
        }
        return res;
    }
};
// @lc code=end

