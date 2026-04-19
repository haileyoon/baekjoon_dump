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
  int n,k, ax = 0,l = 0;
  int a[100001]={0};
  cin>>n>>k;
  for(int i = 0;i<n;i++){
    cin>>a[i];
    ax+=a[i];
    l = max(l,a[i]);
  }
  int h = ax,m;
  while(l<h){
    m = (l+h)/2;
    int cnt = 0,num = 0;
    for(int i = 0;i<n;i++){
        if(cnt+a[i]>m){
          cnt = 0;
          num++;
        }
        cnt+=a[i];
    }
    if(cnt!=0) num+=1;
    if(num<=k){
      h = m;
    }
    else{
      l = m+1;
    }
  }
  cout<<l;
  return 0;
}
