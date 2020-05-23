/*
 * @Author: Kay_Rick@outlook.com
 * @Date: 2020-05-24 00:33:11
 * @LastEditors: Kay_Rick@outlook.com
 * @LastEditTime: 2020-05-24 00:39:17
 * @Description: 二分查找模板题
 */ 

/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (43.34%)
 * Likes:    121
 * Dislikes: 0
 * Total Accepted:    32.3K
 * Total Submissions: 74.4K
 * Testcase Example:  '16'
 *
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 * 
 * 说明：不要使用任何内置的库函数，如  sqrt。
 * 
 * 示例 1：
 * 
 * 输入：16
 * 输出：True
 * 
 * 示例 2：
 * 
 * 输入：14
 * 输出：False
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // 这里要注意处理溢出的情况
            if ((long long)mid * mid == num) {
                return true;
            } else if ((long long)mid * mid < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end

