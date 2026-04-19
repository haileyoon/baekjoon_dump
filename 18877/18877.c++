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
struct coords{
  int x;
  int y;
};
bool cmp(coords q, coords w){
  if(q.x!=w.x){
    return q.x<w.x;
  }
  else{
    return q.y<w.y;
  }
}
int main(){
  cin.tie(0);
  cout.tie(0);
  int n,k,ans = 0;
  long long ax = 0;
  coords a[100001];
  cin>>n>>k;
  for(int i = 0;i<k;i++){
    cin>>a[i].x>>a[i].y;
    if(a[i].y>ax){
      ax = a[i].y;
    }
  }
  sort(&a[0],&a[k],cmp);
  long long l = 1, h = ax,cnt = 0,m = 1;
  while(l<h){
    m = (l+h)/2+1;
    cnt = 1;
    int x = a[0].x;
    for(int i = 0;i<k;i++){
      while(x<=a[i].y){
        if(x+m<=a[i].y){
          if(x+m>=a[i].x) x = x+m;
          else x = a[i].x;
          cnt++;
        }
        else{
          break;
        }
      }
    }
    if(cnt>=n){
      ans = m;
      l = m;
    }
    else{
      h = m-1;
    }
  }
  cout<<ans;
  return 0;
}
