#include<bits/stdc++.h>
#define MAXN 100000
#define int long long

signed main(){//��Ϊ��int long long������signed
    signed n,a[MAXN];
    std::cin>>n;
    for(signed i=0;i<n;i++){
        std::cin>>a[i];
    }
    std::sort(a,a+n);
    for(signed i=0;i<n;i++){
        std::cout<<a[i]<<" ";
    }
    return 0;
}
