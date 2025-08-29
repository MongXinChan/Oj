#include<iostream>
#include<algorithm>
#include<string>
using namespace std; 
string a,b;
int n,p[5000],q[5000],t[5000],m;



int main(){
	cin>>a>>b;
	int la=a.length(),lb=b.length();
	//store
	for(int i=1;i<=la;++i){
		p[i]=a[la-i]-'0';
	}
	for(int i=1;i<=lb;++i){
		q[i]=b[lb-i]-'0';
	}
	//multiple
	for(int i=1;i<=la;++i){
		for(int j=1;j<=lb;++j){
			t[i+j-1]+=p[i]*q[j];//remember to'+=' isnt '='
		}
	}
	m=la+lb;
	//plus
	for(int i=1;i<m;++i){
		if(t[i]>9){
			t[i+1]+=t[i]/10;
			t[i]%=10;
		}
	}
	while(t[m]==0&&m>1){
		m--;
	}
	for(int i=m;i>=1;--i){
		cout<<t[i];
	}
	return 0;
}