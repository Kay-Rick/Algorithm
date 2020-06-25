/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Github: https://github.com/Kay-Rick
 * @Date: 2020-03-12 22:18:06
 * @LastEditors: Kay_Rick@outlook.com
 * @LastEditTime: 2020-06-25 10:19:21
 * @FilePath: /LeetCode/src/Accepted/102.二叉树的层次遍历.cpp
 * @Description: BFS 使用队列进行层次遍历
 */
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (59.96%)
 * Likes:    402
 * Dislikes: 0
 * Total Accepted:    88.5K
 * Total Submissions: 144.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 例如:
 * 给定二叉树: [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    /**
     * @brief 层序遍历：使用队列 BFS 思想
     * @param root 
     * @return vector<vector<int>> 
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root == NULL) {
            return res;
        }
        q.push(root);
        while (!q.empty()) {
            vector<int> v;
            // 使用count记录每一层的个数
            int count = q.size();
            while (count--) {
                TreeNode* T;
                T = q.front();
                q.pop();
                v.push_back(T->val);
                if (T->left != NULL) {
                    q.push(T->left);
                }        
                if (T->right != NULL) {
                    q.push(T->right);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};
// @lc code=end
