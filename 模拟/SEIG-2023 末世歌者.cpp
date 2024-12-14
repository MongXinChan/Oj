#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// 将特征数转换为奇偶性表示
string conv(string s) {
    string a;
    for (char c : s) {
        int digit = c - '0';
        a += (digit % 2 == 0) ? '0' : '1';
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    vector<string> stringb(n);
    unordered_map<string, int> Count;

    for (int i = 0; i < n; ++i) {
        cin >> stringb[i];
        string parity = conv(stringb[i]);
        Count[parity]++;
    }

    long long COUNT = 0;
    for (const auto& entry : Count) {
        string parity = entry.first;
        
        string complement;
        for (char c : parity) {
            complement += (c == '0') ? '1' : '0';
        }
        
        COUNT += (long long)entry.second * Count[complement];
    }

    
    cout << COUNT / 2 << endl;

    return 0;
}