#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define MAX 501
int la,lb,m;//m是最大值的意思 
short x[MAX]={},y[MAX]={};
string a,b;

int Traversing(short* p,short *q,string a,string b){
	for(int i=1;i<=a.length();++i){
		p[i]=a[a.length()-i]-'0';
	}
	for(int i=1;i<=b.length();++i){
		q[i]=b[b.length()-i]-'0';
	}
}

int main(){
	cin>>a>>b;
	la=a.length();
	lb=b.length();
	m=max(la,lb);
	if(la>lb){
		Traversing(x,y,a,b);
	}
	else{
		Traversing(y,x,b,a);
	}
	for(int i=1;i<m;++i){
		if(x[i]>=10){
			x[i]-=10;
			++x[i+1];
		}
	}
	if(x[m+1]>0){
		++m;
	}
	for(int i=m;i>1;--i){
		cout<<x[i];
	}
	return 0;
} 