#include <iostream>
#include <string>

std::string solution(const std::string& s) {
    std::string result=s;
    int t=s.length();
    int pos=0;
    while ((pos = result.find('a', pos)) != std::string::npos){
        result.replace(pos,1,"%100");
        pos+=4;
    }
    return result; // Placeholder
}

int main() {
    std::cout << (solution("abcdwa") ) << std::endl;
    std::cout << (solution("banana") ) << std::endl;
    std::cout << (solution("apple")) << std::endl;
    return 0;
}