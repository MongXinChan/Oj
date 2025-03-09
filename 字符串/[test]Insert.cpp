#include <iostream>
#include <string>

int main() {
    std::string s = "Hello";
    // bug修复：将字符串字面量 "a" 替换为字符 'a'
    s.insert(2, 3, 'a');  // 在索引2的位置插入3个字符 'a'
    std::cout << s << std::endl;  // 输出：Heaaallo
    return 0;
}