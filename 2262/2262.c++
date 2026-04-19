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
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,ans = 0;
  int a[258]={0};
  int deleted[258]={0};
  vector<int> num;
  cin>>n;
  num.push_back(1e9);
  for(int i = 1;i<=n;i++){
    int p;
    cin>>p;
    a[p] = i;
    num.push_back(p);
  }
  num.push_back(1e9);
  for(int i = n;i>1;i--){
    int xx = a[i]+1;
    int yy = a[i]-1;
    while(deleted[xx]){
      xx = xx+1;
    }
    while(deleted[yy]){
      yy = yy-1;
    }
    ans += min(abs(num[a[i]]-num[xx]),abs(num[a[i]]-num[yy]));
    deleted[a[i]] = 1;
  }
  cout<<ans;
  return 0;
}
