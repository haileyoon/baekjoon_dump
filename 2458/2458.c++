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
int visited[501];
vector<int> a[501],b[501];
void dfs1(int cur){
  visited[cur] = 1;
  for(int i = 0;i<a[cur].size();i++){
    int nxt = a[cur][i];
    if(visited[nxt]==0){
      dfs1(nxt);
    }
  }
}
void dfs2(int cur){
  visited[cur] = 1;
  for(int i = 0;i<b[cur].size();i++){
    int nxt = b[cur][i];
    if(visited[nxt]==0){
      dfs2(nxt);
    }
  }
}
int main(){
  int x,y,ans = 0;
  int up[501]={0}, down[501]={0};
  cin>>x>>y;
  for(int i = 0;i<y;i++){
    int l,m;
    cin>>l>>m;
    a[m].push_back(l);
    b[l].push_back(m);
  }
  for(int i = 1;i<=x;i++){
    int cnt = 0;
    for(int j = 0;j<501;j++){
      visited[j]=0;
    }
    dfs1(i);
    for(int j = 0;j<501;j++){
      if(visited[j]==1){
        cnt++;
      }
    }
    up[i]=cnt;
  }
  for(int i = 1;i<=x;i++){
    int cnt = 0;
    for(int j = 0;j<501;j++){
      visited[j]=0;
    }
    dfs2(i);
    for(int j = 0;j<501;j++){
      if(visited[j]==1){
        cnt++;
      }
    }
    down[i]=cnt;
  }
  for(int i = 1;i<=x;i++){
    if(up[i]+down[i]-2==x-1){
      ans++;
    }
  }
  cout<<ans;
  return 0;
}
