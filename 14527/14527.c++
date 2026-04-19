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
bool cmp(pair<int,int> a,pair<int,int> b){
  if(a.second!=b.second){
    return a.second<b.second;
  }
  else{
    return a.first<b.first;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  vector<pair<int,int>> a;
  for(int i = 0;i<n;i++){
    long long q,p;
    cin>>q>>p;
    a.push_back({q,p});
  }
  sort(a.begin(),a.end(),cmp);
  long long l = 0,h = n-1,ans = 0,cntl = 0,cnth = 0;
  while(l<=h){
    if(ans<a[l].second+a[h].second) ans = a[l].second+a[h].second;
    cntl++;
    cnth++;
    if(cntl>a[l].first){
      l++;
      cntl = 0;
    }
    if(cnth>a[h].first){
      h--;
      cnth = 0;
    }
  }
  cout<<ans;
  return 0;
}
