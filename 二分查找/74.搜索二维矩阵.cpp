/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (37.88%)
 * Likes:    178
 * Dislikes: 0
 * Total Accepted:    44.2K
 * Total Submissions: 116.7K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 * 
 * 
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * 输出: false
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 二维数组转换成一维进行标准二分查找（利用取余和取模）
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0)
            return false;
        int cols = matrix[0].size();
        if (cols == 0)
            return false;
        int left = 0, right = rows * cols - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid / cols][mid % cols] == target)
                return true;
            else if (matrix[mid / cols][mid % cols] < target)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return false;
    }
};
// @lc code=end
/* 
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int row = -1;
        int rows = matrix.size();
        if (rows == 0)
            return false;
        int cols = matrix[0].size();
        if (cols == 0)
            return false;
        // 确定是在矩阵的某一行
        for (int i = 0; i < rows; i++) {
            if (target >= matrix[i][0] && target <= matrix[i][cols - 1]) {
                row = i;
                break;
            }
        }
        // 找到了在某一行后，进行二分查找
        if (row >= 0) {
            int left = 0, right = cols - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (matrix[row][mid] == target)
                    return true;
                if (matrix[row][mid] > target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return false;
    }
};

 */