/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (54.48%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    57.2K
 * Total Submissions: 104.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层次遍历如下：
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */

/**
 * @file 103.二叉树的锯齿形层次遍历.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-12 22:13:38
 * @brief 层序遍历，偶数层翻转
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root != NULL)
            q.push(root);
        int order = 0;
        while (!q.empty()) {
            int cnt = q.size();
            vector<int> level;
            while (cnt--) {
                TreeNode* t = q.front();
                q.pop();
                level.push_back(t->val);
                if (t->left != NULL)
                    q.push(t->left);
                if (t->right != NULL)
                    q.push(t->right);
            }
            if (++order % 2 == 0)
                reverse(level.begin(), level.end());
            res.push_back(level);
        }

        return res;
    }
};
// @lc code=end

