#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#define maxN 1000005
using namespace std;
struct num{
  int start,loc,x;
};
bool cmp(num x,num y){
  return x.start<y.start;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,ans = 2e9;
  cin>>n;
  vector<num> a;
  int alone[100001]={0};
  for(int i = 0;i<n;i++){
    int q,w;
    cin>>q>>w;
    a.push_back({q,i,1});
    a.push_back({w,i,-1});
  }
  set<int>curr;
  int cnt = 0;
  sort(a.begin(),a.end(),cmp);
  for(int i = 0;i<a.size();i++){
    if(curr.size()==1){
      alone[*curr.begin()]+=a[i].start-a[i-1].start;
    }
    if(curr.size()>0){
      cnt+=a[i].start-a[i-1].start;
    }
    if(a[i].x==1){
      curr.insert(a[i].loc);
    }
    else{
      curr.erase(a[i].loc);
    }
  }
  for(int i = 0;i<n;i++){
    ans = min(ans,alone[i]);
  }
  cout<<cnt-ans;
  return 0;
}
