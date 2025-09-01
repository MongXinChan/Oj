# include<bits/stdc++.h>

using namespace std;

int n,k,cnt=0;

void dfs(int x,int sum,int u){
    //上次分的数x,已经分的数u,前面u-1的和为sum
    if(u == k){
        if(sum == n)cnt++;
        return;
    }

    if(sum > n){
        return;
    }


    for(int i=x;sum+i*(k-u)<=n;i++){//剪纸，i的最大值不超过(n-sum)/(k-u)
        dfs(i,sum+i,u+1);
    }
}

int main(){
    cin>>n>>k;
    dfs(1,0,0);
    cout<<cnt<<endl;
    return 0;
    
}