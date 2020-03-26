/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Github: https://github.com/Kay-Rick
 * @Date: 2020-03-12 20:42:12
 * @LastEditors: Rick
 * @LastEditTime: 2020-03-12 23:27:32
 * @FilePath: /LeetCode/Users/rick/Desktop/GitHub_Reposity/Algorithm/src/LeetCode/Test0145.cpp
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* T = root;
        TreeNode* r;
        bool flag;
        do 
        {
            while (T != NULL) {
                s.push(T);
                T = T->left;
            }
            r = NULL;
            flag = true;
            while (!s.empty() && flag) {
                T = s.top();
                if (T->right == r) {
                    res.push_back(T->val);
                    s.pop();
                    r = T;
                }
                else {
                    T = T->right;
                    flag = false;
                }
            }
        } while (!s.empty());
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