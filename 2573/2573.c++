#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#define maxN 1000005
using namespace std;
int a[301][301];
bool visited[301][301];
int n,k;
int ax[4]={0,0,-1,1};
int ay[4]={-1,1,0,0};
void dfs(int y, int x){
  visited[y][x]=true;
  for(int i = 0;i<4;i++){
    int xx = ax[i]+x;
    int yy = ay[i]+y;
    if(a[yy][xx]<0) a[yy][xx] = 0;
    if(xx<0||yy<0||xx>=k||yy>=n){
      continue;
    }
    if(!a[yy][xx]||visited[yy][xx]) continue;
    dfs(yy,xx);
  }
}
void melt(int y, int x){
  int w = 0;
  for(int i = 0;i<4;i++){
    int xx = ax[i]+x;
    int yy = ay[i]+y;
    if(xx<0||yy<0||xx>=k||yy>=n){
      continue;
    }
    if(a[yy][xx]==0) w++;
  }
  int ice = a[y][x]-w;
  if(ice==0) a[y][x] = -1;
  else a[y][x]-=w;
}
int main(){
  bool done = false;
  int area = 0,ans = 0,wer = 0;
  cin>>n>>k;
  for(int i = 0;i<n;i++){
    for(int j = 0;j<k;j++){
      cin>>a[i][j];
    }
  }
  while(true){
    ans++;
    for(int i = 0;i<301;i++){
      for(int j = 0;j<301;j++){
        visited[i][j] = false;
      }
    }
    int icenum = 0;
    for(int i = 0;i<n;i++){
      for(int j = 0;j<k;j++){
        if(a[i][j]!=0) melt(i,j);
        if(a[i][j]>0) icenum++;
      }
    }
    if(icenum==0){
      cout<<0;
      return 0;
    }
    int cnt = 0;
    for(int i = 0;i<n;i++){
      for(int j = 0;j<k;j++){
        if(a[i][j]<0) a[i][j] = 0;
        if(a[i][j]==0||visited[i][j]) continue;
          cnt++;
          dfs(i,j);
        }
      }
    if(cnt>1){
      cout<<ans;
      return 0;
    }
  }
}
