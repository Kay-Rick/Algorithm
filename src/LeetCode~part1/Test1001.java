/*
 * @Author: Rick
 * @Email: Kay_Rick@outlook.com
 * @Github: https://github.com/Kay-Rick
 * @Date: 2020-02-15 00:21:56
 * @LastEditors: Rick
 * @LastEditTime: 2020-02-26 15:39:51
 * @FilePath: /LeetCode/Users/rick/Desktop/GitHub_Reposity/Algorithm/src/LeetCode~part1/Test1001.java
 * @Description: Description
 */
import java.util.HashMap;
import java.util.Map;

/**
 * @Author: Rick
 * @Date: 2019/12/7 18:57
 * @Description:
 */
public class Test1001 {

    /**
     * 暴力求解： 时间复杂度较高
     * @param nums
     * @param target
     * @return
     */
    public static int[] twoSum1(int[] nums, int target){
        int [] arr = new int[2];

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] == target - nums[i])
                    return new int[] {i , j};
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }

    /**
     * 利用HashMap散列查找,以空间来换时间
     * @param nums
     * @param target
     * @return
     */
    public static int[] twoSum2(int[] nums, int target){
        Map<Integer,Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i],i);
        }

        for (int i = 0; i < nums.length; i++) {
            int temp = target - nums[i];
            if (map.containsKey(temp) && map.get(temp) != i)
                return new int[]{i,map.get(temp)};
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
