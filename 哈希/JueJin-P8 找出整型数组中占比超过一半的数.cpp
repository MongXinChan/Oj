#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    // 找到数组中的最大值和最小值，确定模拟哈希表的大小
    int maxNum = -2147483647-1;
    int minNum = 2147483647;
    for (int num : array) {
        if (num > maxNum) maxNum = num;
        if (num < minNum) minNum = num;
    }

    // 创建模拟哈希表
    int hashSize = maxNum - minNum + 1;
    vector<int> countMap(hashSize, 0);

    // 遍历数组中的每一个数字，更新模拟哈希表
    for (int num : array) {
        countMap[num - minNum]++;
    }

    // 遍历模拟哈希表，找到出现次数超过一半的数字
    int halfSize = array.size() / 2;
    for (int i = 0; i < hashSize; ++i) {
        if (countMap[i] > halfSize) {
            return i + minNum;
        }
    }

    // 如果没有找到符合条件的数字，返回一个默认值（题目保证一定存在这样的数字）
    return -1;
}

int main() {
    // 添加你的测试用例
    cout << (solution({1, 3, 8, 2, 3, 1, 3, 3, 3}) == 3) << endl;
    cout << (solution({5, 5, 5, 1, 2, 5, 5}) == 5) << endl;
    cout << (solution({9, 9, 9, 9, 8, 9, 8, 8}) == 9) << endl;

    return 0;
}