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
struct coords{
  long long num;
  long long x1;
  long long x2;
  long long y;
};
bool cmp(coords q,coords w){
  if(q.x1!=w.x1){
    return q.x1<w.x1;
  }
  else if(q.x2!=w.x2){
    return q.x2<w.x2;
  }
  else if(q.y!=w.y){
    return q.y<w.y;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n,m;
  coords a[100001]={0};
  long long teamnum[100001]={0};
  cin>>n>>m;
  for(int i = 1;i<=n;i++){
    cin>>a[i].x1>>a[i].x2>>a[i].y;
    a[i].num = i;
  }
  sort(&a[1],&a[n+1],cmp);
  long long end = 0,team = 0;
  for(int i = 1;i<=n;i++){
    if(end<a[i].x1){
      team++;
      end = a[i].x2;
    }
    else{
      if(a[i].x2>end) end = a[i].x2;
    }
    teamnum[a[i].num] = team;
  }
  for(int i = 0;i<m;i++){
    long long x,y;
    cin>>x>>y;
    if(teamnum[x]==teamnum[y]){
      cout<<"1"<<"\n";
    }
    else{
      cout<<"0"<<"\n";
    }
  }
  return 0;
}
