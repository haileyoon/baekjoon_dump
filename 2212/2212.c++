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
  vector<int> a;
  int b[100001]={0};
  int n,k,ans = 0;
  cin>>n>>k;
  for(int i = 0;i<n;i++){
    int p;
    cin>>p;
    a.push_back(p);
  }
  sort(a.begin(),a.end());
  for(int i = 0;i<n-1;i++){
    b[i] = a[i+1]-a[i];
  }
  sort(&b[0],&b[n-1]);
  for(int i = 0;i<n-k;i++){
    ans+=b[i];
  }
  cout<<ans;
  return 0;
}
