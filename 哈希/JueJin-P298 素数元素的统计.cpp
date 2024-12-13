#include <iostream>
#include <vector>
using namespace std;
//说一下自己的多余之举:一开始定义了一个结构体数组来存储是否为素数
//然后遍历数组，判断是否为素数。我发现直接用judge&&逻辑嵌套就行了

const int MAX_NUM = 100000; // 假设数组中最大的数字不超过100000

bool judge(int n) {
    if (n <= 1) return false; // 0,1 不是素数
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(vector<int> a) {
    int countMap[MAX_NUM] = {0}; // 使用数组模拟哈希表
    int cn = 0;

    // 统计每个数字的出现次数
    for (int num : a) {
        countMap[num]++;
    }

    // 判断每个数字及其出现次数是否满足条件
    for (int num : a) {
        if (countMap[num] > 0 && judge(num) && judge(countMap[num])) {
            cn++;
            countMap[num] = 0; // 避免重复计数
        }
    }

    return cn;
}

int main() {
    vector<int> test1 = {1, 2, 3, 2, 5, 7, 7, 7, 5};
    vector<int> test2 = {1, 4, 6, 8, 10, 12};
    vector<int> test3 = {3, 3, 3, 5, 5, 5, 5};

    cout << (solution(test1) == 3) << endl;
    cout << (solution(test2) == 0) << endl;
    cout << (solution(test3) == 1) << endl;

    return 0;
}