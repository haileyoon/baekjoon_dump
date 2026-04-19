#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#define maxN 1000005
using namespace std;
int n,m;
int visited[51][51] = {0};
int a[51][51]={0};
int ax[4] = {0,0,-1,1};
int ay[4] = {1,-1,0,0};
int start[51][51]={0};
queue<pair<int,int>> visit;
int bfs(int x,int y){
  int ans = 0;
  visited[x][y] = 1;
  while(!visit.empty()){
    x = visit.front().first;
    y = visit.front().second;
    for(int i = 0;i<4;i++){
        int xx = x+ax[i];
        int yy = y+ay[i];
        if(a[xx][yy]==0){
          continue;
        }
        if(xx>n||yy>m||xx<=0||yy<=0){
          continue;
        }
        if(visited[xx][yy]==0&&a[xx][yy]==1){
          visited[xx][yy] = visited[x][y]+1;
          ans = max(ans,visited[xx][yy]);
          visit.push({xx,yy});
        }
    }
    visit.pop();
  }
  return ans;
}
void clear(){
  for(int i = 0;i<=n;i++){
    for(int j = 0;j<=m;j++){
      visited[i][j] = 0;
    }
  }
}
void print(){
  for(int i = 1;i<=n;i++){
    for(int j = 1;j<=m;j++){
      cout<<visited[i][j]<<" ";
    }
    cout<<"\n";
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  for(int i = 1;i<=n;i++){
    string s;
    cin>>s;
    for(int j = 1;j<=m;j++){
      if(s[j-1]=='W') a[i][j] = 0;
      else if(s[j-1]=='L') a[i][j] = 1;
    }
  }
  int ans = 0;
  clear();
  for(int i = 1;i<=n;i++){
    for(int j = 1;j<=m;j++){
      if(a[i][j]==1){
        visit.push({i,j});
        ans = max(ans,bfs(i,j)-1);
        clear();
      }
    }
  }
  cout<<ans;
  return 0;
}
