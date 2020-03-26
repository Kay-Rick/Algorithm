/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Github: https://github.com/Kay-Rick
 * @Date: 2020-03-26 20:47:30
 * @LastEditors: Rick
 * @LastEditTime: 2020-03-26 20:56:08
 * @FilePath: /LeetCode/50.pow-x-n.cpp
 * @Description: 分治法求X的n次幂
 */
/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (33.49%)
 * Likes:    283
 * Dislikes: 0
 * Total Accepted:    61K
 * Total Submissions: 178.4K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * 
 * 示例 1:
 * 
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 * 
 * 
 * 示例 2:
 * 
 * 输入: 2.10000, 3
 * 输出: 9.26100
 * 
 * 
 * 示例 3:
 * 
 * 输入: 2.00000, -2
 * 输出: 0.25000
 * 解释: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 说明:
 * 
 * 
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
 * 
 * 
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
  public:
    double myPow(double x, int n) {
        long long N = n;
        // 对负数情况进行处理
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }
    double fastPow(double x, int n) {
        // 递归终止条件
        if (n == 0)
            return 1.0;
        // 当前层逻辑处理（分治）
        double half = fastPow(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
};
// @lc code=end
