#include<iostream>
#include<cmath>

using namespace std;

/*
第一行两个整数 n,m，表示方阵大小和魔法施放次数。接下来 m 行，每行 4个整数 x,y,r,z，表示在这次魔法中，Scarlet 会把以第 x行第 y列为中心的 2r+1 阶矩阵按照某种时针方向旋转，其中 
z=0 表示顺时针，z=1 表示逆时针。
*/
int a[501][501],b[501][501];
//-->我们多一格是为了方便统计


int main(){
	int n,m,t=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=t++;
		}
	}
	for(int i=1;i<=m;i++){
		int x,y,r,opt;
		cin>>x>>y>>r>>opt;
		if(opt==0){
			for(int j=x-r;j<=x+r;j++){
				for(int k=y-r;k<=y+r;k++){
					b[x-y+k][x+y-j]=a[j][k];
				}
			}
			for(int j=x-r;j<=x+r;j++){
				for(int k=y-r;k<=y+r;k++){
					a[j][k]=b[j][k];
				}
			}
		}
		else{
			for(int j=x-r;j<=x+r;j++){
				for(int k=y-r;k<=y+r;k++){
					b[x+y-k][y-x+j]=a[j][k];
				}
			}
			for(int j=x-r;j<=x+r;j++){
				for(int k=y-r;k<=y+r;k++){
					a[j][k]=b[j][k];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
