# Oj

##24
###Oct
```cpp
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
```


```cpp
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
```

> today's summary
> I consider that I never finish a question during lnog-time,including oj,some databates
> I need to pay some time to fill my mind about some computer question.
> 好了我的毕生英语也就这样了，发现最近自己挺忙的，也挺懒的，刷了一边数据结构和一些简单算法就浅尝辄止，想看的代码书也没看多少，不过值得高兴的是把《C++编程思想二卷》啃了第一卷，暂时来讲第二卷还不需要用太多，慢慢看，加上看《代码大全2》来简化我的编程习惯，说句实话，我有点==lazy==，这点直言不讳，也算是把Cpp的应用提上日程，现在准备每天1~3道oj（如果不忙手里的项目的话，尽可能保持2道），并且带着一些问题去找答案。预计在11月前完成对图论的复习以及构建一些==QT==小项目的需求。
> 即目前->每天Oj+一些学习，在11月份做好QT的小项目，大概是在中旬。期间找几天去看看华南植物园 ~ ，那里目前的秋意特别浓厚，喜欢秋
