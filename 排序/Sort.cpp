/**
 * @file Sort.cpp
 * @author Rick (Kay_Rick@outlook.com)
 * @version 1.0
 * @date 2020-06-19 14:06:00
 * @brief 排序算法汇总
 * 
 * @copyright Copyright (c) 2020 Rick, All Rights Reserved.
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/**
 * @brief 冒泡排序(从小到大) 平均时间复杂度O(n^2),空间复杂度O(1),稳定排序
 * @param array 
 * @param n 
 */
void bubbleSort (int array[], int n) {
    // 开始进行遍历 ==>控制判断的次数
    for (int i = 0; i < n; i++) {
        bool flag = false;  // 记录有无数据交换
        // 内循环 ==> 相邻数字的比较和移动
        for (int j = 0; j < n - 1 - i; j++) {
            // j < n - 1 - i这里 -i 是因为后面已经排好
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}



/**
 * @brief 插入排序 ==> 类似手抓扑克牌进行排序 平均时间复杂度O(n^2),空间复杂度O(1),稳定排序
 * @param array 
 * @param n 
 */
void insertSort (int array[], int n) {
    for (int i = 1; i < n; i++) {
        // 记录当前扑克牌
        int temp = array[i];
        int j = i;
        // 在有序序列中从后往前找到空位
        while (j >= 1 && array[j - 1] > temp) {
            array[j] = array[j - 1];
            j--;
        }
        // 插入
        array[j] = temp;
    }
}



/**
 * @brief 选择排序 ==> 每次从无序序列中选择一个最小的放在有序序列中 
 *          平均时间复杂度O(n^2),空间复杂度O(1),非稳定排序
 * @param array 
 * @param n 
 */
void selectSort (int array[], int n) {
    // 进行 n - 1轮比较
    for (int i = 0;i < n - 1; i++) {
        int min = i;
        // 找最小的元素
        for (int j = i + 1; j < n; j++) {
            // 记录目前能找最小元素值的下标
            if (array[j] < array[min]) 
                min = j;
        }
        // 将找到的最小元素和i下标的最小元素进行交换
        if (i != min) {
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}



/**
 * @brief 希尔排序 ==> 增量序列+插入排序(插入排序的高效改进算法)
 *          平均时间复杂度O(nlog n) 空间复杂度 O(1) 非稳定排序
 * @param array 
 * @param n 
 */
void shellSort (int array[], int n) {
    int d = n / 2;
    int j, temp;
    // 引入增量 d
    while (d > 0) {
        // 每一趟相当于以 d 为步数的插入排序
        for (int i = d; i < n; i++) {
            temp = array[i];
            j = i;
            // 查找插入的位置，这里j>=0放在前面，短路运算会直接跳出循环
            while (j >= d && array[j - d] > temp) {
                array[j] = array[j - d];
                j -= d;
            }
            // 插入排序
            array[j] = temp;
        }
        d /= 2;
    }
}



/**
 * @brief 一次归并
 * @param array 一次需要归并的数组
 * @param temp 临时数组
 * @param start 数组起始位置
 * @param mid 数组中间位置
 * @param end 数组末尾位置
 */
void _merge(int array[], int temp[], int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = 0;
    // 归并操作
    while (i <= mid && j <= end) {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    while (i <= mid) 
        temp[k++] = array[i++];
    while (j <= end)
        temp[k++] = array[j++];
    // 将排好序的存回 array 中 start 到 end 这区间
    for (int i = start, k = 0; i <= end; i++, k++) {
        array[i] = temp[k];
    }
}
/**
 * @brief 归并排序核心递归函数 ==> 分类比武,不断进行归并 
 * @param array 
 * @param temp 
 * @param start 
 * @param end 
 */
void mSort (int array[], int temp[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mSort(array, temp, start, mid);
        mSort(array, temp, mid + 1, end);
        _merge(array, temp, start, mid, end);
    }
}
/**
 * @brief 归并排序 时间复杂度O(nlog n) 没有最坏和最差时间复杂度 空间复杂度O(n) 稳定排序算法
 * @param array 
 * @param n 
 */
void mergeSort (int array[], int n) {
    // 将temp数组声明在外部是为了防止在merge函数里面频繁申请释放空间带来的开销
    int* temp = new int[n];
    if (temp != NULL) {
        mSort(array, temp, 0, n - 1);
        delete []temp;
    }
}

/**
 * @brief 快速排序核心递归函数
 * @param array 
 * @param left 
 * @param right 
 */
void qSort (int array[], int left, int right) {
    if (left >= right)
        return;
    int pivot = array[left + right >> 1];
    // 指针都先从边界开始
    int low = left - 1, high = right + 1;
    // 将序列中比基准小的移到基准左边，大的移到右边
    while (low < high) {
        while (array[++low] < pivot);
        while (array[--high] > pivot);
        if (low < high)
            swap(array[low], array[high]);
    }
    qSort(array, left, high);
    qSort(array, high + 1, right);
}
/**
 * @brief 快速排序 ==> 时间复杂度O(nlog n), 空间复杂度O(log n)
 * @param array 
 * @param n 
 */
void quickSort (int array[], int n) {
    qSort(array, 0, n - 1);
}



/**
 * @brief 向下过滤，将N个元素的数组中以array[p]为根的子堆调整为最大堆
 * @param array 待过滤数组
 * @param p 根节点编号
 * @param N 数组长度
 */
void PercDown(int array[], int p, int N) {
    int parent, child;
    // 取出根结点存放的值
    int X = array[p];
    for (parent = p; (parent * 2 + 1) < N; parent = child) {
        // 从0开始，不同之前堆是从 1 开始
        child = parent * 2 + 1;
        // child指向左右子结点的较大者
        if ((child != N - 1) && (array[child] < array[child + 1]))
            child++;
        // 找到了合适位置，跳出循环
        if (X >= array[child])
            break; 
        else       /* 下滤X */
            array[parent] = array[child];
    }
    array[parent] = X;
}

/**
 * @brief 堆排序 时间复杂度 O(nlog n) 空间复杂度
 * @param array 待排序数组
 * @param N 数组长度
 */
void HeapSort(int array[], int N) {
    int i;
    // 从第一个非叶子节点开始，从右至左调整结构，建立最大堆
    for (i = N / 2; i >= 0; i--) 
        PercDown(array, i, N);
    // 调整堆结构 + 交换堆顶元素与末尾元素
    for (i = N - 1; i > 0; i--) {
        // 不断删除堆顶元素
        swap(array[0], array[i]);
        PercDown(array, 0, i);
    }
}

/**
 * @brief 桶排序：先知道序列中记录都位于某个小区间段[0, m]内
 *        将具有相同值的记录都分配到同一个桶中，然后依次按照编号从桶中取出记录，组成有序序列
 *        时间复杂度O(n + m) 空间复杂度O(n + m)，适用于m相对于n很小的情况
 * @param array 
 * @param n 
 */
// 桶的默认数量
int DEFAULT_BUCKET_SIZE = 5;
void bucketSort(int array[], int n) {
    if (n < 1)
        return;
    int max_element = array[0];
    int min_element = array[0];

    // 找出数组的最大值和最小值
    for (int i = 1; i < n; i++) {
        max_element = max(max_element, array[i]);
        min_element = min(min_element, array[i]);
    }
    int bucketSize = DEFAULT_BUCKET_SIZE;
    int bucketCount = ((max_element - min_element) / bucketSize) + 1;

    vector<vector<int> > buckets(bucketCount);
    vector<int> res;
    // 利用映射函数将数据分配到各个桶中
    for (int i = 0; i < n; i++)
        buckets[(array[i] - min_element) / bucketSize].push_back(array[i]);

    for (int i = 0; i < buckets.size(); i++) {
        // 每个桶内部进行排序
        sort(buckets[i].begin(), buckets[i].end());
        for (int j = 0; j < buckets[i].size(); j++)
            res.push_back(buckets[i][j]);
    }

    // 将vector中数据覆盖到原数组
    for (int i = 0; i < res.size(); i++)
        array[i] = res[i];
}

/**
 * @brief 计数排序
 * @param array 
 * @param n 
 */
void countSort(int array[], int n) {
    if (n < 1)
        return;
    // 1. 得到数组的最大值和最小值，算出差值
    int max_element = array[0];
    int min_element = array[0];
    for (int i = 1; i < n; i++) {
        max_element = max(max_element, array[i]);
        min_element = min(min_element, array[i]);
    }
    int d = max_element - min_element;
    // 2. 创建统计数组并计算统计对应元素个数
    int *count = new int[d + 1];
    for (int i = 0; i < n; i++)
        count[array[i] - min_element]++;
    // 3. 统计数组变形，后面的元素等于前面的元素之和 ==> 使排序稳定的一种策略
    for (int i = 1; i < d + 1; i++) 
        count[i] = count[i] + count[i - 1];

    // 4. 倒序遍历原始数组，从统计数组找到正确位置，输出到结果数组
    int *sortedArray = new int[n];
    for (int i = n - 1; i >= 0; i--) 
        sortedArray[--count[array[i] - min_element]] = array[i];

    for (int i = 0; i < n; i++)
        array[i] = sortedArray[i];
    delete[] sortedArray;
}


/**
 * @brief 获取数组array中数据最大位数
 * @param array 
 * @param n 
 * @return int 
 */
int maxbit(int array[], int n) {
    if (n < 1)
        return 0;
    int max_element = array[0];
    for (int i = 1; i < n; i++) 
        max_element = max(max_element, array[i]);
    int d = 0;
    while(max_element > 0) {
        max_element /= 10;
        d++;
    }
    return d;
}

/**
 * @brief 基数排序
 * @param array 
 * @param n 
 */
void radixSort(int array[], int n) {
    int d = maxbit(array, n);
    int* temp = new int[n];
    // 计数器
    int* count = new int[10];
    int radix = 1;
    // 进行d次排序
    for (int i = 0; i < d; i++) {
        // 每次分配前清空计数器
        for (int j = 0; j < 10; j++) 
            count[j] = 0;
        for (int j = 0; j < n; j++) {
            int k = (array[j] / radix) % 10;
            count[k]++;
        }
        // 将temp中位置依次分配给每个桶
        for (int j = 1; j < 10; j++)
            count[j] = count[j] + count[j - 1];
        // 将所有桶中记录依次收集到temp中
        for (int j = n - 1; j >= 0; j--) {
            int k = (array[j] / radix) % 10;
            temp[count[k] - 1] = array[j];
            count[k]--;
        }
        // 将临时数组的内容复制到原数组
        for (int j = 0; j < n; j++)
            array[j] = temp[j];
        
        radix *= 10;
    }
}