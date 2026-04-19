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
  long long a,b,c;
  cin>>a>>b>>c;
  long long x[100001]={0};
  for(int i = 0;i<a;i++){
    cin>>x[i];
  }
  sort(&x[0],&x[a]);
  long long l = 0,h = x[a-1]-x[0],m = 0;
  while(l<h){
    m = (l+h)/2;
    long long bus = 1,cow = 1,fcow = 0;
    while(cow<a){
      if(cow-fcow<c&&x[cow]<=x[fcow]+m){
        cow++;
        continue;
      }
      bus++;
      fcow = cow;
    }
    if(bus<=b){
      h = m;
    }
    else{
      l = m+1;
    }
  }
  cout<<l;
  return 0;
}
