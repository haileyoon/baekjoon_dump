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
int test[101][101][101]={0};
int k,m,curr = 10000000,a,b;
void dfs(int x,int y,int num){
  if(num>k||test[x][y][num]){
    return;
  }
  test[x][y][num] = 1;
  curr = min(curr,abs(m-(x+y)));
  dfs(a,y,num+1);
  dfs(x,b,num+1);
  dfs(x,0,num+1);
  dfs(0,y,num+1);
  int xx = 0;
  int yy = 0;
  if(x+y>b){
    xx = x+y-b;
  }
  if(x+y>a){
    yy = x+y-a;
  }
  dfs(xx,min(b,x+y),num+1);
  dfs(min(a,x+y),yy,num+1);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>a>>b>>k>>m;
  dfs(0,0,0);
  cout<<curr;
  return 0;
}
