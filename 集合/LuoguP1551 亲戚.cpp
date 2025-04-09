#include <iostream>
#include <vector>
using namespace std;

vector<int> Father;

int Parent(int x) {
    if (Father[x] == -1) {
        return x; // 如果父节点是 -1，说明它是根节点
    }
    return Father[x] = Parent(Father[x]); // 路径压缩
}

int main() {
    int n, m, p, a, b;
    cin >> n >> m >> p;

    // 初始化 Father 数组，每个节点的父节点初始化为 -1
    Father.resize(n + 1, -1);

    // 处理 m 次合并操作
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        int rootA = Parent(a);
        int rootB = Parent(b);
        if (rootA != rootB) { // 如果两个根节点不同，合并它们
            Father[rootA] = rootB;
        }
    }

    // 处理 p 次查询操作
    for (int i = 1; i <= p; i++) {
        cin >> a >> b;
        if (Parent(a) == Parent(b)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}