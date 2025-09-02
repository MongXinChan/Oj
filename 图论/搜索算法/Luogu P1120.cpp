#include <iostream>

using namespace std;

const int N =0x4f;

int maxN=0,minN=0,Hash[N];

void dfs(int k,int len,int L,int p){
    //尝试拼出k根长度都为L的线段
    if(k==0){
        cout<<L;
        exit(0);
    }
    if(len == L){
        dfs(k-1,0,L,maxN);  //拼出一根线段，继续拼下一根
        return;
    }

    for(int i=p;i>=minN;i--){
        if(Hash[i]&&i+len<=L){  //i这根线段没有用过，并且加上len不超过L
            Hash[i]--;
            dfs(k,len+i,L,i);   //继续拼当前这根线段
            Hash[i]++;          //【恢复现场】
            if(len==0 || len+i==L) return; //剪纸，len==0说明这一轮是从头开始的，i+len==L说明这一轮已经拼完了
            while(i>minN && Hash[i]==0) i--; //剪纸，跳过所有用完的线段
        }
    }
    return;
}


int main(){
    int n;
    cin>>n;
    int sum=0;
    while(n--){
        int a;
        cin>>a;
        Hash[a]++;          //记录每种长度的线段有多少根
        sum+=a;             //线段总长度
        maxN=max(maxN,a);
        minN=min(minN==0?a:minN,a);
    }

    for(int L=maxN;L<=sum;L++){ //线段的长度至少为maxN，至多为sum
        if(sum%L==0){       //能整除才有可能拼成若干根长度为L的线段
            dfs(sum/L,0,L,maxN); //尝试拼出sum/L根长度为L的线段
        }

    }
}