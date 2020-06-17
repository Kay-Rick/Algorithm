/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 *
 * https://leetcode-cn.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (39.33%)
 * Likes:    215
 * Dislikes: 0
 * Total Accepted:    43.5K
 * Total Submissions: 110.5K
 * Testcase Example:  '"aba"'
 *
 * 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "aba"
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "abca"
 * 输出: True
 * 解释: 你可以删除c字符。
 * 
 * 
 * 注意:
 * 
 * 
 * 字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
 * 
 * 
 */

/**
 * @file 680.验证回文字符串-ⅱ.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-17 19:06:01
 * @brief 在判断是否为回文字符串时，我们不需要判断整个字符串，因为左指针左边和右指针右边的字符之前已经判断过具有对称性质
 *          所以只需要判断中间的子字符串即可。
 *          在试着删除字符时，我们既可以删除左指针指向的字符，也可以删除右指针指向的字符。
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j])
                // 两种情况求“或”
                return helper(s, i + 1, j) || helper(s, i, j - 1);
        }
        return true;
    }
    /**
     * @brief 判断字符串从i ~ j之间是否是回文串
     * @param s 
     * @param i 
     * @param j 
     * @return true 
     * @return false 
     */
    bool helper(string& s, int i, int j) {
        bool res = true;
        while(i < j) {
            if (s[i] != s[j])
                res = false;
            i++;
            j--;
        }
        return res;
    }
};
// @lc code=end

/* 
class Solution {
  public:
    bool validPalindrome(string s) {
        int skip = 0;
        if (s.size() <= 1)
            return true;
        int i = 0;
        int j = s.size() - 1;
        bool res1 = true;
        bool res2 = true;
        // 删除左边的情形
        while (i <= j) {
            if (s[i] != s[j]) {
                if (skip < 1 && s[i + 1] == s[j]) {
                    i++;
                    skip++;
                    continue;
                } else
                    res1 = false;
            }
            i++;
            j--;
        }
        // 删除右边的情形
        i = 0;
        j = s.size() - 1;
        skip = 0;
        while (i <= j) {
            if (s[i] != s[j]) {
                if (skip < 1 && s[i] == s[j - 1]) {
                    j--;
                    skip++;
                    continue;
                } else
                    res2 = false;
            }
            i++;
            j--;
        }
        return res1 || res2;
    }
};
 */