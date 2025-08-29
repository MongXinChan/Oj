#include<bits/stdc++.h>
#include<iomanip>
#define MAXN 10005

struct watertime{
	int t;	//float有误差慎用 
	int r;
};

watertime wt[MAXN];

bool compare(const watertime &a, const watertime &b) {
    return a.t < b.t;
}

void Test02(){
	int n;
	std::cin>>n;
	double sum;
	for(int i=0;i<n;i++){
		std::cin>>wt[i].t;		//不是wt.t[i]而是wt[i].t 
		wt[i].r=i+1;
	}
	std::sort(wt,wt+n,compare);//记得加std:: 
	for(int i=0;i<n;i++){
		std::cout<<wt[i].r<<" ";
//		sum=sum+wt[i].t*(wt[i].r-1);
//		if(wt[i].r-1==0){
//			sum=sum+wt[i].t;
//		};
	}
	std::cout<<std::endl;
	for(int j=n-1;j>=0;j--){ //等待人数的计数器，由n-1开始
	   	int i=n-j-1;//这是个规律，当前最少时间的人序号和要等待的人数之和=n
	   	sum+=wt[i].t*j; //累加                  
  	}
//	std::cout<<std::fixed<<std::setprecision(2)<<(sum/n)-0.006;
	  	sum=sum/n;
	    std::cout<<std::fixed<<std::setprecision(2)<<sum;
//		printf("%0.2lf", sum);
}

int main(){
	Test02();
	return 0;
}
