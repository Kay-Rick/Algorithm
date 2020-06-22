/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 *
 * https://leetcode-cn.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (41.65%)
 * Likes:    112
 * Dislikes: 0
 * Total Accepted:    9K
 * Total Submissions: 21.4K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * 给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。
 * 
 * 规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。
 * 
 * 请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输出坐标的顺序不重要
 * m 和 n 都小于150
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 
 * 给定下面的 5x5 矩阵:
 * 
 * ⁠ 太平洋 ~   ~   ~   ~   ~ 
 * ⁠      ~  1   2   2   3  (5) *
 * ⁠      ~  3   2   3  (4) (4) *
 * ⁠      ~  2   4  (5)  3   1  *
 * ⁠      ~ (6) (7)  1   4   5  *
 * ⁠      ~ (5)  1   1   2   4  *
 * ⁠         *   *   *   *   * 大西洋
 * 
 * 返回:
 * 
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).
 * 
 * 
 * 
 * 
 */

/**
 * @file 417.太平洋大西洋水流问题.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-22 19:59:01
 * @brief DFS
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<bool>> A, B;
    vector<vector<int>> res;
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return res;
        m = matrix.size();
        n = matrix[0].size();
        // 对数组进行初始化
        A.resize(m, vector<bool>(n, 0));
        B.resize(m, vector<bool>(n, 0));
        // 从边缘开始搜
        for (int i = 0; i < m; i++) {
            dfs(matrix, i, 0, INT32_MIN,A);
            dfs(matrix, i, n - 1, INT32_MIN, B);
        }
        for (int i = 0; i < n; i++) {
            dfs(matrix, 0, i, INT32_MIN, A);
            dfs(matrix, m - 1, i, INT32_MIN, B);
        }
        // 将搜到的A和B求交集
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] && B[i][j])
                    res.push_back(vector<int>({i, j}));
            }
        }
        return res;
    }

    /**
     * @brief 
     * @param matrix 
     * @param r 行号
     * @param c 列号
     * @param prev 前一个序号的值
     * @param st 
     */
    void dfs (vector<vector<int>>& matrix, int r, int c, int prev, vector<vector<bool>>& st) {
        if (r < 0 || r >= m || c < 0 || c >= n || st[r][c] || matrix[r][c] < prev)
            return;
        st[r][c] = true;
        for (auto d : directions) {
            int x = r + d[0];
            int y = c + d[1];
            dfs(matrix, x, y, matrix[r][c], st);
        }
    }
};
// @lc code=end

/* 
        ！！！TLE！！！
class Solution {
  public:
    vector<vector<bool>> A, B;
    vector<vector<int>> res;
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
        if (matrix.size() == 0)
            return res;
        m = matrix.size();
        n = matrix[0].size();
        // 对数组进行初始化
        A.resize(m, vector<bool>(n, 0));
        B.resize(m, vector<bool>(n, 0));
        for (int i = 0; i < m; i++) {
            dfs(matrix, i, 0, A);
            dfs(matrix, i, n - 1, B);
        }
        for (int i = 0; i < n; i++) {
            dfs(matrix, 0, i, A);
            dfs(matrix, m - 1, i, B);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] && B[i][j])
                    res.push_back(vector<int>({i, j}));
            }
        }

        return res;
    }

    void dfs(vector<vector<int>> &matrix, int r, int c, vector<vector<bool>> &st) {
        if (st[r][c])
            return;
        st[r][c] = true;
        for (auto d : directions) {
            int x = r + d[0];
            int y = c + d[1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[r][c] > matrix[x][y])
                continue;
            dfs(matrix, x, y, st);
        }
    }
};

 */