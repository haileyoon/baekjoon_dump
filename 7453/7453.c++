#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#define maxN 1000005
using namespace std;
int main(){
  cin.tie(0);
  cout.tie(0);
  long long a[4][4001]={0};
  vector<long long> x;
  int n;
  long long cnt = 0;
  cin>>n;
  for(int i = 0;i<n;i++){
    for(int j = 0;j<4;j++){
      cin>>a[j][i];
    }
  }
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      x.push_back(a[2][i]+a[3][j]);
    }
  }
  sort(x.begin(),x.end());
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      long long h = -1*(a[0][i]+a[1][j]);
      long long low = lower_bound(x.begin(),x.end(),h)-x.begin();
      long long up = upper_bound(x.begin(),x.end(),h)-x.begin();
      if(h==x[low]){
        cnt+=up-low;
      }
    }
  }
  cout<<cnt;
  return 0;
}
