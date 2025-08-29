#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 0; i < n; i++) {
        int MIN = min({a[i], b[i], c[i]});
        cout << 3 * MIN << endl;
    }
    return 0;
}