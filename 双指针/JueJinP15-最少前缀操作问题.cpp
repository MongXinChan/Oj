#include <iostream>
#include <string>
using namespace std;

int solution(string S, string T) {
    int i = 0, j = 0;  // 初始化两个指针
    int operations = 0;  // 初始化操作次数
    if(S.size()>T.size()){
        while(i<S.size()+1&&j<T.size()+1){
            if(S[i++]==T[j++]){
            }else {
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
    cout << (solution("aba", "abb") == 1) << endl;
    cout << (solution("abcd", "efg") == 4) << endl;
    cout << (solution("xyz", "xy") == 1) << endl;
    cout << (solution("hello", "helloworld") == 0) << endl;
    cout << (solution("same", "same") == 0) << endl;
    return 0;
}