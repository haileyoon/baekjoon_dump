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
  long long a[100001]={0};
  for(int i = 0;i<n;i++){
    cin>>a[i];  
  }
  long long l = 0,h = n-1,x,y,ans = 10000000000;
  while(l<h){
    int m = a[l]+a[h];
    if(ans>=abs(m)){
      x = a[l];
      y = a[h];
      ans = abs(m);
    }
    if(m>0){
      h--;
    }
    else {
      l++;
    }
  }
  cout<<x<<" "<<y;
}
