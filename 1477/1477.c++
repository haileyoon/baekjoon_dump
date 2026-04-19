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
  int n,num,len;
  cin>>n>>num>>len;
  int a[151]={0};
  for(int i = 1;i<=n;i++){
    cin>>a[i];
  }
  a[0] = 0;
  a[n+1] = len;
  sort(&a[0],&a[n+2]);
  int l = 1,h = len,m,cnt = 0;
  while(l<h){
    m = (l+h)/2;
    int cur = a[0];
    cnt = 0;
    for(int i = 1;i<=n+1;i++){
      cnt+=(a[i]-a[i-1]-1)/m;
    }
    if(cnt<=num){
      h = m;
    }
    else{
      l = m+1;
    }
  }
  cout<<l;
  return 0;
}
