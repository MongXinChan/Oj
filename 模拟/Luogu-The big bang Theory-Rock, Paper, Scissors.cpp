/*
#include<iostream>
#define MAXN 10000;
using namespace std;

short a[MAXN]={0},b[MAXN]={0};
short WA=0,WB=0;//Win的成绩 
void cmp(int a,int b){//a是甲 
	if(a==b)
		return;
	switch(a){
		case 0:switch(b){
			case 1:WB++;break;
			case 2:WA++;break;
			case 3:WA++;break;
			case 4:WB++;break;
		};break; 
		case 1:switch(b){
			case 0:WA++;break;
			case 2:WB++;break;
			case 3:WA++;break;
			case 4:WB++;break;
		};break;
		case 2:switch(b){
			case 0:WB++;break;
			case 1:WA++;break;
			case 3:WB++;break;
			case 4:WA++;break;
		};break;
		case 3:switch(b){
			case 0:WB++;break;
			case 1:WB++;break;
			case 2:WA++;break;
			case 4:WA++;break;
		};break;
		case 4:switch(b){
			case 0:WA++;break;
			case 1:WA++;break;
			case 2:WB++;break;
			case 3:WB++;break;
		};break;
	}
}

int main(){
	int N,Ta,Tb;
	cin>>N>>Ta>>Tb;
	for(int i=0;i<Ta;i++){
		cin>>a[i];
	}
	for(int i=0;i<Tb;i++){
		cin>>b[i];
	}
	for(int i=0;i<N;i++){
		cmp(a[i%Ta],b[i%Tb]);
	}
	cout<<WA<<" "<<WB;
	return 0;
}
*/

/*打表法*/

#include <iostream>
using namespace std;
const int MAXN = 200 + 10;
int n, na, nb, a[MAXN], b[MAXN], cnta, cntb;
int vs[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}}; //得分表的处理 
int main()
{
    cin >> n >> na >> nb;
    for(int i = 0; i < na; i++) cin >> a[i];
    for(int i = 0; i < nb; i++) cin >> b[i];
    for(int i = 0; i < n; i++)
    {
        cnta += vs[a[i % na]][b[i % nb]]; //周期循环 
        cntb += vs[b[i % nb]][a[i % na]];
    }
    cout << cnta << " " << cntb << endl;
    return 0;
}
