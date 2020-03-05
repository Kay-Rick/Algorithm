/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Date: 2020-03-05 21:41:53
 * @Last Modified by: Rick
 * @Last Modified time: 2020-03-05 21:47:46
 * @Description: 匹配括号：栈来实现，注意在取栈顶元素的时候前面判断一下栈是否为空
 */

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.23%)
 * Likes:    1418
 * Dislikes: 0
 * Total Accepted:    217K
 * Total Submissions: 529K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack <char> st;        
        if (s.length() == 0)
        {
            return true;
        }
        if (s.length() == 1)
        {
            return false;
        }
        bool flag = true;
        string::iterator it = s.begin();
        while (it != s.end() && flag)
        {
            if (*it == '(' || *it == '[' || *it == '{')
            {
                st.push(*it);
            }
            else if (*it == ')' && !st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else if(*it == ']' && !st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else if(*it == '}' && !st.empty() && st.top() == '{')
            {
                st.pop();
            }else
            {
                flag = false;
            }
            it++;
        }
        return flag && st.empty();
    }
};
// @lc code=end