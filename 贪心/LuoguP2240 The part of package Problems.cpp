#include<bits/stdc++.h>
#include<iomanip>
#define MAXN 1005
float m[MAXN],v[MAXN];
float ave[MAXN],ans;

void Test01(){
	int n,t;
	std::cin>>n>>t;
	for(int i=0;i<n;i++){
		std::cin>>m[i]>>v[i];
		ave[i]=v[i]/m[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(ave[j]<ave[j+1]){
				std::swap(ave[j],ave[j+1]);
				std::swap(v[j],v[j+1]);
				std::swap(m[j],m[j+1]);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(t-m[i]>-0.000001){
			t-=m[i];
			ans+=v[i];
		}
		else{
			ans+=t*ave[i];
			break; 
		}
	}
	printf("%0.2f",ans);//std::cout<<std::fixed<<std::setprecision(2)<<ans;
} 



int main(){
	Test01();
	return 0;
}