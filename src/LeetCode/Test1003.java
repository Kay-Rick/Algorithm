import java.util.HashSet;
import java.util.Set;
/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Date: 2020-02-16 14:51:05
 * @Last Modified by: Rick
 * @Last Modified time: 2020-02-17 22:20:46
 * @Description: LeetCode第三题 
 *  利用Set进行检查是否有重复，双指针进行滑动窗口的检验
 */

/*
 * @lc app=leetcode.cn id=3 lang=java
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (32.19%)
 * Likes:    3168
 * Dislikes: 0
 * Total Accepted:    347.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

// @lc code=start
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int max_len = 0;
        int i = 0, j = 0;
        int n = s.length();
        Set<Character> set = new HashSet<>();
        while (i < n && j < n) {
            if (!set.contains(s.charAt(j))) {
                set.add(s.charAt(j++));
                max_len = Math.max(max_len, j - i);
            } else {
                set.remove(s.charAt(i++));
            }
        }
        return max_len;
    }
}
// @lc code=end
