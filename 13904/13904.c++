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
vector<pair<int,int>> a;
bool cmp(pair<int,int>q, pair<int,int>w){
  if(q.second!=w.second){
    return q.second>w.second;
  }
  else return q.first<w.first;
}
int main(){
  cin.tie(0);
  cout.tie(0);
  int visited[1001]={0};
  int n,ax = 0,cnt = 0;
  cin>>n;
  for(int i = 0;i<n;i++){
    int q,w;
    cin>>q>>w;
    a.push_back({q,w});
    ax = max(q,ax);
  }
  sort(a.begin(),a.end(),cmp);
  for(int i = 0;i<n;i++){
    for(int j = a[i].first;j>0;j--){
      if(visited[j]==0){
        visited[j] = a[i].second;
        break;
      }
    }
  }
  for(int i = 1;i<=ax;i++){
    cnt+=visited[i];
  }
  cout<<cnt;
  return 0;
}
