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
  int n,k,ans = 0;
  cin>>n>>k;
  vector<pair<int,int>> a;
  for(int i = 0;i<n;i++){
    int q,p;
    cin>>q>>p;
    a.push_back({q,p});
  }
  int curr = 0;
  sort(a.begin(),a.end());
  for(int i = 0;i<n;i++){
    int xx = a[i].first;
    int yy = a[i].second;
    if(xx<curr){
      xx = curr;
    }
    ans+=(yy-xx)/k;
    if((yy-xx)%k>0){
      ans++;
      curr = xx+(((yy-xx)/k)+1)*k;
    }
  }
  cout<<ans;
  return 0;
}
