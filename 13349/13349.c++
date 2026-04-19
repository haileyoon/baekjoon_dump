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
long long a[1001][1001],q,w,ans =1e9;
bool visited[1001][1001];
int n,k;
int ax[4]={0,0,-1,1};
int ay[4]={-1,1,0,0};
void dfs(long long y,long long x,long long p){
  visited[y][x]=true;
  for(int i = 0;i<4;i++){
    long long xx = ax[i]+x;
    long long yy = ay[i]+y;
    if(xx<0||yy<0||xx>=w||yy>=q){
      continue;
    }
    if(!visited[yy][xx]&&a[yy][xx]<=a[y][x]+p){
      visited[yy][xx] = true;
      dfs(yy,xx,p);
    }
  }
}
int main(){
  cin.tie(0);
  cout.tie(0);
  cin>>q>>w;
  for(int i = 0;i<q;i++){
    for(int j = 0;j<w;j++){
      cin>>a[i][j];
    }
  }
  long long l = 0,h = 1e9,m = 0;
  while(l<h){
    for(int i = 0;i<q+1;i++){
      for(int j = 0;j<w+1;j++){
        visited[i][j] = false;
      }
    }
    m = (l+h)/2;
    dfs(0,0,m);
    if(visited[q-1][w-1]){
      h = m;
      ans = min(ans,m);
    }
    else{
      l = m+1;
    }
  }
  cout<<ans;
}
