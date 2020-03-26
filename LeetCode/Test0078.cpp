/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (75.67%)
 * Likes:    500
 * Dislikes: 0
 * Total Accepted:    72.7K
 * Total Submissions: 94.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> result;     // 递归存结果集一定要放在public里面
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> temp;
        helper(nums, temp, 0);
        return result;
    }
private:
    /**
     * @brief 辅助递归函数
     * @param nums 
     * @param list 
     * @param index 
     */
    void helper(vector<int>& nums, vector<int> list, int index) {
        // 递归终止条件
        if (nums.size() == index) {
            result.push_back(list);
            return;
        }
        helper(nums, list, index + 1);  // 不选择该下标的元素
        list.push_back(nums[index]);    // 选择该下标的元素
        helper(nums, list, index + 1);
        list.pop_back();
    }
};
// @lc code=end
/* 
class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result = {{}};
        for (int num : nums) {
            int n = result.size();
            for (int i = 0; i < n; i++) {
                result.push_back(result[i]);  // 原来集合的子集全是下一个集合的元素
                result.back().push_back(num); // 原来子集里面加上新添加的元素
            }
        }
        return result;
    }
};
 */
/* 
class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }

  private:
    void subsets(vector<int> &nums, int i, vector<int> &sub, vector<vector<int>> &subs) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }
};
 */