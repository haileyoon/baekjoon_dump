#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#define maxN 1000005
using namespace std;
int n,t_max;
int a[100001]={0};
bool funct(int x){
  priority_queue<int,vector<int>,greater<int>> pq;
  for(int i = 0;i<x;i++){
    pq.push(a[i]);
  }
  for(int i = x;i<n;i++){
    int e = pq.top();
    pq.pop();
    if(e+a[i]>t_max){
      return false;
    }
    else{
      pq.push(e+a[i]);
    }
  }
  return true;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>t_max;
  for(int i = 0;i<n;i++){
    cin>>a[i];
  }
  int l = 1,h = n,ans = 0;
  while(l<h){
    int m = (l+h)/2;
    if(funct(m)){
      h = m;
      ans = m;
    }
    else{
      l = m+1;
    }
  }
  cout<<ans;
  return 0;
}
