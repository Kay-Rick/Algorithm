/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (41.90%)
 * Likes:    344
 * Dislikes: 0
 * Total Accepted:    45.2K
 * Total Submissions: 106.4K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hash;
        for (string s : wordList) 
            hash.insert(s);
        int res = 1;
        int size = beginWord.size();
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()) {
            int cnt = q.size();
            while(cnt--) {
                string str = q.front();
                q.pop();
                if (str == endWord)
                    return res;
                hash.erase(str);
                for (int i = 0; i < size; i++) {
                    char c = str[i];
                    for (int j = 0; j < 26; j++) {
                        str[i] = 'a' + j;
                        if (hash.count(str))
                            q.push(str);
                    }
                    str[i] = c;
                }
            }
            res++;
        }
        return 0;
    }
};
// @lc code=end

