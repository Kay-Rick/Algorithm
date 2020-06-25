/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (71.49%)
 * Likes:    456
 * Dislikes: 0
 * Total Accepted:    124.2K
 * Total Submissions: 172.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 * 
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最大深度 3 。
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
    int max_depth = 0;
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        dfs (root, 1);
        return max_depth;
    }
    /**
     * @brief DFS求最大深度
     * @param root 
     * @param depth 
     */
    void dfs (TreeNode* root, int depth) {
        // 是叶子结点，更新最大高度
        if (root->left == NULL && root->right == NULL) {
            max_depth = max(max_depth, depth); 
        }
        // 递归左子树
        if (root->left != NULL)
            dfs(root->left, depth + 1);
        // 递归右子树
        if (root->right != NULL)
            dfs(root->right, depth + 1);
    }
};
// @lc code=end
/* 
class Solution {
  public:
    int maxDepth(TreeNode *root) {
        TreeNode *T = root;
        int res = 0;
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode *> q;
        q.push(T);
        while (!q.empty()) {
            res++;
            // 一定要将 q.size() 放在初始化里，而不能放在判断停止的条件中
            // 因为q的大小是随时变化的，所以放停止条件中会出错
            for (int i = q.size(); i > 0; i--) {
                T = q.front();
                q.pop();
                if (T->left != NULL) {
                    q.push(T->left);
                }
                if (T->right != NULL) {
                    q.push(T->right);
                }
            }
        }
        return res;
    }
};
 */

/* 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
 */