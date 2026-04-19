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
vector<pair<long long,long long>>stop;
int main(){
  cin.tie(0);
  cout.tie(0);
  int n,k,f,c;
  cin>>n>>k>>f>>c;
  for(int i = 0;i<k;i++){
    int loc,p;
    cin>>loc>>p;
    stop.push_back({loc,p});
  }
  int mx = 0;
  bool yn[100001]={0};
  for(int i = k-1;i>=0;i--){
    if(stop[i].second>mx){
      yn[i] = true;
      mx = stop[i].second;
    }
  }
  long long t = 0,cnt = 0,p = 0,a = 0,b = 0;
  for(int i = 0;i<k;i++){
    if(yn[i]){
      a += (stop[i].first-p)*f;
      b += (stop[i].first-p)*c;
      cnt+=((a-b)*stop[i].second);
      a = b;
      p = stop[i].first;
    }
  }
  cout<<cnt;
  return 0;
}
