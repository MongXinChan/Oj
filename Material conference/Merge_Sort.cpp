#include <iostream>

using namespace std;

#include <vector>

// 合并（Merge）函数：将两个有序子数组合并成一个有序数组
void Merge(std::vector<int>& arr, int L, int mid, int R) {
    // 辅助数组，用于存放合并后的元素
    std::vector<int> temp(R - L + 1);
    
    int i = L;      // 第一个子数组的起始指针
    int j = mid + 1;  // 第二个子数组的起始指针
    int k = 0;      // 辅助数组的写入指针

    // 比较两个子数组的元素，将较小的放入辅助数组
    while (i <= mid && j <= R) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // 将第一个子数组中剩余的元素复制到辅助数组
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // 将第二个子数组中剩余的元素复制到辅助数组
    while (j <= R) {
        temp[k++] = arr[j++];
    }

    // 将辅助数组中的元素复制回原数组的相应位置
    for (int p = 0; p < temp.size(); p++) {
        arr[L + p] = temp[p];
    }
}

// 归并排序（Merge Sort）函数：递归地分解数组并调用 Merge 函数进行合并
void Merge_Sort(std::vector<int>& arr, int L, int R) {
    // 递归终止条件：当子数组只剩下一个元素时，它自然有序
    if (L >= R) {
        return;
    }

    // 找到中间位置，将数组一分为二
    int mid = L + (R - L) / 2;

    // 递归地对左半部分进行排序
    Merge_Sort(arr, L, mid);

    // 递归地对右半部分进行排序
    Merge_Sort(arr, mid + 1, R);

    // 将两个已排序的子数组合并
    Merge(arr, L, mid, R);
}