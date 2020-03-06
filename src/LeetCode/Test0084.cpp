/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Date: 2020-03-06 15:48:02
 * @Last Modified by: Rick
 * @Last Modified time: 2020-03-06 17:34:17
 * @Description: 维护一个序列递增的栈
 */

/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (37.79%)
 * Likes:    460
 * Dislikes: 0
 * Total Accepted:    30.9K
 * Total Submissions: 78.9K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 
 * 
 * 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
 * 
 * 
 * 
 * 
 * 
 * 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [2,1,5,6,2,3]
 * 输出: 10
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        s.push(-1);
        int maxarea = 0;
        // 对每一个元素进行处理
        for (int i = 0; i < heights.size(); i++)
        {
            // 当当前元素比栈顶元素小的时候，每次出栈都进行面积计算
            while (s.top() != -1 && heights[s.top()] >= heights[i])
            {
                int temp = s.top();
                s.pop();
                maxarea = max(maxarea, heights[temp] * (i - s.top() - 1));
            }
            s.push(i);
        }
        // 处理尾部元素和最小元素
        while (s.top() != -1)
        {
            int temp = s.top();
            int size = heights.size();
            s.pop();
            maxarea = max(maxarea, heights[temp] * (size - s.top() - 1));
        }
        return maxarea;
    }
};
// @lc code=end
