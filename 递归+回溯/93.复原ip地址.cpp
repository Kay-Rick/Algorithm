/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (46.79%)
 * Likes:    286
 * Dislikes: 0
 * Total Accepted:    48.2K
 * Total Submissions: 102.6K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 * 
 * 有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: "25525511135"
 * 输出: ["255.255.11.135", "255.255.111.35"]
 * 
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        // 不合法序列直接返回
        if (s.size() == 0 || s.size() > 12)
            return res;
        dfs(s, 4, "");
        return res;
    }

    /**
     * @brief 
     * @param s 还剩下的字符串
     * @param n 地址段个数
     * @param out 记录结果
     */
    void dfs(string s, int n, string out) {
        if (n == 0 && s.empty()) {
            out.erase(out.end() - 1);   // 去除调最后一个点
            res.push_back(out);
        }
        else {
           for (int i = 1; i <= 3; i++) {
               if (s.size() >= i && isValid(s.substr(0, i))) {
                   dfs(s.substr(i), n - 1, out + s.substr(0, i) + ".");
               }
           }
        }
    }

    /**
     * @brief 判断分割出的每一个ip地址段是否合法
     * @param s 
     * @return true 
     * @return false 
     */
    bool isValid (string s) {
        if (s.size() > 1 && s[0] == '0')
            return false;
        int a = stoi(s);
        return a <= 255 && a >= 0;
    }
};
// @lc code=end

