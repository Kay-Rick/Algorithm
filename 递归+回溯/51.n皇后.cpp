/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (66.93%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    32.2K
 * Total Submissions: 46.9K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        helper(board, 0);
        return result;
    }

    /**
     * @brief 辅助回溯函数
     * @param board 路径，board 中小于 row 的那些行都已经成功放置了皇后
     * @param row 第 row 行的所有列都是放置皇后的选择
     */
    void helper(vector<string> &board, int row) {
        // row 超过 board 的最后一行，结束
        if (row == board.size()) {
            result.push_back(board);
            return;
        }
        int count = board[row].size();
        for (int col = 0; col < count; col++) {
            // 判断当前列能否放置，若不能放置跳出本轮循环(决策树中的剪枝操作)
            if (!isValid(board, col, row))
                continue;
            // 做选择
            board[row][col] = 'Q';
            // 进行下一轮决策
            helper(board, row + 1);
            // 撤销选择
            board[row][col] = '.';
        }
    }

    /**
     * @brief 判断当前位置是否能放置皇后
     * @param board 
     * @param col 
     * @param row 
     * @return true 
     * @return false 
     */
    bool isValid(vector<string> &board, int col, int row) {
        int n = board.size();
        // 检查列有没有重复（行不用检查，因为我们在放的时候就已经逐行来放）
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        // 检查右上方是否有皇后冲突（因为我们逐层放，只用考虑斜上方的情形）
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        // 检查左上方是否有皇后冲突
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }

  private:
    vector<vector<string>> result;
};
// @lc code=end
