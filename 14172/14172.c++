#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#define maxN 1000005
using namespace std;
struct cow{
  int x;
  int y;
  int power;
};
int n,ans = 0;
cow a[201]={0};
int visited[201]={0};
void clear(){
  for(int i = 0;i<=200;i++){
    visited[i] = 0;
  }
}
int dfs(int num){
  int cnt = 0;
  visited[num]= 1;
  for(int i = 0;i<n;i++){
    int xdiff = a[num].x-a[i].x;
    int ydiff = a[num].y-a[i].y;
    if(a[num].power>=xdiff*xdiff+ydiff*ydiff&&visited[i]==0){
      cnt++;
      cnt+=dfs(i);
    }
  }
  return cnt;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i = 0;i<n;i++){
    int x1,y1,power1;
    cin>>x1>>y1>>power1;
    power1=power1*power1;
    a[i].x = x1;
    a[i].y = y1;
    a[i].power = power1;
  }
  for(int i = 0;i<n;i++){
    int cnt = dfs(i);
    clear();
    ans = max(cnt,ans);
  }
  cout<<ans+1;
  return 0;
}
