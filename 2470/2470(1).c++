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
  int n;
  cin>>n;
  long long fin1 = 0,fin2 = 0,diff = 2000000001;
  set<long long> a;
  for(int i = 0;i<n;i++){
    int p;
    cin>>p;
    a.insert(p);
  }
  auto cnt = a.begin();
  for(int i = 0;i<n;i++){
    long long j = *cnt;
    a.erase(j);
    long long x = 0,y = 0;
    auto r = a.lower_bound(-1*j);
    if(r==a.begin()){
      x = *r;
    }
    else if(r==a.end()){
      r--;
      x = *r;
    }
    else{
      int q = *r;
      r--;
      int w = *r;
      if(abs(x+q)<abs(x+w)){
        x = q;
      }
      else{
        x = w;
      }
    }
    y = j;
    if(abs(x+y)<diff){
      fin1 = min(x,y);
      fin2 = max(x,y);
      diff = abs(x+y);
    }
    a.insert(j);
    cnt++;
  }
  cout<<fin1<<" "<<fin2;
  return 0;
}
