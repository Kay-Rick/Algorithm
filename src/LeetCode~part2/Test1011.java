/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Github: https://github.com/Kay-Rick
 * @Date: 2020-02-26 16:40:57
 * @LastEditors: Rick
 * @LastEditTime: 2020-02-26 17:00:09
 * @FilePath: /LeetCode/Test1011.java
 * @Description: 盛最多水的容器，双指针
 */
/*
 * @lc app=leetcode.cn id=11 lang=java
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode-cn.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (59.90%)
 * Likes:    1147
 * Dislikes: 0
 * Total Accepted:    144.1K
 * Total Submissions: 234.4K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为
 * (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 * 
 * 
 * 
 * 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [1,8,6,2,5,4,8,3,7]
 * 输出: 49
 * 
 */

// @lc code=start
class Solution {
    public int maxArea(int[] height) {
        int Area = 0;
        int i = 0, j = height.length - 1;
        while (i < j) {
            int max_height = Math.min(height[i], height[j]);
            Area = Math.max(Area, (j - i) * max_height);
            if (max_height == height[i]) {
                i++;
            } else {
                j--;
            }
        }
        return Area;
    }
}
// @lc code=end

