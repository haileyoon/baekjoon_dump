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
  cin.tie(0);
  cout.tie(0);
  long long x,y,z,cnt = 0;
  cin>>x>>y>>z;
  set<long long> a;
  for(int i = 0;i<x;i++){
    long long p;
    cin>>p;
    a.insert(p);
  }
  for(int i = 0;i<y;i++){
    long long q,w;
    cin>>q>>w;
    auto e = a.lower_bound(q+(z-w));
    auto f = a.lower_bound(q-(z-w));
    if(abs(*e-q)+w<=z||abs(*f-q)+w<=z) cnt++;
  }
  cout<<cnt;
  return 0;
}
