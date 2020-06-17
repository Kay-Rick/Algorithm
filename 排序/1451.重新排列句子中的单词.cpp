/*
 * @lc app=leetcode.cn id=1451 lang=cpp
 *
 * [1451] 重新排列句子中的单词
 *
 * https://leetcode-cn.com/problems/rearrange-words-in-a-sentence/description/
 *
 * algorithms
 * Medium (46.88%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    4.5K
 * Total Submissions: 9.7K
 * Testcase Example:  '"Leetcode is cool"'
 *
 * 「句子」是一个用空格分隔单词的字符串。给你一个满足下述格式的句子 text :
 * 
 * 
 * 句子的首字母大写
 * text 中的每个单词都用单个空格分隔。
 * 
 * 
 * 请你重新排列 text 中的单词，使所有单词按其长度的升序排列。如果两个单词的长度相同，则保留其在原句子中的相对顺序。
 * 
 * 请同样按上述格式返回新的句子。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：text = "Leetcode is cool"
 * 输出："Is cool leetcode"
 * 解释：句子中共有 3 个单词，长度为 8 的 "Leetcode" ，长度为 2 的 "is" 以及长度为 4 的 "cool" 。
 * 输出需要按单词的长度升序排列，新句子中的第一个单词首字母需要大写。
 * 
 * 
 * 示例 2：
 * 
 * 输入：text = "Keep calm and code on"
 * 输出："On and keep calm code"
 * 解释：输出的排序情况如下：
 * "On" 2 个字母。
 * "and" 3 个字母。
 * "keep" 4 个字母，因为存在长度相同的其他单词，所以它们之间需要保留在原句子中的相对顺序。
 * "calm" 4 个字母。
 * "code" 4 个字母。
 * 
 * 
 * 示例 3：
 * 
 * 输入：text = "To be or not to be"
 * 输出："To be or to be not"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * text 以大写字母开头，然后包含若干小写字母以及单词间的单个空格。
 * 1 <= text.length <= 10^5
 * 
 * 
 */

/**
 * @file 1451.重新排列句子中的单词.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-12 22:24:26
 * @brief 双关键字排序(使用稳定排序stable_sort并匿名实现排序函数)
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    string arrangeWords(string text) {
        stringstream ssin(text);
        string str;
        vector<string> res;
        while (ssin >> str)
            res.push_back(str);
        
        res[0][0] = tolower(res[0][0]);
        // 匿名实现排序函数
        stable_sort(res.begin(), res.end(), [](string a, string b) {
            return a.size() < b.size();
        });
        res[0][0] = toupper(res[0][0]);

        string result;
        for (string word : res) 
            result += word + ' ';
        result.pop_back();
        return result;
    }
};
// @lc code=end

