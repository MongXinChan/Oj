#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Minister {
    long long a;
    long long b;
};

bool compare(const Minister &x, const Minister &y) {
    // 贪心策略：按 a/(a+b) 降序排列
    return x.a * (x.a + y.b) > y.a * (x.b + y.a);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Minister> ministers(n);
        for (int i = 0; i < n; ++i) {
            cin >> ministers[i].a >> ministers[i].b;
        }
        // 按贪心策略排序
        sort(ministers.begin(), ministers.end(), compare);
        long long max_bonus = 0;
        long long current_sum = 0;
        long long prev_bonus = 0;
        for (const Minister &minister : ministers) {
            current_sum += minister.a;
            long long current_bonus = max(prev_bonus, current_sum) + minister.b;
            max_bonus = max(max_bonus, current_bonus);
            prev_bonus = current_bonus;
        }
        cout << max_bonus << endl;
    }
    return 0;
}