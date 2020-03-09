/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Github: https://github.com/Kay-Rick
 * @Date: 2020-03-09 17:42:45
 * @LastEditors: Rick
 * @LastEditTime: 2020-03-09 22:16:00
 * @FilePath: /LeetCode/Test0242.cpp
 * @Description: 哈希表
 */
/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (57.36%)
 * Likes:    162
 * Dislikes: 0
 * Total Accepted:    79.6K
 * Total Submissions: 135.5K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 示例 1:
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 说明:
 * 你可以假设字符串只包含小写字母。
 * 
 * 进阶:
 * 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }
        int a1[255] = {0};
        int a2[255] = {0};
        for (int i = 0; i < s.length(); i++){
            char c1 = s.at(i);
            char c2 = t.at(i);
            a1[c1]++;
            a2[c2]++;
        }
        for (int i = 0; i < 255; i++) {
            if (a1[i] != a2[i]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

