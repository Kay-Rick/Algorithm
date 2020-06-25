/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Github: https://github.com/Kay-Rick
 * @Date: 2020-03-12 20:07:27
 * @LastEditors: Kay_Rick@outlook.com
 * @LastEditTime: 2020-06-25 09:58:18
 * @FilePath: /LeetCode/Test0144.cpp
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
    /**
     * @brief 先序遍历非递归算法
     * @param root 
     * @return vector<int> 
     */
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* T = root;
        vector<int> res;
        stack <TreeNode*> s;
        while (T != NULL || !s.empty()) {
            // 遇到第一个结点就压栈，并去遍历左子树
            while (T != NULL) {
                // 第一次访问结点就加到结果集
                res.push_back(T->val);
                s.push(T);
                T = T->left;
            }
            if (!s.empty()) {
                // 左子树遍历结束，弹出栈顶元素
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
