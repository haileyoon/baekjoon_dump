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
vector<int> b[1001];
vector<int> ans;
int in[1001]={0};
int out[1001]={0};
void top(){
  queue<int> q;
  for(int i = 1;i<=n;i++){
    if(in[i]==0){
      q.push(i);
    }
  }
  while(!q.empty()){
    int cur = q.front();
    ans.push_back(cur);
    for(int i = 0;i<b[cur].size();i++){
      in[b[cur][i]]--;
      if(in[b[cur][i]]==0){
        q.push(b[cur][i]);
      }
    }
    q.pop();
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  for(int i = 0;i<m;i++){
    int x;
    cin>>x;
    int cur[x]={0};
    for(int j = 0;j<x;j++){
      int y;
      cin>>y;
      cur[j] = y;
    }
    for(int j = x-1;j>=0;j--){
      for(int k = j-1;k>=0;k--){
        in[cur[j]]++;
      }
    }
    for(int j = 0;j<x;j++){
      for(int k = j+1;k<x;k++){
        b[cur[j]].push_back(cur[k]);
        out[cur[j]]++;
      }
    }
  }
  top();
  if(ans.size()!=n){
    cout<<"0";
  }
  else{
    for(int i = 0;i<n;i++){
      cout<<ans[i]<<"\n";
    }
  }
  return 0;
}
