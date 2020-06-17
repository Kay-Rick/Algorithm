/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 *
 * https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * algorithms
 * Medium (44.12%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    7.4K
 * Total Submissions: 16.5K
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 * 
 * 给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * s = "abpcplea", d = ["ale","apple","monkey","plea"]
 * 
 * 输出: 
 * "apple"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * s = "abpcplea", d = ["a","b","c"]
 * 
 * 输出: 
 * "a"
 * 
 * 
 * 说明:
 * 
 * 
 * 所有输入的字符串只包含小写字母。
 * 字典的大小不会超过 1000。
 * 所有输入的字符串长度不会超过 1000。
 * 
 * 
 */

/**
 * @file 524.通过删除字母匹配到字典里最长单词.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-17 20:06:63
 * @brief 双指针法枚举 + STL双关键字排序
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        vector<string> res;
        for (auto str : d) {
            int i = 0;
            int j = 0;
            while(i < s.size() && j < str.size()) {
                if (s[i] != str[j])
                    i++;
                else {
                    i++;
                    j++;
                }
            }
            if (j >= str.size())
                res.push_back(str);
        }
        if (res.size() == 0)
            return "";
        // 先按照字符串长度进行排序，若长度相等，按字典序排序：a < b
        sort(res.begin(), res.end(), [](string& a, string& b) {
            if (a.size() != b.size())
                return a.size() > b.size();
            else {
                return a < b;
            }
        });
        return res[0];
    }
};
// @lc code=end

