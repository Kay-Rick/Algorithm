/*
 * @lc app=leetcode.cn id=1452 lang=cpp
 *
 * [1452] 收藏清单
 *
 * https://leetcode-cn.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/description/
 *
 * algorithms
 * Medium (46.09%)
 * Likes:    8
 * Dislikes: 0
 * Total Accepted:    3.3K
 * Total Submissions: 7.2K
 * Testcase Example:  '[["leetcode","google","facebook"],["google","microsoft"],["google","facebook"],["google"],["amazon"]]\r'
 *
 * 给你一个数组 favoriteCompanies ，其中 favoriteCompanies[i] 是第 i 名用户收藏的公司清单（下标从 0
 * 开始）。
 * 
 * 请找出不是其他任何人收藏的公司清单的子集的收藏清单，并返回该清单下标。下标需要按升序排列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：favoriteCompanies =
 * [["leetcode","google","facebook"],["google","microsoft"],["google","facebook"],["google"],["amazon"]]
 * 输出：[0,1,4] 
 * 解释：
 * favoriteCompanies[2]=["google","facebook"] 是
 * favoriteCompanies[0]=["leetcode","google","facebook"] 的子集。
 * favoriteCompanies[3]=["google"] 是
 * favoriteCompanies[0]=["leetcode","google","facebook"] 和
 * favoriteCompanies[1]=["google","microsoft"] 的子集。
 * 其余的收藏清单均不是其他任何人收藏的公司清单的子集，因此，答案为 [0,1,4] 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：favoriteCompanies =
 * [["leetcode","google","facebook"],["leetcode","amazon"],["facebook","google"]]
 * 输出：[0,1] 
 * 解释：favoriteCompanies[2]=["facebook","google"] 是
 * favoriteCompanies[0]=["leetcode","google","facebook"] 的子集，因此，答案为 [0,1] 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：favoriteCompanies = [["leetcode"],["google"],["facebook"],["amazon"]]
 * 输出：[0,1,2,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= favoriteCompanies.length <= 100
 * 1 <= favoriteCompanies[i].length <= 500
 * 1 <= favoriteCompanies[i][j].length <= 20
 * favoriteCompanies[i] 中的所有字符串 各不相同 。
 * 用户收藏的公司清单也 各不相同 ，也就是说，即便我们按字母顺序排序每个清单， favoriteCompanies[i] !=
 * favoriteCompanies[j] 仍然成立。
 * 所有字符串仅包含小写英文字母。
 * 
 * 
 */

/**
 * @file 1452.收藏清单.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-12 23:11:46
 * @brief 判断字符串集合是否是另一个字符串集合的子集
 *          - 先对集合进行排序
 *          - 用两个指针进行比较，被比较的集合越界，表示已经全部在另一个集合中找到即就是子集
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();
        for (auto &v : favoriteCompanies) 
            sort(v.begin(), v.end());
        vector<int> res;
        for (int i = 0; i < n; i++) {
            bool find = false;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    vector<string> &A = favoriteCompanies[i];
                    vector<string> &B = favoriteCompanies[j];
                    int index = 0;
                    for (int b = 0; b < B.size() && index < A.size(); b++) {
                        if (A[index] == B[b])
                            index++;
                    }
                    if (index == A.size()) {
                        find = true;
                        break;
                    }
                }
            }
            if (!find) 
                res.push_back(i);
        }

        return res;
    }
};
// @lc code=end

