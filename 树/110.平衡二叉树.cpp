/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (51.89%)
 * Likes:    374
 * Dislikes: 0
 * Total Accepted:    89K
 * Total Submissions: 169.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * 
 * 
 * 示例 1:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7]
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回 true 。
 * 
 * 示例 2:
 * 
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * 返回 false 。
 * 
 * 
 * 
 */

/**
 * @file 110.平衡二叉树.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-12 23:14:40
 * @brief 判断一颗树是否是平衡二叉树
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
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
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        return abs(getDepth(root->left) - getDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    /**
     * @brief Get the Depth of Tree
     * @param root 
     * @return int 
     */
    int getDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
};
// @lc code=end

