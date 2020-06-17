/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (47.70%)
 * Likes:    533
 * Dislikes: 0
 * Total Accepted:    161.3K
 * Total Submissions: 336.4K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m + n - 1; i >= m; i--)
            nums1[i] = nums2[i - m];
        sort(nums1.begin(), nums1.end());
    }
};
// @lc code=end
/* 

class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> res;
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j])
                res.push_back(nums1[i++]);
            else
                res.push_back(nums2[j++]);
        }
        while (i < m)
            res.push_back(nums1[i++]);
        while (j < n)
            res.push_back(nums2[j++]);
        for (int k = 0; k < n + m; k++) {
            nums1[k] = res[k];
        }
    }
};

 */