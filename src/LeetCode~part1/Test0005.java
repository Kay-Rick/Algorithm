/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Date: 2020-02-21 14:44:03
 * @Last Modified by: Rick
 * @Last Modified time: 2020-02-21 20:03:57
 * @Description: LeetCode第5题 最长回文串
 */

/*
 * @lc app=leetcode.cn id=5 lang=java
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.82%)
 * Likes:    1772
 * Dislikes: 0
 * Total Accepted:    186K
 * Total Submissions: 650.9K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start
class Solution {
    /**
     * 中心扩展算法 我们观察到回文中心的两侧互为镜像 因此，回文可以从它的中心展开，并且只有2n−1个这样的中心
     * 
     * @param s
     * @return 最长回文串
     */
    public String longestPalindrome(String s) {
        if (s == null || s.length() < 1) {
            return "";
        }
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            // 针对回文串是奇数的情况
            int len1 = expandAroundCenter(s, i, i);
            // 针对回文串是偶数的情况
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = Math.max(len1, len2);
            if (len > end - start) {
                // 屏蔽了len1和len2的情况，根据取整规则把start统一处理一下
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substring(start, end + 1);
    }

    /**
     * 
     * @param s
     * @param left
     * @param right
     * @return 每一次通过中心判定法得到的回文串长度
     */
    private int expandAroundCenter(String s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
            L--;
            R++;
        }
        // 当完成上面while循环的时候，L和R的位置分别处于正好匹配的下一个，所以是(R-1)-(L+1)+1
        return R - L - 1;
    }

}
// @lc code=end

