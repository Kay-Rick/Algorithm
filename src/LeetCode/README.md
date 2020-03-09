- [环形链表](#%e7%8e%af%e5%bd%a2%e9%93%be%e8%a1%a8)
  - [快慢指针](#%e5%bf%ab%e6%85%a2%e6%8c%87%e9%92%88)
- [移动零](#%e7%a7%bb%e5%8a%a8%e9%9b%b6)
  - [解法1：用count计录0的个数](#%e8%a7%a3%e6%b3%951%e7%94%a8count%e8%ae%a1%e5%bd%950%e7%9a%84%e4%b8%aa%e6%95%b0)
  - [解法2：双指针](#%e8%a7%a3%e6%b3%952%e5%8f%8c%e6%8c%87%e9%92%88)
- [有效的括号](#%e6%9c%89%e6%95%88%e7%9a%84%e6%8b%ac%e5%8f%b7)
  - [栈实现(优秀题解)](#%e6%a0%88%e5%ae%9e%e7%8e%b0%e4%bc%98%e7%a7%80%e9%a2%98%e8%a7%a3)
- [最小栈](#%e6%9c%80%e5%b0%8f%e6%a0%88)
  - [解法：两个栈来实现](#%e8%a7%a3%e6%b3%95%e4%b8%a4%e4%b8%aa%e6%a0%88%e6%9d%a5%e5%ae%9e%e7%8e%b0)
- [柱状图中最大的矩形](#%e6%9f%b1%e7%8a%b6%e5%9b%be%e4%b8%ad%e6%9c%80%e5%a4%a7%e7%9a%84%e7%9f%a9%e5%bd%a2)
  - [解法1：暴力法](#%e8%a7%a3%e6%b3%951%e6%9a%b4%e5%8a%9b%e6%b3%95)
  - [解法2：有序栈](#%e8%a7%a3%e6%b3%952%e6%9c%89%e5%ba%8f%e6%a0%88)
- [有效的字母异位词](#%e6%9c%89%e6%95%88%e7%9a%84%e5%ad%97%e6%af%8d%e5%bc%82%e4%bd%8d%e8%af%8d)
  - [解法1：排序](#%e8%a7%a3%e6%b3%951%e6%8e%92%e5%ba%8f)
  - [解法2：哈希表](#%e8%a7%a3%e6%b3%952%e5%93%88%e5%b8%8c%e8%a1%a8)
- [字母异位词分组](#%e5%ad%97%e6%af%8d%e5%bc%82%e4%bd%8d%e8%af%8d%e5%88%86%e7%bb%84)
  - [解法1：排序数组分类](#%e8%a7%a3%e6%b3%951%e6%8e%92%e5%ba%8f%e6%95%b0%e7%bb%84%e5%88%86%e7%b1%bb)
  - [解法2：引入下标](#%e8%a7%a3%e6%b3%952%e5%bc%95%e5%85%a5%e4%b8%8b%e6%a0%87)
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





## 最小栈

```
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
```



### 解法：两个栈来实现

```c++
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
```

每次在进行进栈操作的时候，都和栈顶元素进行比较，保存一个最小元素到第二个栈



## 柱状图中最大的矩形

![image-20200306155536243](https://tva1.sinaimg.cn/large/00831rSTly1gck9h2pbidj30u00vd76w.jpg)



### 解法1：暴力法

```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            int m = i;
            int n = i;
            while (m >= 0 && heights[m] >= heights[i])
            {
                m--;
            }
            while (n < heights.size() && heights[n] >= heights[i])
            {
                n++;
            }
            max_area = max(max_area, heights[i] * (n - m - 1));
        }

        return max_area;
    }
};
```

计算出每一个柱子的左右边界，更新最大面积



### 解法2：有序栈

在这种方法中，我们维护一个栈。一开始，我们把 -1 放进栈的顶部来表示开始。初始化时，按照从左到右的顺序，我们不断将柱子的序号放进栈中，直到遇到相邻柱子呈下降关系，也就是 `a[i−1]>a[i]` 。现在，我们开始将栈中的序号弹出，直到遇到 `stack[j] `满足`a[stack[j]]≤a[i]` 。每次我们弹出下标时，我们用弹出元素作为高形成的最大面积矩形的宽是当前元素与 `stack[top−1]` 之间的那些柱子。也就是当我们弹出 `stack[top]` 时，记当前元素在原数组中的下标为 `i` ，当前弹出元素为高的最大矩形面积为：

​														`(i−stack[top−1]−1)×a[stack[top]].`

更进一步，当我们到达数组的尾部时，我们将栈中剩余元素全部弹出栈。在弹出每一个元素是，我们用下面的式子来求面积： `(stack[top]−stack[top−1])×a[stack[top]]`，其中`stack[top]`表示刚刚被弹出的元素。因此，我们可以通过每次比较新计算的矩形面积来获得最大的矩形面积。

```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        s.push(-1);
        int maxarea = 0;
        // 对每一个元素进行处理
        for (int i = 0; i < heights.size(); i++)
        {
            // 当当前元素比栈顶元素小的时候，每次出栈都进行面积计算
            while (s.top() != -1 && heights[s.top()] >= heights[i])
            {
                int temp = s.top();
                s.pop();
                maxarea = max(maxarea, heights[temp] * (i - s.top() - 1));
            }
            s.push(i);
        }
        // 处理尾部元素和最小元素
        while (s.top() != -1)
        {
            int temp = s.top();
            int size = heights.size();
            s.pop();
            maxarea = max(maxarea, heights[temp] * (size - s.top() - 1));
        }
        return maxarea;
    }
};
```



## 有效的字母异位词

```
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:
输入: s = "anagram", t = "nagaram"
输出: true
示例 2:
输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。

进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
```



### 解法1：排序

通过将s 的字母重新排列成 t 来生成变位词。因此，如果 T 是 S 的变位词，对两个字符串进行排序将产生两个相同的字符串。此外，如果 s 和 t 的长度不同，t 不能是 s 的变位词，我们可以提前返回。

```java
public boolean isAnagram(String s, String t) {
    if (s.length() != t.length()) {
        return false;
    }
    char[] str1 = s.toCharArray();
    char[] str2 = t.toCharArray();
    Arrays.sort(str1);
    Arrays.sort(str2);
    return Arrays.equals(str1, str2);
}
```



### 解法2：哈希表

为了检查 t 是否是 s 的重新排列，我们可以计算两个字符串中每个字母的出现次数并进行比较。因为 S 和 T 都只包含 A−Z 的字母，所以一个简单的 26 位计数器表就足够了。
**我们需要两个计数器数表进行比较吗？实际上不是，因为我们可以用一个计数器表计算s 字母的频率，用 t 减少计数器表中的每个字母的计数器，然后检查计数器是否回到零**

```java
public boolean isAnagram(String s, String t) {
    if (s.length() != t.length()) {
        return false;
    }
    int[] counter = new int[26];
    for (int i = 0; i < s.length(); i++) {
        counter[s.charAt(i) - 'a']++;
        counter[t.charAt(i) - 'a']--;
    }
    for (int count : counter) {
        if (count != 0) {
            return false;
        }
    }
    return true;
}
```



## 字母异位词分组

```
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:
输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：
所有输入均为小写字母。
不考虑答案输出的顺序。
```



### 解法1：排序数组分类

维护一个映射 `ans : {String -> List}`，其中每个键 KK 是一个排序字符串，每个值是初始输入的字符串列表，排序后等于 K

![image-20200310000617545](https://tva1.sinaimg.cn/large/00831rSTly1gco4ijmo0gj30r60emq5q.jpg)

```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if (strs.length == 0) return new ArrayList();
        Map<String, List> ans = new HashMap<String, List>();
        for (String s : strs) {
            char[] ca = s.toCharArray();
            Arrays.sort(ca);
            String key = String.valueOf(ca);
            if (!ans.containsKey(key)) ans.put(key, new ArrayList());
            ans.get(key).add(s);
        }
        return new ArrayList(ans.values());
    }
}
```



### 解法2：引入下标

```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int sub = 0;                    // 记录结果集res的下标
        string tmp;
        unordered_map <string,int> work;
        for (auto str : strs) {
            tmp = str;                  // 排序后将tmp作为key进行标识
            sort(tmp.begin(), tmp.end());
            // 如果能找到同一个组里面,就在该异位词标识的(key)分组work[tmp]下加
            if (work.count(tmp)) {
                res[work[tmp]].push_back(str);
            }else
            {
                vector<string> vec (1, str);  // 初始化一个长度为1的数组为str
                res.push_back(vec);
                // 在该分组下面在res结果集的下标,方便于我们后续能够找到合适的分组
                work[tmp] = sub++;   
            }
        }
        return res;
    }
};
```

