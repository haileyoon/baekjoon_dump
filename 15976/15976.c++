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
  int n,m,a,b,ans = 0;
  cin>>n;
  vector<long long> x_input,x;
  for(int i = 0;i<n;i++){
    long long loc,p;
    cin>>loc;
    cin>>p;
    x_input.push_back(p);
    x.push_back(loc);
  }
  cin>>m;
  vector<long long> y,total;
  total.push_back(0);
  long long cnt;
  cnt = 0;
  for(int i = 1;i<=m;i++){
    long long loc,p;
    cin>>loc;
    cin>>p;
    y.push_back(loc);
    total.push_back(p+cnt);
    cnt+=p;
  }
  cin>>a>>b;
  long long l = 0,h = m,sum = 0;
  for(int i = 0;i<n;i++){
    l = 0,h = m;
    while(l<h){
      long long mid = (l+h)/2;
      if(x[i]+a>y[mid]){
        l = mid+1;
      }
      else{
        h = mid;
      }
    }
    long long low = l;
    l = 0,h = m;
    while(l<h){
      long long mid = (l+h)/2;
      if(x[i]+b+1>y[mid]){
        l = mid+1;
      }
      else{
        h = mid;
      }
    }
    long long high = l;
    sum+=x_input[i]*(total[high]-total[low]);
  }
  cout<<sum;
}
