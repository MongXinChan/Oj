#include<bits/stdc++.h>
using namespace std;
char a[101][101];//地图
int b[101][101]={0};//答案
int n,m,i,j;
int dx[8]={1,0,-1,0,-1,1,1,-1};//方向
int dy[8]={0,1,0,-1,-1,-1,1,1};//方向
void dfs(int x,int y){
    //调用函数将地雷周围的数加起来
    int nx,ny,k;
    for (k=0;k<8;k++){
        //循环，将8个方向加起来。（不需要判断地雷，因为输出有判断）

        nx=x+dx[k];
        ny=y+dy[k];
        if (nx>=1&&nx<=n&&ny>=1&&ny<=m)//判断有没有越界
            b[nx][ny]++;//加一
   }
}
int main(){
    cin>>n>>m;//输入
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++){
            cin>>a[i][j];
            if (a[i][j]=='*')
                dfs(i,j);//如果是地雷就调用函数
        }
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++)
            if (a[i][j]=='*')//判断是地雷就直接输出
                cout<<a[i][j];
            else
                cout<<b[i][j];//不是地雷输出答案
        cout<<endl;
    }
 return 0;
}