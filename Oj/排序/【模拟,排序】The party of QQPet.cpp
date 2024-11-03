#include<iostream>
#include<bits/stdc++.h>
#define MAXN 1000
using namespace std;
struct mox{
	string n;//name
	string b_pos,a_pos;//position
	long long int con;//contribution
	int le,num;//level,number
}mx[MAXN];

int cmp1(mox a,mox b){
	if(a.con==b.con)
		return a.num<b.num;
	else
		return a.con>b.con;
}

short trans(string a){//transfer
	if (a=="BangZhu") return 0;
	if (a=="FuBangZhu") return 1;
	if (a=="HuFa") return 2;
	if (a=="ZhangLao") return 3;
	if (a=="TangZhu") return 4;
	if (a=="JingYing") return 5;
	if (a=="BangZhong") return 6;
}

int cmp2(mox a,mox b){
	if(trans(a.a_pos)==trans(b.a_pos)){
		if(a.le==b.le)	return a.num<b.num;
		return	a.le>b.le;
	}
	return trans(a.a_pos)<trans(b.a_pos); 
}

int main(){
	int N;
	cin>>N; 
	for(int i=0;i<N;i++){
		cin>>mx[i].n>>mx[i].b_pos>>mx[i].con>>mx[i].le;
		mx[i].num=i;
	}
	sort(mx+3,mx+N,cmp1);
	for (int i=0;i<N;i++){
		if (i==0) mx[i].a_pos="BangZhu";
		else if (i==1||i==2) mx[i].a_pos="FuBangZhu";
		else if (i==3||i==4) mx[i].a_pos="HuFa";
		else if (i>=5&&i<=8) mx[i].a_pos="ZhangLao";
		else if (i>=9&&i<=15) mx[i].a_pos="TangZhu";
		else if (i>=16&&i<=40) mx[i].a_pos="JingYing";
		else mx[i].a_pos="BangZhong";
	}
	sort(mx,mx+N,cmp2);
	for (int i=0;i<N;i++){
		cout<<mx[i].n<<" "<<mx[i].a_pos<<" "<<mx[i].le<<endl;
	}
    return 0;
}
