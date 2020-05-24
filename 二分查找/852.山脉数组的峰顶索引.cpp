/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 *
 * https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/description/
 *
 * algorithms
 * Easy (70.54%)
 * Likes:    78
 * Dislikes: 0
 * Total Accepted:    24.2K
 * Total Submissions: 34.3K
 * Testcase Example:  '[0,1,0]'
 *
 * 我们把符合下列属性的数组 A 称作山脉：
 * 
 * 
 * A.length >= 3
 * 存在 0 < i < A.length - 1 使得A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... >
 * A[A.length - 1]
 * 
 * 
 * 给定一个确定为山脉的数组，返回任何满足 A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... >
 * A[A.length - 1] 的 i 的值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[0,1,0]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 输入：[0,2,1,0]
 * 输出：1
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= A.length <= 10000
 * 0 <= A[i] <= 10^6
 * A 是如上定义的山脉
 * 
 * 
 * 
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0, right = A.size() - 1;
        while (left < right) {
            int mid  = left + (right - left) / 2;
            // 峰顶在mid之后
            if (A[mid] < A[mid + 1]) 
                left = mid + 1;
            // 峰顶在mid之前
            else if (A[mid - 1] > A[mid])
                right = mid;
            // 峰顶在mid这个位置
            else
                return mid;
        }
        return -1;
    }
};
// @lc code=end

