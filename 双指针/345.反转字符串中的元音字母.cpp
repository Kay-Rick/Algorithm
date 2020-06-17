/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (49.89%)
 * Likes:    96
 * Dislikes: 0
 * Total Accepted:    37.6K
 * Total Submissions: 75K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 示例 1:
 * 
 * 输入: "hello"
 * 输出: "holle"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "leetcode"
 * 输出: "leotcede"
 * 
 * 说明:
 * 元音字母不包含字母"y"。
 * 
 */
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        string res = s;
        unordered_set<char> ss({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        int i = 0;
        int j = s.size() - 1;
        int count = 0;
        for (int k = 0; k < s.size(); k++)  {
            if (ss.count(s[k]))
                count++;
        }
        if (count <= 1)
            return res;
        while (i < j) {
            while(!ss.count(res[i]))
                i++;
            while(!ss.count(res[j]))
                j--;
            if (i < j) {
                char temp = res[i];
                res[i] = res[j];
                res[j] = temp;
                i++;
                j--;
            }
        }
        return res;
    }
};
// @lc code=end
