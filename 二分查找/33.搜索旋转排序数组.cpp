/*
 * @Author: Kay_Rick@outlook.com
 * @Date: 2020-05-24 10:01:47
 * @LastEditors: Kay_Rick@outlook.com
 * @LastEditTime: 2020-05-24 16:00:52
 * @Description: 二分查找
 */ 

/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (37.94%)
 * Likes:    736
 * Dislikes: 0
 * Total Accepted:    124K
 * Total Submissions: 326.7K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            // 当target在左半段的时候
            if (target >= nums[0]) {
                // mid在右半段时，将mid的索引值改成MAX
                if (nums[mid] < nums[0])
                    nums[mid] = INT32_MAX;
            }
            // 当target在右半段的时候
            else {
                // mid在左半段时，将mid的索引值改成MIN
                if (nums[mid] >= nums[0]) 
                    nums[mid] = INT32_MIN;
            }

            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};
// @lc code=end
/* 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int result = -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                result = mid;
            // mid落在左边升序序列中
            if (nums[left] <= nums[mid]) {
                // 判断target位于哪个序列里面进行规约left或者right
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else 
                    left = mid + 1;
            }
            // mid落在右边升序区间
            else {
                // 判断target位于哪个序列里面进行规约left或者right
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return result;
    }
};

 */