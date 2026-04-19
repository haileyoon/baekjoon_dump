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
int n,k;
vector<int> a;
int check(){
  int x = a.size();
  while(x>0&&a[x-1]<x) x--;
  return x;
}
int main(){
  cin>>n>>k;
  for(int i = 0;i<n;i++){
    int p;
    cin>>p;
    a.push_back(p);
  }
  sort(begin(a),end(a),greater<int>());
  int y = check();
  if(y<n){
    for(int i = y;i>=max(0,y-k+1);i--){
      a[i]++;
    }
  }
  sort(begin(a),end(a),greater<int>());
  cout<<check();
}
