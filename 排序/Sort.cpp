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
using namespace std;


/**
 * @brief 冒泡排序(从小到大) 平均时间复杂度O(n^2),空间复杂度O(1),稳定排序
 * @param array 
 * @param n 
 */
void bullleSort (int array[], int n) {
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
        // 从后往前找到空位
        for (;j > 0 && array[j - 1] > temp; j--) {
            array[j] = array[j - 1];
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
            j = i - d;
            // 查找插入的位置，这里j>=0放在前面，短路运算会直接跳出循环
            while (j >= 0 && array[j] > temp) {
                array[j + d] = array[j];
                j -= d;
            }
            // 插入排序
            array[j + d] = temp;
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
    // 将排好序的存回array中low到high这区间
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
void mSort (int array[], int temp [],int start, int end) {
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
 * @brief 选择快速排序的基准
 * @param array 
 * @param left 
 * @param right 
 * @return int 
 */
int selectPivot(int array[], int left, int right) {
    int center = (left + right) / 2;
    // 进行排列使 array[left] <= array[center] <= array[right]
    if (array[left] > array[center])
        swap(array[left], array[center]);
    if (array[left] > array[right])
        swap(array[left], array[right]);
    if (array[center] > array[right])
        swap(array[center], array[right]);
    //  将基准pivot藏到右边
    swap(array[center], array[right - 1]);
    // 只需要考虑array[left + 1] … array[right - 2]
    return array[right - 1];
}
/**
 * @brief 快速排序核心递归函数
 * @param array 
 * @param left 
 * @param right 
 */
void qSort (int array[], int left, int right) {
    int pivot = selectPivot(array, left, right);
    int low = left, high = right - 1;
    // 将序列中比基准小的移到基准左边，大的移到右边
    while (true) {
        while (array[++low] < array[pivot]);
        while (array[--high] > array[pivot]);
        if (low < high)
            swap(array[low], array[high]);
        else
            break;        
    }
    // 将 pivot 换到正确的位置
    swap(array[low], array[right - 1]);
    qSort(array, left, low - 1);
    qSort(array, low + 1, right);
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
 * @brief 向下过滤，将N个元素的数组中以A[p]为根的子堆调整为最大堆
 * @param A 
 * @param p 
 * @param N 
 */
void PercDown(int A[], int p, int N) {
    int Parent, Child;
    int X;

    X = A[p]; /* 取出根结点存放的值 */
    for (Parent = p; (Parent * 2 + 1) < N; Parent = Child) {
        Child = Parent * 2 + 1; // 从0开始，不同之前堆是从1开始
        if ((Child != N - 1) && (A[Child] < A[Child + 1]))
            Child++; /* Child指向左右子结点的较大者 */
        if (X >= A[Child])
            break; /* 找到了合适位置 */
        else       /* 下滤X */
            A[Parent] = A[Child];
    }
    A[Parent] = X;
}

/**
 * @brief 堆排序
 * @param A 
 * @param N 
 */
void HeapSort(int A[], int N) {
    int i;
    for (i = N / 2; i >= 0; i--) /* 建立最大堆 */
        PercDown(A, i, N);
    for (i = N - 1; i > 0; i--) {
        /* 删除最大堆顶 */
        swap(A[0], A[i]);
        PercDown(A, 0, i);
    }
}

