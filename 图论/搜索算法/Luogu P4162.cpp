/**
 * Windy 有一块地，被分为N*M块1*1的小方格，有的格子含有障碍物，有的没有含有；如果格子A可以走到格子B，
 * 那么两个格子的距离就为两个格子之间的欧氏距离，如果格子A不能走到格子B，那么两个格子的距离为0。
 * 如果格子X和格子Y有公共边，并且X和Y都不含有障碍物，那么X可以走到Y，Y也可以走到X（但是这有点妨碍我们进行剪纸）。
  *如果为windy可以移走T块障碍物，求所有格子间的最大距离。需要保证移走T块障碍物以后至少有一格不含障碍物
    * 输入：第一行包含3个整数N、M、T。接下来有N行，每行为一个长度为M的字符串，0表示该格子不含障碍物，1表示该格子含有障碍物
    * 1<=N,M<=30,0<=T<=30
    * 输出：输出一个实数，表示所有格子间的最大距离，保留6位小数
 */
#include <bits/stdc++.h>

using namespace std;

int n,m,t;

int a[35][35];

int dis[35][35];
bool vis[35][35];

int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};              //四个方向

void dfs(int x,int y,int cnt){
    if(cnt>t) return;                               //【可行性剪纸】，已经移走了t个障碍，不能再移走了
    if(cnt>=dis[x][y]) return;                      //【最优性剪纸】，之前到达过(x,y)，并且距离更小
    dis[x][y]=cnt;                                  //标记访问
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>n || nx<1 || ny>m || ny<1) {continue;} //越界
        if(vis[nx][ny]){continue;}
        vis[nx][ny]=1;
        dfs(nx,ny,cnt+a[nx][ny]);                   //如果是障碍物，cnt+1
        vis[nx][ny]=0;                              //【恢复现场】
    }
}

/***
 * 计算最短路径一般用Dijkstra、SPFA这样的高级最短路径算法。但是用DFS进行剪纸操作也可以完成我们的目的，最主要是剪纸的条件如何确定
 *      1.可行性剪纸，这里是移走的障碍物数量已经超过t，确实就没有必要继续搜索下去了
 *      2.记忆化搜索，这里对访问的节点进行记录，记录到达该节点时所行走的距离CNT1与CNT2两种情况，如果CNT1<CNT2，那么就没有必要继续搜索CNT2的路径了，
 *   注意这里的等号不能省略，因为等号的情况也没有必要继续搜索下去了。
 * 
 *
 */

int main(){
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char s;
            cin>>s;
            a[i][j]=s-'0';
        }
    }

    int ans=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            memset(dis,0x3f,sizeof(dis));
            memset(vis,0,sizeof(vis));
            int cnt = a[i][j] == 1? 1: 0;    //如果起点是障碍物，cnt=1
            dfs(i,j,cnt);
            for(int x=1;x<=n;x++){
                for(int y=1;y<=m;y++){
                    if(dis[x][y]<=t){
                        ans=max(ans,(x-i)*(x-i)+(y-j)*(y-j));
                    }
                }
            }
        }
    }
    cout<<fixed<<setprecision(6)<<sqrt(ans)<<endl;
    return 0;
}