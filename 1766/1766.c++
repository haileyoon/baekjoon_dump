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
vector<int> a[32001];
int in[32001]={0};
void top(){
  priority_queue<int,vector<int>,greater<int>> q;
  for(int i = 1;i<=n;i++){
    if(in[i]==0){
      q.push(i);
    }
  }
  while(!q.empty()){
    int cur = q.top();
    q.pop();
    cout<<cur<<" ";
    for(int i = 0;i<a[cur].size();i++){
      in[a[cur][i]]--;
      if(in[a[cur][i]]==0){
        q.push(a[cur][i]);
      }
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  for(int i = 0;i<m;i++){
    int x,y;
    cin>>x>>y;
    in[y]++;
    a[x].push_back(y);
  }
  top();
  return 0;
}
