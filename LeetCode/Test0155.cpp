/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Github: https://github.com/Kay-Rick
 * @Date: 2020-03-06 14:14:54
 * @LastEditors: Rick
 * @LastEditTime: 2020-03-06 14:28:44
 * @FilePath: /LeetCode/Test0155.cpp
 * @Description: 最小栈的问题采用两个栈来进行解决
 */
/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (50.65%)
 * Likes:    395
 * Dislikes: 0
 * Total Accepted:    78.2K
 * Total Submissions: 150.9K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) -- 将元素 x 推入栈中。
 * pop() -- 删除栈顶的元素。
 * top() -- 获取栈顶元素。
 * getMin() -- 检索栈中的最小元素。
 * 
 * 
 * 示例:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 */
#include<iostream>
#include<stack>
using namespace std;
// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    /**
     * @description: 用另一个栈来维护当前加入栈的最小元素
     * @param {x} 
     * @return: 
     */
    void push(int x) {
        s1.push(x);
        if(s2.empty()){
            s2.push(x);
        }else
        {
            int t = s2.top();
            s2.push((x < t) ? x : t);
        }
    }

    void pop() {
        s1.pop();
        s2.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }

private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

