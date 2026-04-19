#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#define maxN 1000005
using namespace std;
int main(){
  cin.tie(0);
  cout.tie(0);
  int n,k,cnt = 0;
  cin>>n>>k;
  int a[1001][1001]={0};
  for(int i = 0;i<n;i++){
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    for(int i = x1;i<x2;i++){
      a[i][y1]++;
      a[i][y2]--;
    }
  }
  for(int i = 0;i<1000;i++){
    for(int j = 0;j<1000;j++){
      if(a[i][j]==k) cnt++;
      a[i][j+1] += a[i][j];
    }
  }
  cout<<cnt;
  return 0;
}
