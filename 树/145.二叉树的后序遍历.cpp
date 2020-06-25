/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Github: https://github.com/Kay-Rick
 * @Date: 2020-03-13 14:15:12
 * @LastEditors: Kay_Rick@outlook.com
 * @LastEditTime: 2020-06-25 10:18:07
 * @FilePath: /LeetCode/145.二叉树的后序遍历.cpp
 * @Description: Description
 */
/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (69.09%)
 * Likes:    239
 * Dislikes: 0
 * Total Accepted:    57.2K
 * Total Submissions: 81.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
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
     * @brief 后序遍历非递归算法 ==> 中序遍历稍作修改
     * @param root 
     * @return vector<int> 
     */
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* T = root;
        while (T != NULL || !s.empty()) {
            // 遇到第一个结点就压栈，并去访问右子树，将结果放在前面
            while (T != NULL) {
                s.push(T);
                res.insert(res.begin(),T->val);
                T = T->right;
            }
            // 访问栈顶元素，遍历结点左子树
            if (!s.empty()) {
                T = s.top();
                s.pop();
                T = T->left;
            }
        }
        return res;
    }
};
// @lc code=end

/* 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root != NULL) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            res.push_back(root->val);
        }
        return res;
    }
private:
    vector<int> res;
}; 
*/