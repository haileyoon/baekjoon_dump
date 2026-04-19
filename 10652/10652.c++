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
int b,p,e,n,m,ans = 1e9;
vector<int> a[40001];
int visited[40001]={0};
int final[40001]={0};
queue<int> visit;
void bfs(int begin){
  visited[begin] = 1;
  while(!visit.empty()){
    begin = visit.front();
    for(int i = 0;i<a[begin].size();i++){
      if(visited[a[begin][i]]==0){
        visited[a[begin][i]] = visited[begin]+1;
        visit.push(a[begin][i]);
      }
    }
    visit.pop();
  }
}
void clear(){
  for(int i = 0;i<40001;i++){
    visited[i] = 0;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>b>>e>>p>>n>>m;
  for(int i = 0;i<m;i++){
    int p,q;
    cin>>p>>q;
    a[p].push_back(q);
    a[q].push_back(p);
  }
  clear();
  visit.push(1);
  bfs(1);
  for(int i = 1;i<=n;i++){
    final[i]+=(visited[i]-1)*b;
  }
  clear();
  visit.push(2);
  bfs(2);
  for(int i = 1;i<=n;i++){
    final[i]+=(visited[i]-1)*e;
  }
  clear();
  visit.push(n);
  bfs(n);
  for(int i = 1;i<=n;i++){
    final[i]+=(visited[i]-1)*p;
  }
  for(int i = 1;i<=n;i++){
    ans = min(final[i],ans);
  }
  cout<<ans;
  return 0;
}
