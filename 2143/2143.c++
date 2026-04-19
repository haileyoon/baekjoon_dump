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
  long long x,n,k,ans = 0;
  long long a[1001]={0},b[1001]={0};
  cin>>x>>n;
  for(int i = 1;i<=n;i++){
    cin>>a[i];
  }
  vector<long long> asum,bsum;
 for(int i = 1;i<=n;i++){
    long long cnt = a[i];
    asum.push_back(cnt);
    for(int j = i+1;j<=n;j++){
      cnt+=a[j];
      asum.push_back(cnt);
    }
  }
  cin>>k;
  for(int i = 1;i<=k;i++){
    cin>>b[i];
  }
  for(int i = 1;i<=k;i++){
    long long cnt = b[i];
    bsum.push_back(cnt);
    for(int j = i+1;j<=k;j++){
      cnt+=b[j];
      bsum.push_back(cnt);
    }
  }
  sort(bsum.begin(),bsum.end());
  sort(asum.begin(),asum.end());
  for(int i = 0;i<asum.size();i++){
    long long l = 0,h = bsum.size(),m = 0,ans1 = 0,ans2 = 0;
    while(l<h){
      m = (l+h)/2;
      if(bsum[m]<x-asum[i]) l = m+1;
      else h = m;
    }
    ans1 = h;
    l = 0,h = bsum.size();
    while(l<h){
      m = (l+h)/2;
      if(bsum[m]<=x-asum[i]) l = m+1;
      else h = m;
    }
    ans2 = h;
    ans+=ans2-ans1;
  }
  cout<<ans;
}
