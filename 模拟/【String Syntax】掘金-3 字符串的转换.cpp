#include <string>
#include <iostream>

std::string solution(const std::string& s) {
    // std::string a=s; 不一定都要有这一步
    //检查是否含有空字符串
    if(s=="0"){
        return 0;
    }
    //注意到样例2要省去无效0;
    std::string method_push0=s;
    while(method_push0.size()>1&&method_push0[0]=='0'){
        method_push0.erase(0,1);
    }
    //查询小数点的有无
    int flag=0;
    if(method_push0.find('.',0)!=0){
        flag=method_push0.find('.');
    }
    int pre_pos=0;
    if(flag!=0) pre_pos=flag;//不用-1的原因是string下标从0开始,便于我们去知道怎么给‘,’
    int back_pos=0;
    if(flag!=0)int back_pos=method_push0.length()-flag-1;//-1的原因是
    int first_insert_pos=-1;
    int MaxCount=0;
    if(pre_pos>3){//确定是否这个字符段>3。
    //理由很简单，第一个插入的位置肯定是第一个‘,’,但是也要确保其是否其前置的数字位数大于3
    //而且还要知道总共放几次
        first_insert_pos=(pre_pos-1)%3+1;//这里有问题，少了PRE_POS去减1，并且在结果+1
        MaxCount=(pre_pos-1)/3;
    }
    if(first_insert_pos!=-1){
        for(int i=0;i<MaxCount;++i){
            method_push0.insert(first_insert_pos,1,',');
            first_insert_pos+=4;
        }
    }
    //，而且由于string从下标0开始，那么倒也不用+1;
    return method_push0;
}

int main() {
    std::cout << (solution("1294512.12412") == "1,294,512.12412") << std::endl;
    std::cout << (solution("0000123456789.99") == "123,456,789.99") << std::endl;
    std::cout << (solution("987654321") == "987,654,321") << std::endl;
}
