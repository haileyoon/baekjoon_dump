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
  long long n;
  cin>>n;
  vector<pair<long long,long long>> a;
  for(int i = 0;i<n;i++){
    long long q,w;
    cin>>q>>w;
    a.push_back({q,w});
  }
  sort(a.begin(),a.end());
  long long cnt = a[0].second-a[0].first,end = a[0].second;
  for(int i = 1;i<n;i++){
    if(end>a[i].first){
      if(a[i].second>end)cnt+=a[i].second-end;
    }
    else{
      cnt+=a[i].second-a[i].first;
    }
    end = max(end,a[i].second);
  }
  cout<<cnt;
  return 0;
}
