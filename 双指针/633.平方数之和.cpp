/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 *
 * https://leetcode-cn.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Easy (33.25%)
 * Likes:    117
 * Dislikes: 0
 * Total Accepted:    22.7K
 * Total Submissions: 67.9K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c。
 * 
 * 示例1:
 * 
 * 
 * 输入: 5
 * 输出: True
 * 解释: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * 
 * 
 * 示例2:
 * 
 * 
 * 输入: 3
 * 输出: False
 * 
 * 
 */

/**
 * @file 633.平方数之和.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-17 17:06:56
 * @brief 双指针算法
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c < 0)
            return false;
        long long upper = sqrt(c);
        long long lower = 0;
        while (lower <= upper) {
            if (upper * upper + lower * lower == c)
                return true;
            else if (upper * upper + lower * lower < c)
                lower++;
            else 
                upper--;
        }
        return false;
    }
};
// @lc code=end

