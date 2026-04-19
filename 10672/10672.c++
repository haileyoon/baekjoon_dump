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
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  int x,y,r;
  int seen[50001]={0};
  vector<pair<int,int>>a;
  for(int i = 0;i<n;i++){
    cin>>x>>y>>r;
    x*=-1;
    a.push_back({(x-1)*r,y});
    a.push_back({x*r,-y});
  }
  sort(a.begin(),a.end());
  set<int> curr;
  set<int> ans;
  int i = 0;
  while(i < a.size()){
    int p = a[i].first;
    while(p==a[i].first){
      pair<int,int> b = a[i];
      int q = b.second;
      if(q>0){
        curr.insert(q);
      }
      else{
        curr.erase(-q);
      }
      i++;
    }
    if(curr.size()>0){
      ans.insert(*curr.begin());
    }
  }
  cout<<ans.size();
  return 0;
}
