/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 *
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (53.84%)
 * Likes:    308
 * Dislikes: 0
 * Total Accepted:    99.4K
 * Total Submissions: 183.4K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
 * 
 * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 * 
 * 说明:
 * 
 * 
 * 返回的下标值（index1 和 index2）不是从零开始的。
 * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 * 
 * 
 * 示例:
 * 
 * 输入: numbers = [2, 7, 11, 15], target = 9
 * 输出: [1,2]
 * 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 * 
 */

/**
 * @file 167.两数之和-ii-输入有序数组.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-17 16:06:61
 * @brief 双指针法
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                res.push_back(i + 1);
                res.push_back(j + 1);
                break;
            }
            if (numbers[i] + numbers[j] < target)
                i++;
            else
                j--;
        }
        return res;
    }
};
// @lc code=end
/* 
class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n = numbers.size() - 1;
        vector<int> res;
        unordered_map<int, int> hash;
        for (int i = 0; i < numbers.size(); i++) {
            hash[numbers[i]] = i + 1;
        }
        for (int i = 0; i < numbers.size(); i++) {
            int x = target - numbers[i];
            if (hash.count(x)) {
                res.push_back(i + 1);
                res.push_back(hash[x]);
                break;
            }
        }
        return res;
    }
}; 
*/