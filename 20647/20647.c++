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
vector<int>a[1000005];
int ans = 0;
int visited[1000005]={0};
void dfs(int x){
  visited[x] = 1;
  int cnt = 0;
  for(int i = 0;i<a[x].size();i++){
    if(visited[a[x][i]]==0){
      cnt++;
      dfs(a[x][i]);
    }
  }
  int t = 1;
  while(t-1<cnt){
    ans++;
    t*=2;
  }
  ans+=cnt;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  for(int i = 0;i<n-1;i++){
    int p,q;
    cin>>p>>q;
    a[p].push_back(q);
    a[q].push_back(p);
  }
  dfs(1);
  cout<<ans;
  return 0;
}
