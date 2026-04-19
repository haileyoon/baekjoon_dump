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
  int n,k,ans = 1e9;
  int a[5001]={0};
  cin>>n>>k;
  int lar = 0;
  for(int i = 0;i<n;i++){
    cin>>a[i];
    lar = max(a[i],lar);
  }
  int l = 0,h = lar,m;
  while(l<h){
    m = (l+h)/2;
    int in = a[0],ax = a[0],cnt = 1;
    for(int i = 1;i<n;i++){
      if(a[i]<in){
        in = a[i];
      }
      if(a[i]>ax){
        ax = a[i];
      }
      if(ax-in>m){
         cnt++;
         in = a[i];
         ax = a[i];
      }
    }
    if(cnt<=k){
      if(m<ans)ans = m;
      h = m;
    }
    else{
      l = m+1;
    }
  }
  cout<<ans;
  return 0;
}
