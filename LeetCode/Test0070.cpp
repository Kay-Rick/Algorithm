/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Github: https://github.com/Kay-Rick
 * @Date: 2020-03-26 14:01:18
 * @LastEditors: Rick
 * @LastEditTime: 2020-03-26 19:47:46
 * @FilePath: /LeetCode/70.爬楼梯.cpp
 * @Description: 递归问题
 */
/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode-cn.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (47.38%)
 * Likes:    892
 * Dislikes: 0
 * Total Accepted:    158.2K
 * Total Submissions: 328.8K
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 注意：给定 n 是一个正整数。
 * 
 * 示例 1：
 * 
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶
 * 2.  2 阶
 * 
 * 示例 2：
 * 
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 * 
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        vector<int> steps(n, 0);
        steps[0] = 1;
        steps[1] = 2;
        for (int i = 2; i < steps.size(); i++) {
            steps[i] = steps[i - 1] + steps[i - 2];
        }
        return steps[n - 1];
    }
};
// @lc code=end
