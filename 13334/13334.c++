#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#define maxN 1000005
using namespace std;
struct coords{
  long long x;
  long long y;
};
bool cmp(pair<long long,long long>a,pair<long long,long long>b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } 
    else {
        return a.second < b.second;
    }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  long long d,ans = 0;
  cin>>n;
  vector<pair<long long,long long>>a;
  priority_queue<long long,vector<long long>,greater<long long>> b;
  for(int i = 0;i<n;i++){
    long long q,p;
    cin>>q>>p;
    if(q<p){
      a.push_back({q,p});
    }
    else{
      a.push_back({p,q});
    }
  }
  sort(a.begin(),a.end(),cmp);
  cin>>d;
    for(int i = 0;i<a.size();i++){
      int begin = a[i].first;
      int end = a[i].second;
      if(end-begin<=d){
        b.push(begin);
      }
      else continue;
      while(b.size()>0){
        if(b.top()<end-d) b.pop();
        else{
          if(ans<b.size()) ans = b.size();
          break;
        }
      }
    }
  cout<<ans;
  return 0;
}
