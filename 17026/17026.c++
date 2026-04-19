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
struct mountain{
  int start;
  int end;
};
bool cmp(mountain x,mountain y){
  if(x.start==y.start) return x.end>y.end;
  else return x.start<y.start;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  vector<mountain> a;
  for(int i = 0;i<n;i++){
    int q,w;
    cin>>q>>w;
    a.push_back({q-w,q+w});
  }
  sort(a.begin(),a.end(),cmp);
  long long cnt = 0, len = -1;
  for(int i = 0;i<n;i++){
    if(a[i].end>len){
      len = a[i].end;
      cnt++;
    }
  }
  cout<<cnt;
  return 0;
}
