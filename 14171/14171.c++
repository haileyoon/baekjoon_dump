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
  int n,cnt = 0;
  cin>>n;
  map<pair<string,string>,int> a;
  for(int i = 0;i<n;i++){
    string s,r,state;
    cin>>s>>r;
    state+=s[0];
    state+=s[1];
    if(r==state) continue;
    a[{r,state}]++;
    cnt+=a[{state,r}];
  }
  cout<<cnt;
  return 0;
}
