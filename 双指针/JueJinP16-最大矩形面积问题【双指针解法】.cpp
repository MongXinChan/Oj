#include <iostream>
#include <vector>

int solution(int n, std::vector<int> A) {
    int max_area = 0;
    int left = 0;
    int right = 0;
    int min_height = A[0];

    while (right < n) {
        // 更新最小高度
        min_height = std::min(min_height, A[right]);

        // 计算当前子数组的矩形面积
        int current_area = (right - left + 1) * min_height;
        max_area = std::max(max_area, current_area);

        // 如果右指针指向的高度小于当前最小高度，移动左指针
        if (A[right] < min_height) {
            left = right;
            min_height = A[right];
        }

        // 移动右指针
        right++;
    }

    return max_area;
}

int main() {
    // Add your test cases here
    std::vector<int> A_case1 = std::vector<int>{1, 2, 3, 4, 5};
    std::cout << (solution(5, A_case1) == 9) << std::endl;
    return 0;
}