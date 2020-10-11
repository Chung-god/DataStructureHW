#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int road[1000][1000];
int visited[1000][1000];
int mincost=1000;
int m,n;

void dfs(int x, int y, int cost){
    if(x==m-1&&y==n-1){if(cost<mincost)mincost =cost;}
    int xmove[4]={0,0,1,-1};
    int ymove[4]={-1,1,0,0};
    for(int i=0; i<4; i++){
        int xx = x+xmove[i];
        int yy = y+ymove[i];
        if(yy>=1000||yy<0||xx>=1000||xx<0){
            continue;
        }
        if(road[yy][xx]!=-1&&visited[yy][xx]==0){
            visited[yy][xx]=1;
            dfs(xx,yy,cost+road[yy][xx]);
            visited[yy][xx]=0;
        }
    }
}


int main(){
    cin>>m>>n;
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            if(i<m&&j<n){
                cin>>road[j][i];
            }else{
                road[j][i]=-1;
            }
            visited[j][i]=0;
        }
    }
    visited[0][0]=1;
    dfs(0,0,road[0][0]);
    if(mincost==1000)mincost=-1;
    cout<<mincost;

}