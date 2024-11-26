#include <vector>
#include <iostream>

// 找出数组中只出现一次的两个数字
std::pair<int, int> findSingleNumbers(const std::vector<int>& nums) {
    int p = 0;
    // 第一次遍历，计算所有数字的异或结果
    for (int num : nums) {
        p ^= num;
    }

    // 找到异或结果中最低的1位
    int rightmost_set_bit = p & (-rightmost_set_bit);

    int num1 = 0, num2 = 0;
    // 第二次遍历，根据最低位是0还是1，将数组分为两组，分别计算异或结果
    for (int num : nums) {
        if (num & rightmost_set_bit) {
            num1 ^= num;
        } else {
            num2 ^= num;
        }
    }

    return {num1, num2};
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 1, 2, 3, 4, 6};
    auto [num1, num2] = findSingleNumbers(nums);

    std::cout << "The two numbers that appear only once are: " << num1 << " and " << num2 << std::endl;
    return 0;
}
