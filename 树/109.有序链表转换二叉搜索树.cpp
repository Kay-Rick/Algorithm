/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (72.36%)
 * Likes:    250
 * Dislikes: 0
 * Total Accepted:    33.2K
 * Total Submissions: 45.5K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定的有序链表： [-10, -3, 0, 5, 9],
 * 
 * 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */

/**
 * @file 109.有序链表转换二叉搜索树.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-07-12 22:31:40
 * @brief 每次通过找链表的中点来构建(题目同108题)
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
        int cnt = 0;
        for (auto p = head; p != NULL; p = p->next)
            cnt++;
        if (cnt == 1)
            return new TreeNode(head->val);
        ListNode* cur = head;
        // cur 指向根节点左子树中的最后一个节点
        for (int i = 0; i < cnt / 2 - 1; i++)
            cur = cur->next;
        // 根节点
        TreeNode* root = new TreeNode(cur->next->val);
        root->right = sortedListToBST(cur->next->next);
        cur->next = NULL;
        root->left = sortedListToBST(head);
        return root;
    }
};
// @lc code=end

