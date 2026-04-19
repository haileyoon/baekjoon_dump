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
int n,k,ans = 251;
int path[251]={0};
int s[251]={0};
int d[251]={0};
int visited[251][251]={0};
void dfs(int x,int y){
  if(visited[x][y]){
    return;
  }
  if(x==n-1){
    ans = min(ans,y);
  }
  visited[x][y] = 1;
  for(int i = x+1;i-x<=d[y]&&i<n;i++){
    if(path[i]<=s[y]) dfs(i,y);
  }
  for(int i = y+1;i<k;i++){
    if(path[x]<=s[i]) dfs(x,i);
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>k;
  for(int i = 0;i<n;i++){
    cin>>path[i];
  }
  for(int i = 0;i<k;i++){
    cin>>s[i]>>d[i];
  }
  dfs(0,0);
  cout<<ans;
  return 0;
}
