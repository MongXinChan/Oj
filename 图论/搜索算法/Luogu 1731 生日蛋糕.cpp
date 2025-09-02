#include <bits/stdc++.h>

using namespace std;

const int INF =0x3f3f3f3f;

int ans = INF;

int min_s[21],min_v[21],n,m;

// 当前层高，半径，高度，黑色上表面总面积，体积
void dfs(int k,int r,int h,int s,int v){
    int MAX_h = h;

    if(k==0){                       //递归边界
        if(v == n) ans=min(s,ans);      //正好用完材料
        return;
    }

    if(v + min_v[k] > n)  return; // 体积超出
    if(s + min_s[k] >= ans) return; // 面积下界超出
    if(2*(n-v)/r+s>=ans) return;  // 侧面积下界超出


    for(int i=r-1;i>=k;i--){
        if(i==0) continue;

        MAX_h = min(h-1,(n-min_v[k-1]-v)/(i*i));
        for(int j=MAX_h;j>=k;j--){
            int next_s = s + 2*i*j;
            if(k==m) next_s+= i*i;
            dfs(k-1,i,j,next_s,v+i*i*j);
        }
    }

}

int main(){
    cin>>n>>m;                          //目标层数
    for(int i=1;i<=m;i++){              //
        min_s[i]=min_s[i-1]+2*i*i;            //1~i侧层面积最小值
        min_v[i]=min_v[i-1]+i*i*i;            //1~i层体积最小值
    }

    dfs(m,n,n,0,0);                 //从第m层开始搜索
    if(ans==INF) ans=0;
    cout<<ans<<endl;
    return 0;
}