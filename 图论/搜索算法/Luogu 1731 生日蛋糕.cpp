#include <bits/stdc++.h>

using namespace std;

const int INF =0x3f3f3f3f;

int ans = INF;

int sk[20],vk[20],n,m;

void dfs(int k,int r,int h,int s,int v){
    int MAX_h = h;

    if(k==0) {
        if(v == n){                 //找到一个解
            ans = min(ans,s);       //更新答案
            return;
        }
    }

    if(v+vk[k-1]>n){
        return ;//剪纸
    }

    if(2*(n-v)/r+s>=ans){
        return ;//剪纸
    }

    for(int i=r-1;i>=k;i--){
        if(k==m){
            s=i*i;
        }
        MAX_h=min(h-1,(n-vk[k-1]-v)/i/i);//第k-1层最高的高度
        for(int j=MAX_h;j>=k;j--){
            dfs(k-1,i,j,s+2*i*j,v+i*i*j);
        }
    }

}

int main(){
    cin>>n>>m;                          //目标层数
    for(int i=1;i<=m;i++){              //
        sk[i]=sk[i-1]+2*i*i;            //1~i侧层面积最小值
        vk[i]=vk[i-1]+i*i*i;            //1~i层体积最小值
    }

    dfs(m,n,n,0,0);                 //从第m层开始搜索
    if(ans==INF) ans=0;
    cout<<ans<<endl;
    return 0;
}