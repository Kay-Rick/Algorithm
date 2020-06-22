/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 *
 * https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/description/
 *
 * algorithms
 * Medium (32.90%)
 * Likes:    41
 * Dislikes: 0
 * Total Accepted:    8.2K
 * Total Submissions: 24.5K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * 在一个 N × N 的方形网格中，每个单元格有两种状态：空（0）或者阻塞（1）。
 * 
 * 一条从左上角到右下角、长度为 k 的畅通路径，由满足下述条件的单元格 C_1, C_2, ..., C_k 组成：
 * 
 * 
 * 相邻单元格 C_i 和 C_{i+1} 在八个方向之一上连通（此时，C_i 和 C_{i+1} 不同且共享边或角）
 * C_1 位于 (0, 0)（即，值为 grid[0][0]）
 * C_k 位于 (N-1, N-1)（即，值为 grid[N-1][N-1]）
 * 如果 C_i 位于 (r, c)，则 grid[r][c] 为空（即，grid[r][c] == 0）
 * 
 * 
 * 返回这条从左上角到右下角的最短畅通路径的长度。如果不存在这样的路径，返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[0,1],[1,0]]
 * 
 * 输出：2
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[0,0,0],[1,1,0],[1,1,0]]
 * 
 * 输出：4
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 100
 * grid[i][j] 为 0 或 1
 * 
 * 
 */

/**
 * @file 1091.二进制矩阵中的最短路径.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-21 22:10:03
 * @brief BFS搜索
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int directions[8][8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1}, {1, 0}};
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({0, 0});
        int res = 0;
    
        while(!q.empty()) {
            int count = q.size();
            res++;
            while (count--) {
                pair<int, int> t = q.front();
                q.pop();
                int x = t.first;
                int y = t.second;
                if (grid[x][y] == 1)
                    continue;
                if (x == m - 1 && y == n - 1)
                    return res;
                grid[x][y] = 1;
                // 枚举8个方向
                for(auto d: directions) {
                    int nx = x + d[0];
                    int ny = y + d[1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    q.push({nx, ny});
                }
            }
        }
        return -1;
    }
};
// @lc code=end

