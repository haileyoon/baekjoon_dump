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
  long long a[100002]={0},ans = 1e9;
  cin>>n>>k;
  for(int i = 1;i<n+1;i++){
    int x;
    cin>>x;
    a[i] = a[i-1]+x;
  }
  long long l = 0,h = 1;
  while(l<=h&&h<=n){ 
    if(a[h]-a[l]>=k){
      if(h-l<ans) ans = h-l;
      l++;
    }
    else{
      h++;
    }
  }
  if(ans == 1e9){
    cout<<0;
  }
  else{
    cout<<ans;
  }
}
