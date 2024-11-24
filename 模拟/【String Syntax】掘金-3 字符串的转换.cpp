#include <string>
#include <iostream>

std::string solution(const std::string& s) {
    // ����Ƿ��п��ַ���
    if (s == "0") {
        return "0";
    }
    
    // ȥ����Ч��ǰ��0
    std::string method_push0 = s;
    while (method_push0.size() > 1 && method_push0[0] == '0') {
        method_push0.erase(0, 1);
    }
    
    // ��ѯС���������
    int flag = method_push0.find('.');
    int pre_pos = (flag == std::string::npos) ? method_push0.length() : flag;
    
    // �����һ������λ�úͲ������
    int first_insert_pos = pre_pos % 3;
    if (first_insert_pos == 0) {
        first_insert_pos = 3;
    }
    int MaxCount = (pre_pos - 1) / 3;
    
    // ���붺��
    for (int i = 0; i < MaxCount; ++i) {
        method_push0.insert(first_insert_pos, ",");
        first_insert_pos += 4;
    }
    
    return method_push0;
}

int main() {
    std::cout << (solution("1294512.12412") == "1,294,512.12412") << std::endl;
    std::cout << (solution("0000123456789.99") == "123,456,789.99") << std::endl;
    std::cout << (solution("987654321") == "987,654,321") << std::endl;
}
