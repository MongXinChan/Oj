#include<iostream>
#include<algorithm>
using namespace std;


int solution(int x, int y) {
    // 计算目标位置与起始位置的距离
    int dis = abs(x- y);
    
    // 如果距离为0，直接返回0步
    if (dis == 0) return 0;
    
    // 初始化步数
    int steps = 0;

        dis
    return steps;
}

int main() {
    // 你可以添加更多测试用例
    std::cout << (solution(12, 6) == 4) << std::endl;
    std::cout << (solution(34, 45) == 6) << std::endl;
    std::cout << (solution(50, 30) == 8) << std::endl;
    return 0;
}