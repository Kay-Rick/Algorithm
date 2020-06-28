/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (41.67%)
 * Likes:    456
 * Dislikes: 0
 * Total Accepted:    66K
 * Total Submissions: 157.8K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int n, m;
    vector<vector<bool>> st;
    bool exist(vector<vector<char>> &board, string word) {
        m = board.size();
        n = board[0].size();
        st.resize(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    } 

    /**
     * @brief DFS找到 word 是否存在在board二维数组
     * @param board 
     * @param word 
     * @param col 
     * @param row 
     * @param cur 
     * @return true 
     * @return false 
     */
    bool dfs (vector<vector<char>>& board, string word, int col, int row, int cur) {
        if (cur == word.size()){
            return true;
        }
        if (col < 0 || col >= m || row < 0 || row >= n || board[col][row] != word[cur] || st[col][row])
            return false;
        st[col][row] = true;
        for (auto d : directions) {
            if (dfs(board, word, col + d[0], row + d[1], cur + 1))
                return true;
        }
        st[col][row] = false;
        return false;
    }
};
// @lc code=end

