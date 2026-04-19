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
bool cmp(pair<long long,long long> q,pair<long long,long long> w){
  if(q.second!=w.second){
    return q.second>w.second;
  }
  else{
    return q.first<w.first;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long d,cnt = 0;
  int n;
  vector<pair<long long,long long>> a;
  cin>>n>>d;
  for(int i = 0;i<n;i++){
    long long p,q;
    cin>>p>>q;
    a.push_back({p,q});
  }
  set<int> x;
  int j = 0;
  sort(a.begin(),a.end(),cmp);
  for(int i = 0;i<n;i++){
    while(j<a.size()&&a[j].second>=a[i].second*2){
      x.insert(a[j].first);
      j++;
    }
    auto low = x.lower_bound(a[i].first-d);
    auto high = x.lower_bound(a[i].first);
    if(a[i].first<=*high&&a[i].first+d>=*high&&a[i].first-d<=*low&&a[i].first>*low){
      cnt++;
    }
  }
  cout<<cnt;
  return 0;
}
