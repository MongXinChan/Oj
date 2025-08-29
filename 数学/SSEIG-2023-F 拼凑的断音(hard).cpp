/*
sum (a_j)<(i-1)*(a_i)
-->sum[i]<i*a_i
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n+1);
    vector<long long> sum(n+1,0);
    for(int i=1;i<n+1;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=2;i<n+1;i++)
    cout<<((sum[i]<=i*a[i])?1:0)<<" ";
    return 0;
}