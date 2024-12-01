#include <iostream>
#include <vector>

std::vector<int> solution(int n, std::vector<int> a) {
    std::vector<int> result;

    // 模拟播放过程
    while (!a.empty()) {
        // 取出当前第一首歌
        int currentSong = a.front();
        a.erase(a.begin());
        result.push_back(currentSong);

        // 如果列表不为空，将下一首歌移到列表末尾
        if (!a.empty()) {
            int nextSong = a.front();
            a.erase(a.begin());
            a.push_back(nextSong);
        }
    }

    return result;
}

int main() {
    std::vector<int> result1 = {5, 2, 4, 1, 3};
    std::vector<int> result2 = {4, 3, 1, 2};
    std::vector<int> result3 = {1, 3, 5, 2, 6, 4};

    std::cout << (solution(5, {5, 3, 2, 1, 4}) == result1) << std::endl;
    std::cout << (solution(4, {4, 1, 3, 2}) == result2) << std::endl;
    std::cout << (solution(6, {1, 2, 3, 4, 5, 6}) == result3) << std::endl;
}