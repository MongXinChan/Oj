#include <string>
#include <iostream>

std::string solution(const std::string& s) {
    // std::string a=s; ��һ����Ҫ����һ��
    //����Ƿ��п��ַ���
    if(s=="0"){
        return 0;
    }
    //ע�⵽����2Ҫʡȥ��Ч0;
    std::string method_push0=s;
    while(method_push0.size()>1&&method_push0[0]=='0'){
        method_push0.erase(0,1);
    }
    //��ѯС���������
    int flag=0;
    if(method_push0.find('.',0)!=0){
        flag=method_push0.find('.');
    }
    int pre_pos=0;
    if(flag!=0) pre_pos=flag;//����-1��ԭ����string�±��0��ʼ,��������ȥ֪����ô����,��
    int back_pos=0;
    if(flag!=0)int back_pos=method_push0.length()-flag-1;//-1��ԭ����
    int first_insert_pos=-1;
    int MaxCount=0;
    if(pre_pos>3){//ȷ���Ƿ�����ַ���>3��
    //���ɺܼ򵥣���һ�������λ�ÿ϶��ǵ�һ����,��,����ҲҪȷ�����Ƿ���ǰ�õ�����λ������3
    //���һ�Ҫ֪���ܹ��ż���
        first_insert_pos=(pre_pos-1)%3+1;//���������⣬����PRE_POSȥ��1�������ڽ��+1
        MaxCount=(pre_pos-1)/3;
    }
    if(first_insert_pos!=-1){
        for(int i=0;i<MaxCount;++i){
            method_push0.insert(first_insert_pos,1,',');
            first_insert_pos+=4;
        }
    }
    //����������string���±�0��ʼ����ô��Ҳ����+1;
    return method_push0;
}

int main() {
    std::cout << (solution("1294512.12412") == "1,294,512.12412") << std::endl;
    std::cout << (solution("0000123456789.99") == "123,456,789.99") << std::endl;
    std::cout << (solution("987654321") == "987,654,321") << std::endl;
}
