/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (65.61%)
 * Likes:    263
 * Dislikes: 0
 * Total Accepted:    67.8K
 * Total Submissions: 102.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
 */

/**
 * @file 107.二叉树的层次遍历-ii.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-12 22:21:43
 * @brief 层序遍历序列从底层往上输出
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root != NULL) 
            q.push(root);
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
            res.insert(res.begin(), level);
        }
        return res;
    }
};
// @lc code=end

