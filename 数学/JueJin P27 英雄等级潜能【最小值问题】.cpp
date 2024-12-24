#include <iostream>
#include <vector>
#include <algorithm>
int solution(int n, std::vector<int> u) {
    int min_level = std::min(u.begin(), u.end());
    
    int cnt = 0;
    for (int level : u) {
        if (level != min_level) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    std::cout << (solution(5, {1, 2, 3, 1, 2}) == 3) << std::endl;
    std::cout << (solution(4, {100000, 100000, 100000, 100000}) == 0) << std::endl;
    std::cout << (solution(6, {1, 1, 1, 2, 2, 2}) == 3) << std::endl;
}