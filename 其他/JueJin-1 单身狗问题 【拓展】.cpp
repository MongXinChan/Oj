#include <vector>
#include <iostream>

// �ҳ�������ֻ����һ�ε���������
std::pair<int, int> findSingleNumbers(const std::vector<int>& nums) {
    int p = 0;
    // ��һ�α����������������ֵ������
    for (int num : nums) {
        p ^= num;
    }

    // �ҵ����������͵�1λ
    int rightmost_set_bit = p & (-rightmost_set_bit);

    int num1 = 0, num2 = 0;
    // �ڶ��α������������λ��0����1���������Ϊ���飬�ֱ���������
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
