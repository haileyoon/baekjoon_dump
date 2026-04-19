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
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n,k;
  vector<long long> a;
  cin>>n>>k;
  for(int i = 0;i<n;i++){
    long long p;
    cin>>p;
    a.push_back(p);
  }
  sort(a.begin(),a.end());
  long long l = 0,h = 0,curr = 2000000001;
  while(l<n&&h<n){
    if(a[h]-a[l]>=k){
      curr = min(curr,a[h]-a[l]);
      l++;
    }
    else{
      h++;
    }
  }
  cout<<curr;
  return 0;
}
