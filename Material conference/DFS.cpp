#include <iostream>

using namespace std;


auto dfs = [](auto&& self, int u, int parent, const vector<vector<int>>& adj, vector<bool>& visited) -> void {
    visited[u] = true;
    cout << "Visiting node: " << u << endl;

    for (int v : adj[u]) {
        if (v != parent && !visited[v]) {
            self(self, v, u, adj, visited);
        }
    }
};