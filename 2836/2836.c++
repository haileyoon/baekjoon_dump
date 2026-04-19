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
  vector<pair<long long,long long>> a;
  long long n,m,ans = 0;
  cin>>n>>m;
  for(int i = 0;i<n;i++){
    long long q,w;
    cin>>q>>w;
    if(q>w) a.push_back({w,q});
  }
  sort(a.begin(),a.end());
  long long start = 0, end = 0;
  bool yn = true;
  for(int i = 0;i<a.size();i++){
     if(a[i].first<=end){
      end = max(end,a[i].second);
    }
    else{
      ans+=2*(end-start);
      start = a[i].first;
      end = a[i].second;
    }
  }
  ans+=2*(end-start);
  ans+=m;
  cout<<ans;
  return 0;
}
