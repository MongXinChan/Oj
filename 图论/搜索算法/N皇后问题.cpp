//oj.ecustacm.cn/problem.php?id=1158

#include<bits/stdc++.h>

using namespace std;

int row,total;
int ans[20];
int visited[30];
int possibleVis[3][30];
// possibleVis[i][j]，当i=1时候代表主对角线，i=2代表副对角线，j代表列号

void dfs(int currentRow){
    if( currentRow == row+1){
        total++;
        if(total<=3){
            for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
            cout<<endl;
        }
        return;
    }

    for(int y=i;y<=n;y++){
        if(visited[y] || possibleVis[1][currentRow - y + n] || possibleVis[2][currentRow + y])
            continue;
        visited[y]=1;
        possibleVis[1][currentRow - y + n]=1;
        possibleVis[2][currentRow + y]=1;
        ans[currentRow]=y;
        dfs(currentRow+1);
        visited[y]=0;
        possibleVis[1][currentRow - y + n]=0;
        possibleVis[2][currentRow + y]=0;   //【恢复现场】
    }
}

int main(){
    cin>>row;
    dfs(1);
    cout<<total<<endl;
    return 0;
}