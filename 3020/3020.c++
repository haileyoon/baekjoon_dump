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
  int ans = 1e9+1,cnt = 0;
  cin>>n>>k;
  vector<int> a;
  vector<int> b;
  for(int i = 0;i<n/2;i++){
    int p,q;
    cin>>p>>q;
    q = k-q;
    a.push_back(p);
    b.push_back(q);
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  for(int i = 0;i<k;i++){
    int num = 0;
    int down = a.size() - (upper_bound(a.begin(), a.end(), 0.5+i) - a.begin());
    int up = upper_bound(b.begin(), b.end(), 0.5+i) - b.begin();
    num = down+up;
    if(num<ans){
      cnt = 1;
      ans = num;
    }
    else if(ans==num){
      cnt++;
    }
  }
  cout<<ans<<" "<<cnt;
  return 0;
}
