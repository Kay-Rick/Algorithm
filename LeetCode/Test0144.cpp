/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Github: https://github.com/Kay-Rick
 * @Date: 2020-03-12 20:07:27
 * @LastEditors: Rick
 * @LastEditTime: 2020-03-12 23:27:20
 * @FilePath: /LeetCode/Users/rick/Desktop/GitHub_Reposity/Algorithm/src/LeetCode/Test0144.cpp
 * @Description: Description
 */
/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (62.90%)
 * Likes:    216
 * Dislikes: 0
 * Total Accepted:    76.8K
 * Total Submissions: 119K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [1,2,3]
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */
#include <iostream>
#include <stack>
#include <vector>
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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* T = root;
        vector<int> res;
        stack <TreeNode*> s;
        while (T != NULL || !s.empty()) {
            while (T != NULL) {
                res.push_back(T->val);
                s.push(T);
                T = T->left;
            }
            if (!s.empty()) {
                T = s.top();
                s.pop();
                T = T->right;
            }
        }
        return res;
    }
};
// @lc code=end
/* 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root != NULL) {
            res.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return res;
    }
private:
    vector<int> res;
}; 
*/