#include <iostream>
#include <vector>
#include <algorithm> // for std::max_element

// 计数排序函数
// 输入:
//   input: 待排序的向量
// 输出:
//   一个包含排序后元素的新的向量
std::vector<int> counting_sort(const std::vector<int>& input) {
    if (input.empty()) {
        return {}; // 如果输入为空，返回一个空向量
    }

    // 1. 找到输入向量中的最大值
    int max_val = *std::max_element(input.begin(), input.end());

    // 2. 创建计数数组，并统计每个元素的出现次数
    // 数组大小为 max_val + 1，初始化为0
    std::vector<int> count(max_val + 1, 0);
    for (int num : input) {
        count[num]++;
    }

    // 3. 将计数数组转换为累积计数数组
    for (size_t i = 1; i < count.size(); ++i) {
        count[i] += count[i - 1];
    }

    // 4. 创建输出数组，并根据累积计数数组将元素放回正确位置
    std::vector<int> output(input.size());
    for (int i = input.size() - 1; i >= 0; --i) {
        int current_val = input[i];
        int position = count[current_val] - 1;
        output[position] = current_val;
        count[current_val]--; // 将该元素的计数减一
    }

    return output;
}

int main() {
    std::vector<int> numbers = {4, 2, 2, 8, 3, 3, 1};
    std::vector<int> sorted_numbers = counting_sort(numbers);

    // 打印排序结果
    std::cout << "Sorted array: ";
    for (int num : sorted_numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}