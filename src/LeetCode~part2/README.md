- [盛最多水的容器](#盛最多水的容器)    
  - [解法1：暴力法](#解法1暴力法)    
  - [解法2：双指针法](#解法2双指针法)
- [三数之和](#三数之和)    
  - [解法1：排序+双指针+Set](#解法1排序双指针set)    
  - [解法2：排序+双指针](#解法2排序双指针)

## 盛最多水的容器

```
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。
```



<img src="https://tva1.sinaimg.cn/large/0082zybply1gca3eb7xanj30og0fg3zy.jpg" alt="image-20200226204943958" style="zoom:50%;" />

### 解法1：暴力法

在这种情况下，我们将简单地考虑每对可能出现的线段组合并找出这些情况之下的最大面积。

```java
public class Solution {
    public int maxArea(int[] height) {
        int maxarea = 0;
        for (int i = 0; i < height.length; i++)
            for (int j = i + 1; j < height.length; j++)
                maxarea = Math.max(maxarea, Math.min(height[i], height[j]) * (j - i));
        return maxarea;
    }
}
```

### 解法2：双指针法

这种方法背后的思路在于，两线段之间形成的区域总是会受到其中较短那条长度的限制。此外，两线段距离越远，得到的面积就越大。

我们在由线段长度构成的数组中使用两个指针，一个放在开始，一个置于末尾。 此外，我们会使用变量 `maxarea` 来持续存储到目前为止所获得的最大面积。 在每一步中，我们会找出指针所指向的两条线段形成的区域，更新 `maxarea`，并将指向较短线段的指针向较长线段那端移动一步。

```java
public class Solution {
    public int maxArea(int[] height) {
        int maxarea = 0, l = 0, r = height.length - 1;
        while (l < r) {
            maxarea = Math.max(maxarea, Math.min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
}
```





## 三数之和

```
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```



### 解法1：排序+双指针+Set

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(nums);
        int i = 0, j = nums.length - 1;
        while (i < j) {
            Set<Integer> set = new HashSet<>();
            for (int m = i + 1; m < j; m++) {
                set.add(nums[m]);
            }
            if (set.contains(-nums[i] - nums[j])) {
                List<Integer> list2 = new ArrayList<>();
                list2.add(nums[i]);
                list2.add(-(nums[i] + nums[j]));
                list2.add(nums[j]);
                list.add(list2);
            }
            if (Math.abs(nums[i]) > Math.abs(nums[j])) {
                i++;
            } else
            {
                j--;
            }
        }
        return list;
    }
}
```

在这个解法当中，我们没有解决数据重复出现的问题，要消除重复，则要令选捷径




### 解法2：排序+双指针

```java
class Solution {
    public static List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList();
        int len = nums.length;
        if(nums == null || len < 3) return ans;
        Arrays.sort(nums); // 排序
        for (int i = 0; i < len ; i++) {
            if(nums[i] > 0) break; // 如果当前数字大于0，则三数之和一定大于0，所以结束循环
            if(i > 0 && nums[i] == nums[i-1]) continue; // 去重
            int L = i+1;
            int R = len-1;
            while(L < R){
                int sum = nums[i] + nums[L] + nums[R];
                if(sum == 0){
                    ans.add(Arrays.asList(nums[i],nums[L],nums[R]));
                    while (L<R && nums[L] == nums[L+1]) L++; // 去重
                    while (L<R && nums[R] == nums[R-1]) R--; // 去重
                    L++;
                    R--;
                }
                else if (sum < 0) L++;
                else if (sum > 0) R--;
            }
        }        
        return ans;
    }
}
```

- 首先对数组进行排序，排序后固定一个数 `nums[i]`，再使用左右指针指向 
- `nums[i]`后面的两端，数字分别为 `nums[L]` 和 `nums[R]`
- 计算三个数的和 `sum` 判断是否满足为 0，满足则添加进结果集
- 如果 `nums[i]`大于 0，则三数之和必然无法等于 0，结束循环
- 如果` nums[i] == nums[i−1]`，则说明该数字重复，会导致结果重复，所以应该跳过
- 当 `sum == 0 `时，`nums[L] == nums[L+1]` 则会导致结果重复，应该跳过，`L++`
- 当 `sum == 0`时，`nums[R] == nums[R−1]` 则会导致结果重复，应该跳过，`R−−`
- 时间复杂度：**O(n<sup>2</sup> )**

