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
  int n,k;
  int a[200001]={0};
  cin>>n>>k;
  for(int i = 0;i<n;i++){
    cin>>a[i];
  }
  sort(&a[0],&a[n]);
  long long l = 0, h = a[n-1]-a[0];
  while(l<h){
    long long cnt = 0, m = (l+h)/2+1, x = a[0];
    for(int i = 1;i<n;i++){
      int dist = a[i]-x;
      if(dist>=m){
        cnt++;
        x = a[i];
      }
    }
    cnt++;
    if(cnt>=k){
      l = m;
    }
    else{
      h = m-1;
    }
  }
  cout<<l;
  return 0;
}
