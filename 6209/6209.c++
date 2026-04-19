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
  int a,n,k,ans = 0;
  cin>>a>>n>>k;
  vector<int> x;
  x.push_back(0);
  for(int i = 0;i<n;i++){
    int p;
    cin>>p;
    x.push_back(p);
  }
  x.push_back(a);
  sort(&x[0],&x[n+1]);
  int l = 0,h = a,m;
  while(l<h){
    int cnt = 0;
    m = (l+h)/2+1;
    int cur = 0;
    for(int i = 1;i<x.size();i++){
      if(x[i]-x[cur]<m){
        cnt++;
      }
      else cur = i;
    }
    if(cnt>k){
      h = m-1;
    }
    else{
      l = m;
    }
  }
  cout<<l;
  return 0;
}
