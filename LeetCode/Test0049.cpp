/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Github: https://github.com/Kay-Rick
 * @Date: 2020-03-12 23:25:14
 * @LastEditors: Rick
 * @LastEditTime: 2020-03-12 23:26:17
 * @Description: map映射 Hash
 */
/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 * 
 * algorithms
 * Medium (59.66%)
 * Likes:    282
 * Dislikes: 0
 * Total Accepted:    54.9K
 * Total Submissions: 90K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int sub = 0;                    // 记录结果集res的下标
        string tmp;
        unordered_map <string,int> work;
        for (auto str : strs) {
            tmp = str;                  // 排序后将tmp作为key进行标识
            sort(tmp.begin(), tmp.end());
            // 如果能找到同一个组里面,就在该异位词标识的(key)分组work[tmp]下加
            if (work.count(tmp)) {
                res[work[tmp]].push_back(str);
            }else
            {
                vector<string> vec (1, str);    // 初始化一个长度为1的数组为str
                res.push_back(vec);
                work[tmp] = sub++;              // 在该分组下面在res结果集的下标,方便于我们后续能够找到合适的分组
            }
        }
        return res;
    }
};
// @lc code=end
