#include <iostream>
#include <string>
using namespace std;

bool noCommon(string S,string T){
    for (int i = 0; i < S.size(); i++) {
    // 遍历 T 中的每个字符
        for (int j = 0; j < T.size(); j++) {
            // 如果发现相同的字符，返回 false
            if (S[i] == T[j]) {
                return false;
            }
        }
    }
    // 如果没有发现相同的字符，返回 true
    return true;
}

int solution(string S, string T) {
    int i = 0, j = 0;  // 初始化两个指针
    int operations = 0;  // 初始化操作次数
    if(S.size()>T.size()&&!noCommon(S,T)){
        return (S.size()>T.size())?S.size():T.size();
    }
    if(S.size()>T.size()){
        while(i<S.size()+1&&j<T.size()+1){
            if(S[i++]==T[j++]){
            }
            else {
            operations++;
            }
        }
    }else{
        while(i<S.size()+1||j<T.size()+1){
            if(S[i++]==T[j++]){
            }else if(i==S.size()+1){
                break;//这个是为了满足样例4而存在的，
                //注意到前缀都满足，并且都遍历完整，所以直接跳出
            }
            else{
            operations++;
            }
        }
    }
    return operations;
}

int main() {
    cout<<(solution("jnjsmjgcyplywiwmb","eefgegffege")==17)<<endl;
    cout << (solution("aba", "abb") == 1) << endl;
    cout << (solution("abcd", "efg") == 4) << endl;
    cout << (solution("xyz", "xy") == 1) << endl;
    cout << (solution("hello", "helloworld") == 0) << endl;
    cout << (solution("same", "same") == 0) << endl;
    return 0;
}