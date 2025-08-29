#include<bits/stdc++.h>
#define N 1000000
//我是真忘了是哪个题目了。。。后面找到再改改。
struct pp{
    int id,sum;
    friend bool operator<(pp a,pp b){
        return a.sum>b.sum;
    }
}a[N],b[N];
int m,n,k,l,d,c[N];

int main(){
    std::cin>>m>>n>>k>>l>>d;
    int ans=0,sum=0;
    for(int i=0;i<N;i++)a[i].sum=0;
    for(int i=0;i<N;i++)b[i].sum=0;
    for(int i=1;i<=d;i++){
        int x1,y1,x2,y2;
        std::cin>>x1>>y1>>x2>>y2;
        if(x1+1==x2)a[x1].sum++,a[x1].id=x1;
        if(x2+1==x1)a[x2].sum++,a[x2].id=x2;
        if(y1+1==y2)b[y1].sum++,b[y1].id=y1;
        if(y2+1==y1)b[y2].sum++,b[y2].id=y2;
    }
    std::sort(a,a+m);
    for(int i=0;i<k;i++){
        c[i]=a[i].id;
    }
    std::sort(c,c+k);
    for(int i=0;i<k;i++){
        std::cout<<c[i]<<" ";
    }
    std::cout<<std::endl;
    std::sort(b,b+n);
    for(int i=0;i<l;i++){
        c[i]=b[i].id;
    }
    std::sort(c,c+l);
    for(int i=0;i<l;i++){
       	std::cout<<c[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
