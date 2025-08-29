#include <vector>

class DisjointSet {
private:
    std::vector<int> parent;

public:
    DisjointSet(int size) {
        parent.resize(size);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        return x == parent[x] ? x : find(parent[x]);
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};