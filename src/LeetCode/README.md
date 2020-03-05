- [环形链表](#%e7%8e%af%e5%bd%a2%e9%93%be%e8%a1%a8)
  - [快慢指针](#%e5%bf%ab%e6%85%a2%e6%8c%87%e9%92%88)
- [移动零](#%e7%a7%bb%e5%8a%a8%e9%9b%b6)
  - [解法1：用count计录0的个数](#%e8%a7%a3%e6%b3%951%e7%94%a8count%e8%ae%a1%e5%bd%950%e7%9a%84%e4%b8%aa%e6%95%b0)
  - [解法2：双指针](#%e8%a7%a3%e6%b3%952%e5%8f%8c%e6%8c%87%e9%92%88)
- [有效的括号](#%e6%9c%89%e6%95%88%e7%9a%84%e6%8b%ac%e5%8f%b7)
  - [栈实现(优秀题解)](#%e6%a0%88%e5%ae%9e%e7%8e%b0%e4%bc%98%e7%a7%80%e9%a2%98%e8%a7%a3)
## 环形链表
```
给定一个链表，判断链表中是否有环。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
```



### 快慢指针

```java
class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        while (slow != fast) {
            if (fast == null || fast.next == null) {
                return false;
            }
            slow = slow.next;
            fast = fast.next.next;
        }
        return true;
    }
}
```

一个指针走的快，一个指针走的慢，这样有环的时候，快慢指针必然会相遇

## 移动零

```
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
```



### 解法1：用count计录0的个数

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                count++;
            } else {
                nums[i - count] = nums[i];
                if (count != 0) {
                    nums[i] = 0;
                }
            }
        }
    }
}
```



### 解法2：双指针

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                if (i != j) {
                    nums[i] = 0;
                }
                j++;
            }
        }
    }
}
```



## 有效的括号

```
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
```



### 栈实现(优秀题解)

```c++
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int> m{{'(',1},{'[',2},{'{',3},
                                {')',4},{']',5},{'}',6}};
        stack<char> st;
        bool istrue=true;
        for(char c:s){
            int flag=m[c];
            if(flag>=1&&flag<=3) st.push(c);
            else if(!st.empty()&&m[st.top()]==flag-3) st.pop();
            else {istrue=false;break;}
        }
        if(!st.empty()) istrue=false;
        return istrue;
    }
};
```

