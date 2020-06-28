/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (63.98%)
 * Likes:    279
 * Dislikes: 0
 * Total Accepted:    41.5K
 * Total Submissions: 64.8K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
 * 
 */

/**
 * @file 257.二叉树的所有路径.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-28 20:29:01
 * @brief DFS求二叉树所有路径
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <vector>
#include <string>
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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL)
            return res;
        dfs(root, to_string(root->val));        
        return res;
    }

    void dfs(TreeNode* root, string path) {
        // 是根节点
        if (!root->left && !root->right)
            res.push_back(path);
        if (root->left)
            dfs(root->left, path + "->" + to_string(root->left->val));
        if (root->right)
            dfs(root->right, path + "->" + to_string(root->right->val));
    } 
};
// @lc code=end
/* 
class Solution {
  public:
    vector<vector<int>> temp;
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode *root) {
        if (root == NULL)
            return res;
        vector<int> path;
        dfs(root, path);
        // 使用int先存储路径，最后再处理结果
        for (auto s : temp) {
            string str = to_string(s[0]);
            for (int i = 1; i < s.size(); i++) {
                str += "->" + to_string(s[i]);
            }
            res.push_back(str);
        }
        return res;
    }

    void dfs(TreeNode *root, vector<int> &path) {
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
            temp.push_back(path);
        if (root->left)
            dfs(root->left, path);
        if (root->right)
            dfs(root->right, path);
        path.pop_back();
    }
};

 */