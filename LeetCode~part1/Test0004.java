/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Date: 2020-02-17 14:36:28
 * @Last Modified by: Rick
 * @Last Modified time: 2020-02-17 14:43:46
 * @Description: 归并求解法
 */

/*
 * @lc app=leetcode.cn id=4 lang=java
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (36.40%)
 * Likes:    2176
 * Dislikes: 0
 * Total Accepted:    143.2K
 * Total Submissions: 388.8K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */

// @lc code=start
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // 归并需要额外开辟新的内存空间
        int[] num = new int[nums1.length + nums2.length];
        double mid = 0;
        int i = 0, j = 0, k = 0;
        // 有序数组的归并操作 
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j]) {
                num[k++] = nums1[i++];
            } else {
                num[k++] = nums2[j++];
            }
        }

        // 以下的循环只能执行两个当中的一个
        while (i < nums1.length) {
            num[k++] = nums1[i++];
        }
        while (j < nums2.length) {
            num[k++] = nums2[j++];
        }

        if (num.length % 2 == 0) {
            mid = (double)((num[num.length / 2] + num[(num.length / 2) - 1]) / 2.0);
        } else {
            mid = (double)num[(num.length / 2)];
        }
        return mid;
    }
}
// @lc code=end
