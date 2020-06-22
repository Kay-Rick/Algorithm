/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (40.04%)
 * Likes:    240
 * Dislikes: 0
 * Total Accepted:    39.4K
 * Total Submissions: 98K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 
 * 示例:
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * 运行你的函数后，矩阵变为：
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * 解释:
 * 
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int m, n;
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0)
            return;
        m = board.size();
        n = board[0].size();
        // 搜到边界连通的O全部替换为占位符
        for (int i = 0; i < m; i++) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int i = 0; i < n; i++) {
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }
        // 将与边界连通的O全部替换回来
        for (int i = 0 ; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }

    /**
     * @brief 将于边界连通的O替换为占位符 # 
     * @param board 
     * @param r 
     * @param c 
     */
    void dfs (vector<vector<char>>& board, int r, int c) {
        // 越界或者是X或者是访问过就return
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] == 'X' || board[r][c] == '#')
            return;
        board[r][c] = '#';
        for (auto d : directions) 
            dfs(board, r + d[0], c + d[1]);
    }

};
// @lc code=end

