#include <queue>
#include <iostream>
#include <vector>
#include <limits.h>

int solution(int n, int k, const std::vector<int>& nums) {
    // 初始化一个变量来存储最小值
    int mins = INT_MAX;
    
    // 遍历数组，找到长度为 k 的子数组的最大和
    for (int i = 0; i <= n - k; ++i) {
        int sum = 0;
        for (int j = 0; j < k; ++j) {
            sum += nums[i + j];
        }
        // 更新最小值
        if (sum < mins) {
            mins = sum;
        }
    }
    
    return mins;
}

int main() {
    // Add your test cases here
    std::cout << (solution(5, 3, {2, 1, 3, -1, 4}) == 8) << std::endl;
    return 0;
}
