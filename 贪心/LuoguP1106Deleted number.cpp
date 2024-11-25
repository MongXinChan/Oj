#include<bits/stdc++.h>
#define MAXN 256

int main(){
    std::string s;
    int t;
    std::cin>>s>>t;
    s.push_back(-1);                // 在字符串 s 的末尾添加一个特殊字符 -1，用于标记字符串的结束
    while(t--){
        for(int i=0;i<s.size();++i){
            if(s[i]>s[i+1]){
                s.erase(i,1);
                break;
            }
        }
    }
    s.erase(s.end()-1);             //删除字符串末尾的特殊字符 -1
    while(s[0]=='0'&&s.size()>1)    // 如果字符串的首字符为 0，且字符串长度大于 1
        s.erase(s.begin());         // 删除字符串的首字符
    std::cout<<s<<std::endl;
    return 0;
}