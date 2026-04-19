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
  int n;
  cin>>n;
  vector<pair<int,int>> a;
  priority_queue<int,vector<int>,greater<int>> curr;
  for(int i = 0;i<n;i++){
    int p,q;
    cin>>p>>q;
    a.push_back({p,q});
  }
  sort(a.begin(),a.end());
  curr.push(a[0].second);
  for(int i = 1;i<n;i++){
  curr.push(a[i].second);
    if(curr.top()<=a[i].first){
      curr.pop();
    }
  }
  cout<<curr.size();
  return 0;
}
