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
int a[101][100]={0};
int visited[101][100] = {0};
int movex[4]={-1,0,1,0};
int movey[4]={0,1,0,-1};
int n,k,cnt = 0;
void gravity(){
  for(int i = n-1;i>=0;i--){
    for(int j = 10;j>=0;j--){
      int h = i;
      while(a[h+1][j]==0&&h+1<n&&a[h][j]>0){
        h++;
        swap(a[h][j],a[h-1][j]);
      }
    }
  }
}
int connected(int x,int y,int c){
  int cnt = 1;
  int color = a[x][y];
  visited[x][y] = 1;
  for(int i = 0;i<4;i++){
    int xx = x+movex[i];
    int yy = y+movey[i];
    if(xx<0||yy<0||xx>=n||yy>=10){
      continue;
    }
    if(a[xx][yy]==color&&visited[xx][yy]==0) cnt+=connected(xx,yy,c);
  }
  if(c) a[x][y] = 0;
  return cnt;
}
void clear_visited(){
  for(int i = 0;i<n;i++){
    for(int j = 0;j<10;j++){
      visited[i][j] = 0;
    }
  }
}
bool check(){
  clear_visited();
  bool yn = false;
  for(int i = 0;i<n;i++){
      for(int j = 0;j<10;j++){
        if(a[i][j]>0&&!visited[i][j]){
          if(connected(i,j,0)>=k){
            clear_visited();
            yn = true;
            connected(i,j,1);
          }
        }
      }
    }
    return yn;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>k;
  for(int i = 0;i<n;i++){
    string b;
    cin>>b;
    for(int j = 0;j<10;j++){
      a[i][j] = b[j]-48;
    }
  }
  while(check()){
    gravity();
  }
  for(int i = 0;i<n;i++){
    for(int j = 0;j<10;j++){
      cout<<a[i][j];
    }
    cout<<"\n";
  }
  return 0;
}
