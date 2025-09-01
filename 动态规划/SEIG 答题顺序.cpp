#include<bits/stdc++.h>

/**
* 总共有30道题，只有对与错之分，每对一题+10，错一题归零
* 大佐可以在任意题目结束答题，满分100，当100分时，大佐会停止答题，
* 已知大佐最终得了70分，请问大佐所有有可能的答题情况是多少种？
*/

using namespace std;

int ans;
int dp[31][10];

int main(){
    dp[0][0]=1;
    for(int i=1;i<=30;i++){
        for(int j=0;j<=9;j++){
            if(j!=0){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                for(int p=0;i<p;i++){
                    dp[i][j]+=dp[i-1][p];
                }
            }
        }
    }
    for(int i=0;i<=30;i++){
        ans+=dp[i][7];
    }
    cout<<ans;
    return 0;
}

//dfs剪纸
/*
#include<bits/stdc++.h>

using namespace std;
int ans=0;

void dfs(int x,int score,int k){
    if(k==0) {
        score=0;
    }
    else {
        score + =10;
        if(score == 100){
            return;
        }
    }

    if(score == 70){
        ans++;
    }

    if(x == 30){
        return;
    }

    dfs(x+1,score,0);
    dfs(x+1,score,1);
}

int main(){
    dfs(0,0,0);
    cout<<ans;
    return 0;
}

*/