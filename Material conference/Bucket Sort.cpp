#include <iostream>
#include <vector>
#include <algorithm> // for std::sort

// 桶排序函数
void bucket_Sort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    // 1. 找到数组中的最大值，用于确定桶的范围
    int max_val = *std::max_element(arr.begin(), arr.end());
    
    // 假设桶的数量为数组长度，这是一个常见的简单做法
    int bucket_count = arr.size();
    
    // 2. 创建桶
    std::vector<std::vector<int>> buckets(bucket_count);

    // 3. 分配元素到对应的桶中
    // 使用线性映射将元素值映射到桶索引
    for (int num : arr) {
        int bucket_index = (double)num / max_val * (bucket_count - 1);
        buckets[bucket_index].push_back(num);
    }
    
    // 4. 对每个桶内的元素进行排序
    // 这里使用 std::sort，它通常是 IntroSort（结合了快排、堆排和插入排序）
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
    }

    // 5. 收集结果
    int index = 0;
    for (const auto& bucket : buckets) {
        for (int num : bucket) {
            arr[index++] = num;
        }
    }
}

int main() {
    std::vector<int> arr = {0, 10, 5, 8, 2, 7, 3, 1, 9, 6, 4};
    
    std::cout << "原始数组: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    bucketSort(arr);

    std::cout << "排序后数组: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

/**
 *
 *
 * 桶排序（Bucket Sort）是一种基于分布的排序算法，适用于均匀分布的数据。它的基本思想是将数据分到有限数量的桶中，
 * 然后对每个桶内的数据进行排序，最后再将各个桶中的数据合并起来得到有序序列。
 */