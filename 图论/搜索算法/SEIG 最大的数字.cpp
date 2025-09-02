/**
* 给定正整数，可以对其任意位数进行以下操作
* 1.将数字+1，若果数字的是9，则变成0
* 2.将数字-1，若果数字的是0，则变成9
* 1操作可以进行A次，2操作可以进行B次,正整数不超过10^17
*/

#include <bis/stdc++.h>
using namespace std;

string s;
long long ans
int A,B;

void dfs(int i,long long v){
    int d = s[i]-'0';
    if(s[i]){
        int t=min(A,9-d);       // t最大为9
        A -= t;       
        dfs(i+1,v*10+d+t);      //这一位最大是x+t,v*10+d+t是到这一位的最大值
        A += t;                 //【恢复现场】
        if(B>d){
            B -= d+1;           //做 d+1次，因为0也要算一次
            dfs(i+1,v*10+9);
            B + =d+1;           //【恢复现场】
        }
    }
    else ans = max(ans,v);
}

int main(){
    cin>>s>>A>>B;
    dfs(0,0);
    cout<<ans;
    return 0;
}