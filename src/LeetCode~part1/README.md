# LeetCode刷题笔记
- [LeetCode刷题笔记](#leetcode%e5%88%b7%e9%a2%98%e7%ac%94%e8%ae%b0)
  - [两数之和](#%e4%b8%a4%e6%95%b0%e4%b9%8b%e5%92%8c)
    - [解法1：暴力求解法](#%e8%a7%a3%e6%b3%951%e6%9a%b4%e5%8a%9b%e6%b1%82%e8%a7%a3%e6%b3%95)
    - [解法1：两遍哈希表 以时间来换空间的解法](#%e8%a7%a3%e6%b3%951%e4%b8%a4%e9%81%8d%e5%93%88%e5%b8%8c%e8%a1%a8-%e4%bb%a5%e6%97%b6%e9%97%b4%e6%9d%a5%e6%8d%a2%e7%a9%ba%e9%97%b4%e7%9a%84%e8%a7%a3%e6%b3%95)
  - [两数相加](#%e4%b8%a4%e6%95%b0%e7%9b%b8%e5%8a%a0)
    - [解法1：归并法](#%e8%a7%a3%e6%b3%951%e5%bd%92%e5%b9%b6%e6%b3%95)
    - [解法2(设置一个进位的变量)：](#%e8%a7%a3%e6%b3%952%e8%ae%be%e7%bd%ae%e4%b8%80%e4%b8%aa%e8%bf%9b%e4%bd%8d%e7%9a%84%e5%8f%98%e9%87%8f)
  - [无重复字符的最长子串](#%e6%97%a0%e9%87%8d%e5%a4%8d%e5%ad%97%e7%ac%a6%e7%9a%84%e6%9c%80%e9%95%bf%e5%ad%90%e4%b8%b2)
    - [解法1：利用Set进行检查是否有重复，双指针进行滑动窗口的检验](#%e8%a7%a3%e6%b3%951%e5%88%a9%e7%94%a8set%e8%bf%9b%e8%a1%8c%e6%a3%80%e6%9f%a5%e6%98%af%e5%90%a6%e6%9c%89%e9%87%8d%e5%a4%8d%e5%8f%8c%e6%8c%87%e9%92%88%e8%bf%9b%e8%a1%8c%e6%bb%91%e5%8a%a8%e7%aa%97%e5%8f%a3%e7%9a%84%e6%a3%80%e9%aa%8c)
    - [解法2：优化的滑动窗口](#%e8%a7%a3%e6%b3%952%e4%bc%98%e5%8c%96%e7%9a%84%e6%bb%91%e5%8a%a8%e7%aa%97%e5%8f%a3)
  - [寻找两个有序数组的中位数](#%e5%af%bb%e6%89%be%e4%b8%a4%e4%b8%aa%e6%9c%89%e5%ba%8f%e6%95%b0%e7%bb%84%e7%9a%84%e4%b8%ad%e4%bd%8d%e6%95%b0)
    - [解法1：暴力归并法](#%e8%a7%a3%e6%b3%951%e6%9a%b4%e5%8a%9b%e5%bd%92%e5%b9%b6%e6%b3%95)
    - [解法2：归并并记录元素个数](#%e8%a7%a3%e6%b3%952%e5%bd%92%e5%b9%b6%e5%b9%b6%e8%ae%b0%e5%bd%95%e5%85%83%e7%b4%a0%e4%b8%aa%e6%95%b0)
    - [解法3：二分法](#%e8%a7%a3%e6%b3%953%e4%ba%8c%e5%88%86%e6%b3%95)

## 两数之和

```
题目描述：
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

```



### 解法1：暴力求解法

``` Java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int [] arr = new int[2];

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] == target - nums[i])
                    return new int[] {i , j};
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
```

暴力法很简单，遍历每个元素 x*x*，并查找是否存在一个值与 target - x相等的目标元素。

时间复杂度：O(n^2)
对于每个元素，我们试图通过遍历数组的其余部分来寻找它所对应的目标元素，这将耗费 O(n) 的时间。因此时间复杂度为 O(n^2)

空间复杂度：O(1)



### 解法1：两遍哈希表 以时间来换空间的解法

通过以空间换取速度的方式，我们可以将查找时间从 O(n)降低到 O(1)。哈希表正是为此目的而构建的，它支持以 近似 恒定的时间进行快速查找。我用“近似”来描述，是因为一旦出现冲突，查找用时可能会退化到 O(n)。但只要你仔细地挑选哈希函数，在哈希表中进行查找的用时应当被摊销为 O(1)

``` java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }
        for (int i = 0;  i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement) && map.get(complement) != i) {
                return new int[] { i, map.get(complement) };
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}

```



## 两数相加

```
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```

### 解法1：归并法

``` java
/**
     * 注意空指针异常的情况
     * @param l1
     * @param l2
     * @return
     */
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2){
        //初始化一个结点
        ListNode node = new ListNode(0);
        ListNode result = node;

        while (l1 != null && l2 != null){
            //  没有进位的情况
            if (node.val + l1.val + l2.val < 10){
                node.val += l1.val + l2.val;
                //  这里必须进行判断,否则可能会多出一个0节点
                if (l1.next != null || l2.next != null){
                    node.next = new ListNode(0);
                    node = node.next;
                }
            }
            //  针对存在进位的情况,这里放心地创建新的节点
            else{
                node.val += l1.val + l2.val - 10;
                node.next = new ListNode(1);
                node = node.next;
            }
            //  循环
            l1 = l1.next;
            l2 = l2.next;
        }

        //  针对l1还有值的情况
        while (l1 != null){
            if (node.val + l1.val >= 10){
                node.val = l1.val + node.val - 10;
                node.next = new ListNode(1);
                node = node.next;
            }else {
                node.val = l1.val + node.val;
                if (l1.next != null){
                    node.next = new ListNode(0);
                    node = node.next;
                }
            }
            l1 = l1.next;
        }
        
        //针对l2还有值
        while (l2 != null){
            if (node.val + l2.val >= 10){
                node.val = l2.val + node.val - 10;
                node.next = new ListNode(1);
                node = node.next;
            }else {
                node.val = l2.val + node.val;
                if (l2.next != null){
                    node.next = new ListNode(0);
                    node = node.next;
                }
            }
            l2 = l2.next;
        }
        return result;
    }
```



### 解法2(设置一个进位的变量)：

``` java
public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode dummyHead = new ListNode(0);
    ListNode p = l1, q = l2, curr = dummyHead;
    // 设置一个进位变量carry进行标识
  	int carry = 0;
    while (p != null || q != null) {
        int x = (p != null) ? p.val : 0;
        int y = (q != null) ? q.val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr.next = new ListNode(sum % 10);
        curr = curr.next;
        if (p != null) p = p.next;
        if (q != null) q = q.next;
    }
    if (carry > 0) {
        curr.next = new ListNode(carry);
    }
    return dummyHead.next;
}
```



## 无重复字符的最长子串

```
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```



### 解法1：利用Set进行检查是否有重复，双指针进行滑动窗口的检验



通过使用 `HashSet` 作为滑动窗口，我们可以用 `O(1) `的时间来完成对字符是否在当前的子字符串中的检查。

滑动窗口是数组/字符串问题中常用的抽象概念。 窗口通常是在数组/字符串中由开始和结束索引定义的一系列元素的集合，即 `[i,j)`（左闭，右开）。而滑动窗口是可以将两个边界向某一方向“滑动”的窗口。例如，我们将 `[i,j) `向右滑动 1 个元素，则它将变为` [i+1,j+1)`（左闭，右开）。回到我们的问题，我们使用 `HashSet` 将字符存储在当前窗口` [i,j)`（最初` j=i`）中。 然后我们向右侧滑动索引` j`，如果它不在 `HashSet` 中，我们会继续滑动 `j`。直到 `s[j]` 已经存在于` HashSet `中。此时，我们找到的没有重复字符的最长子字符串将会以索引 `i `开头。如果我们对所有的` i `这样做，就可以得到答案。

```java
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        Set<Character> set = new HashSet<>();
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            // try to extend the range [i, j]
            if (!set.contains(s.charAt(j))){
                set.add(s.charAt(j++));
                ans = Math.max(ans, j - i);
            }
            else {
                set.remove(s.charAt(i++));
            }
        }
        return ans;
    }
}
```



### 解法2：优化的滑动窗口

上述的方法最多需要执行 `2n `个步骤。事实上，它可以被进一步优化为仅需要 `n` 个步骤。我们可以定义字符到索引的映射，而不是使用集合来判断一个字符是否存在。 当我们找到重复的字符时，我们可以立即跳过该窗口。

也就是说，如果`s[j]` 在`[i,j) `范围内有与` j′`重复的字符，我们不需要逐渐增加` i `。 我们可以直接跳过 `[i，j′] `范围内的所有元素，并将` i `变为` j′+1`

```java
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), ans = 0;
        Map<Character, Integer> map = new HashMap<>(); // current index of character
        // try to extend the range [i, j]
        for (int j = 0, i = 0; j < n; j++) {
            if (map.containsKey(s.charAt(j))) {
                i = Math.max(map.get(s.charAt(j)), i);
            }
            ans = Math.max(ans, j - i + 1);
            map.put(s.charAt(j), j + 1);
        }
        return ans;
    }
}
```



## 寻找两个有序数组的中位数

```
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。

示例 1:
nums1 = [1, 3]
nums2 = [2]
则中位数是 2.0

示例 2:
nums1 = [1, 2]
nums2 = [3, 4]
则中位数是 (2 + 3)/2 = 2.5
```



### 解法1：暴力归并法

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // 归并需要额外开辟新的内存空间
        int[] num = new int[nums1.length + nums2.length];
        double mid = 0;
        int i = 0, j = 0, k = 0;
        // 有序数组的归并操作 
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j]) {
                num[k++] = nums1[i++];
            } else {
                num[k++] = nums2[j++];
            }
        }

        // 以下的循环只能执行两个当中的一个
        while (i < nums1.length) {
            num[k++] = nums1[i++];
        }
        while (j < nums2.length) {
            num[k++] = nums2[j++];
        }

        if (num.length % 2 == 0) {
            mid = (double)((num[num.length / 2] + num[(num.length / 2) - 1]) / 2.0);
        } else {
            mid = (double)num[(num.length / 2)];
        }
        return mid;
    }
}
```

时间复杂度：遍历全部数组**O (m+n)**

空间复杂度：开辟了一个数组，保存合并后的两个数组 *O*(*m*+*n*)



### 解法2：归并并记录元素个数

其实，我们不需要将两个数组真的合并，我们只需要找到中位数在哪里就可以了。

开始的思路是写一个循环，然后里边判断是否到了中位数的位置，到了就返回结果。首先是怎么将奇数和偶数的情况合并一下。

用` len` 表示合并后数组的长度，如果是奇数，我们需要知道第 `(len+1)/2` 个数就可以了，如果遍历的话需要遍历 `int(len/2) + 1` 次(`int`向下取整)。如果是偶数，我们需要知道第 `len/2`和` len/2+1` 个数，也是需要遍历 `len/2+1 `次。所以遍历的话，奇数和偶数都是` len/2+1` 次。

返回中位数的话，**奇数需要最后一次遍历的结果就可以了**，**偶数需要最后一次和上一次遍历的结果**。所以我们用两个变量` left `和` right`，`right` 保存**当前循环的结果**，在**每次循环前将 `right` 的值赋给 `left`。**这样在最后一次循环的时候，`left` 将得到` right `的值，也就是上一次循环的结果，接下来 `right` 更新为最后一次的结果。

循环中该怎么写，什么时候 A 数组后移，什么时候 B 数组后移。用 `aStart `和 `bStart `分别表示当前指向 A 数组和 B 数组的位置。**如果` aStart `还没有到最后并且此时 A 位置的数字小于 B 位置的数组，那么就可以后移了**。也就是`aStart ＜ m && A[aStart] < B[bStart]`。

但如果 B 数组此刻已经没有数字了，继续取数字` B[bStart ]`，则会越界，所以判断下` bStart` 是否大于数组长度了，这样 `||` 后边的就不会执行了，也就不会导致错误了，所以增加为 `aStart ＜ m && (bStart) >= n || A[aStart] < B[bStart])` 。

```java
public double findMedianSortedArrays(int[] A, int[] B) {
    int m = A.length;
    int n = B.length;
    int len = m + n;
    int left = -1, right = -1;
    int aStart = 0, bStart = 0;
  	// 遍历的话，奇数和偶数都是len/2 + 1次
    for (int i = 0; i <= len / 2; i++) {
        left = right;		//	保证left记录前一次遍历的值
        if (aStart < m && (bStart >= n || A[aStart] < B[bStart])) {
            right = A[aStart++];
        } else {
            right = B[bStart++];
        }
    }
  	// 判断是偶数的方法
    if ((len & 1) == 0)
        return (left + right) / 2.0;
    else
        return right;
}
```



时间复杂度：遍历 `len/2+1 `次，`len=m+n`，所以时间复杂度依旧是 **O(m+n)**

空间复杂度：我们申请了常数个变量，也就是` m,n,len,left,right,aStart,bStart,i` 。总共 8 个变量，所以空间复杂度是 **O(1）**



### 解法3：二分法

上边的两种思路，时间复杂度都达不到题目的要求 **O(log(m+n))** 看到 `log`，很明显，我们只有用到二分的方法才能达到。我们不妨用另一种思路，题目是求中位数，其实就是求第` k` 小数的一种特殊情况

[这道算法题太简单？你忽略了时间复杂度的要求！](https://mp.weixin.qq.com/s/FBlH7o-ssj_iMEPLcvsY2w)

首先在两个数组中分别找出第` k/2 `大的数，再比较这两个第 `k/2` 大的数，这里假设两个数组为 A ，B。

那么比较结果会有下面几种情况：

- `A[k/2] = B[k/2]`,那么第 `k` 大的数就是` A[k/2]`
- `A[k/2] > B[k/2]`,那么第 `k` 大的数肯定在 `A[0:k/2+1] `和 `B[k/2:] `中，这样就将**原来的所有数的总和减少到一半**，再在这个范围里面找第` k/2` 大的数即可，这样也达到了二分查找的区别了。
- `A[k/2] < B[k/2]`，那么第 `k `大的数肯定在 `B[0:k/2+1]和 A[k/2:] `中，同理在这个范围找第 `k/2` 大的数就可以了。

```java
public double findMedianSortedArrays(int[] nums1, int[] nums2) {
    int n = nums1.length;
    int m = nums2.length;
    int left = (n + m + 1) / 2;
    int right = (n + m + 2) / 2;
    //一个小技巧：将偶数和奇数的情况合并，如果是奇数，会求两次同样的 k 。
    return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) + getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) * 0.5;  
}

    private int getKth(int[] nums1, int start1, int end1, int[] nums2, int start2, int end2, int k) {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        //让 len1 的长度小于 len2，这样就能保证如果有数组空了，一定是 len1 
        if (len1 > len2) return getKth(nums2, start2, end2, nums1, start1, end1, k);
        if (len1 == 0) return nums2[start2 + k - 1];

        if (k == 1) return Math.min(nums1[start1], nums2[start2]);

        int i = start1 + Math.min(len1, k / 2) - 1;
        int j = start2 + Math.min(len2, k / 2) - 1;

        if (nums1[i] > nums2[j]) {
            return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
        }
        else {
            return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
        }
    }

```



## 最长回文子串

```
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"
```



### 解法1：暴力求解1 =>过于复杂

```java
public String longestPalindrome(String s) {
    String str = "";
    int i = 0, j = s.length() - 1;
    int max_len = 0;
    if (s.length() == 1) {
        return s;
    }
    /* 每一轮内循环都是固定指针i，在内部进行比较 */
    while (i != s.length()) {
        String substr;
        /* j从后面往前面遍历，双指针 */
        while (j != i) {
            // 遍历时不能使i和j移动，就用m和n记录
            int m = i, n = j, k = j;
            /* 每一轮去查找回文串 */
            while (m < n) {
                if (s.charAt(m) == s.charAt(n)) {
                    m++;
                    n--;
                } else {
                    m = i;
                    n = --k;
                }
            }
            substr = s.substring(i, k + 1);
            // 如果找到更长的子串，则进行替换
            max_len = Math.max(max_len, substr.length());
            if (max_len == substr.length()) {
                str = substr;
            }
            j--;
        }
        i++;
        // 开始新的一轮遍历之前，都要重新置指针j到字符串某尾
        j = s.length() - 1;
    }
    return str;
}
```



### 解法二：暴力求解2

暴力求解，列举所有的子串，判断是否为回文串，保存最长的回文串。

```java
public boolean isPalindromic(String s) {
    int len = s.length();
    for (int i = 0; i < len / 2; i++) {
        if (s.charAt(i) != s.charAt(len - i - 1)) {
            return false;
        }
    }
    return true;
}

// 暴力解法
public String longestPalindrome(String s) {
    String ans = "";
    int max = 0;
    int len = s.length();
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j <= len; j++) {
            String test = s.substring(i, j);
            if (isPalindromic(test) && test.length() > max) {
                ans = s.substring(i, j);
                max = Math.max(max, ans.length());
            }
        }
    return ans;
}
```

时间复杂度：两层 for 循环 O(n²），for 循环里边判断是否为回文 O(n），所以时间复杂度为 **O(n³）**。

空间复杂度：**O(1）**，常数个变量。



### 解法3 ：动态规划

![image-20200226152850486](https://tva1.sinaimg.cn/large/0082zybply1gc9u4gxgeyj30y10u045p.jpg)

```java
public String longestPalindrome(String s) {
    int length = s.length();
    boolean[][] P = new boolean[length][length];
    int maxLen = 0;
    String maxPal = "";
    for (int len = 1; len <= length; len++) 	//遍历所有的长度
        for (int start = 0; start < length; start++) {
            int end = start + len - 1;
            if (end >= length) 		//下标已经越界，结束本次循环
                break;
            P[start][end] = (len == 1 || len == 2 || P[start + 1][end - 1]) && s.charAt(start) == s.charAt(end); //长度为 1 和 2 的单独判断下
            if (P[start][end] && len > maxLen) {
                maxPal = s.substring(start, end + 1);
            }
        }
    return maxPal;
}
```



### 解法4：扩展中心法

我们知道回文串一定是对称的，所以我们可以每次循环选择一个中心，进行左右扩展，判断左右字符是否相等即可。由于存在奇数的字符串和偶数的字符串，所以我们需要从一个字符开始扩展，或者从两个字符之间开始扩展，所以总共有 `n+n-1` 个中心。

![image-20200226153038312](https://tva1.sinaimg.cn/large/0082zybply1gc9u691vloj30mk0cgwi8.jpg)

```java
/**
 * 中心扩展算法 我们观察到回文中心的两侧互为镜像 因此，回文可以从它的中心展开，并且只有2n−1个这样的中心
 * 
 * @param s
 * @return 最长回文串
 */
public String longestPalindrome(String s) {
  if (s == null || s.length() < 1) {
    return "";
  }
  int start = 0, end = 0;
  for (int i = 0; i < s.length(); i++) {
    // 针对回文串是奇数的情况
    int len1 = expandAroundCenter(s, i, i);
    // 针对回文串是偶数的情况
    int len2 = expandAroundCenter(s, i, i + 1);
    int len = Math.max(len1, len2);
    if (len > end - start) {
      // 屏蔽了len1和len2的情况，根据取整规则把start统一处理一下
      start = i - (len - 1) / 2;
      end = i + len / 2;
    }
  }
  return s.substring(start, end + 1);
}

/**
 * 
 * @param s
 * @param left
 * @param right
 * @return 每一次通过中心判定法得到的回文串长度
 */
private int expandAroundCenter(String s, int left, int right) {
  int L = left, R = right;
  while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
    L--;
    R++;
  }
  // 当完成上面while循环的时候，L和R的位置分别处于正好匹配的下一个，所以是(R-1)-(L+1)+1
  return R - L - 1;
}
```

