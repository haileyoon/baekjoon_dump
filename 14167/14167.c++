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
int n;
bool visited[1001];
struct coords{
  long long x;
  long long y;
};
coords a[10001];
void dfs(long long k,long long p){
  visited[k] = true;
  for(int i = 0;i<n;i++){
    long long dist1 = a[k].x-a[i].x; 
    long long dist2 = a[k].y-a[i].y;
    long long dist = dist1*dist1+dist2*dist2;
    if(!visited[i]&&dist<=p){
      dfs(i,p);
    }
  }
}
int main(){
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i = 0;i<n;i++){
    cin>>a[i].x>>a[i].y;
  }
  long long l = 0,h = 2*25000*25000,m;
  while(l<h){
    m = (l+h)/2;
    for(int i = 0;i<1001;i++){
      visited[i] = false;
    }
    dfs(0,m);
    bool tf = false;
    for(int i = 0;i<n;i++){
      if(!visited[i]){
        tf = true;
        break;
      }
    }
    if(tf) l = m+1;
    else h = m;
  }
  cout<<h;
}
