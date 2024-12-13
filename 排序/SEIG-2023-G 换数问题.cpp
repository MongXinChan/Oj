#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    int times;
    cin>>times;
    for(int i=0;i<n;i++)cin>>a[i];
    while(times--){
        int x,k;
        cin>>x>>k;
        if(!(k>a[x-1]&&k<=a[x])){
            a[--x]=k;
            sort(a.begin(),a.end());
            }
        else
            a[--x]=k;
    }
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}