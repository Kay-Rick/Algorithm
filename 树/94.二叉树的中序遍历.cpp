/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Github: https://github.com/Kay-Rick
 * @Date: 2020-03-10 13:15:56
 * @LastEditors: Kay_Rick@outlook.com
 * @LastEditTime: 2020-06-25 10:08:40
 * @Description: Description
 */
/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (69.22%)
 * Likes:    416
 * Dislikes: 0
 * Total Accepted:    116.5K
 * Total Submissions: 165.3K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
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
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */
#include <iostream>
#include <vector>
#include <stack>
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
     * @brief 中序遍历非递归算法
     * @param root 
     * @return vector<int> 
     */
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* T = root;
        vector<int> res;
        stack<TreeNode*> s;
        while (T != NULL || !s.empty()) {
            // 遇到第一个结点就压栈，并遍历左子树
            while (T != NULL) {
                s.push(T);
                T = T->left;
            }
            if (!s.empty()) {
                // 左子树遍历结束，从栈顶弹出结点并访问
                T = s.top();
                s.pop();
                res.push_back(T->val);
                // 按右指针去中序遍历该结点右子树
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root != NULL) {
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
    }
private:
    vector<int> res;
}; 
*/
