#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <deque>
#define maxN 1000005
using namespace std;
vector<pair<int,int>> a[10001];
bool visited[10001];
int n,k,t,e;
void dfs(int x,int p){
  visited[x] = true;
  for(int i = 0;i<a[x].size();i++){
    int xx = a[x][i].first;
    if(!visited[xx]&&a[x][i].second>=p){
      dfs(xx,p);
    }
  }
}
int main(){
  cin.tie(0);
  cout.tie(0);
  cin>>n>>k;
  for(int i = 0;i<k;i++){
    int x,y,wei;
    cin>>x>>y>>wei;
    a[x].push_back({y,wei});
    a[y].push_back({x,wei});
  }
  cin>>t>>e;
  int l = 1,h = 1e9,m = 0;
  while(l<h){
    m = (l+h)/2+1;
    for(int i = 1;i<=n;i++){
      visited[i] = false;
    }
    dfs(t,m);
    if(visited[e]){
      l = m;
    }
    else{
      h = m-1;
    }
  }
  cout<<l;
}
