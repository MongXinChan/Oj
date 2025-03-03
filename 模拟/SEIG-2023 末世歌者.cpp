#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// 定义一个函数 conv，用于将字符串转换为奇偶性表示
string conv(string s) {
    // 初始化一个空字符串 a，用于存储转换后的结果
    string a;
    // 遍历输入字符串 s 中的每个字符
    for (char c : s) {
        // 将字符转换为数字
        int digit = c - '0';
        // 判断数字是否为偶数
        if (digit % 2 == 0) {
            // 如果是偶数，在结果字符串 a 中添加字符 '0'
            a += '0';
        } else {
            // 如果是奇数，在结果字符串 a 中添加字符 '1'
            a += '1';
        }
    }
    // 返回转换后的字符串
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