# include<iostream>

using namespace std;

long long quickPow(long long a, long long b, long long p){
    if(b == 0){
        return 1;
    }

    if(b == 1){
        return a % p;
    }

    long long half = quickPow(a, b/2, p);

    if(b % 2 == 0){
        return (half * half) % p; ;
    } else {
        return ((half * half ) % p * a )% p;
    }
}
//返回值要同为long long

int main(){
    long long a,b,p;
    long long ans=1;

    cin>>a>>b>>p;
    
    ans = quickPow(a,b,p);
    cout<<a<<"^"<<b<<" mod "<<p<<"="<<ans<<endl;

    return 0;

}