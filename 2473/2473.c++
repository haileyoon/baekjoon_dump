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
  int n;
  cin>>n;
  long long fin1 = 0,fin2 = 0,fin3 = 0,diff = 20000000001;
  vector<long long> a;
  for(int i = 0;i<n;i++){
    int p;
    cin>>p;
    a.push_back(p);
  }
  sort(a.begin(),a.end());
  for(int i = 0;i<n;i++){
    long long l = 0,h = n-1;
    if(i==0) l = 1;
    if(i==n-1) h = n-2;
    long long temp = 0;
    while(l<h){
      temp = a[l]+a[i]+a[h];
      if(abs(temp)<diff){
        diff = abs(temp);
        fin1 = a[l];
        fin2 = a[i];
        fin3 = a[h];
      }
      if(temp<0){
        l++;
        if(l==i) l++;
      }
      else{
        h--;
        if(h==i) h--;
      }
    }
  }
  long long b[3] = {fin1,fin2,fin3};
  sort(&b[0],&b[3]);
  for(int i = 0;i<3;i++){
    cout<<b[i];
    if(i<2)cout<<" ";
  }
  return 0;
}
