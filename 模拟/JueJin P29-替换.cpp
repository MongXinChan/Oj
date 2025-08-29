#include <iostream>
#include <string>
using namespace std;

string solution(string s, int k) {
   string r = s;
    for (int i = 0; i < k; ++i) {
        string newR = "";
        // 对当前字符串中的每个字符进行变换
        for (char c : r) {
            if (c == 'a') {
                newR += "bc";  // 将 'a' 变成 'bc'
            } else if (c == 'b') {
                newR += "ca";  // 将 'b' 变成 'ca'
            } else if (c == 'c') {
                newR += "ab";  // 将 'c' 变成 'ab'
            }
        }
        r = newR;  // 更新结果
    }
    return r;
}

int main() {
    cout << (solution("abc", 2) == "caababbcbcca") << endl;
    cout << (solution("abca", 3) == "abbcbccabccacaabcaababbcabbcbcca") << endl;
    cout << (solution("cba", 1) == "abcabc") << endl;
    return 0;
}