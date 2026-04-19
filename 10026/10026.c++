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
int a[101][101]={0};
int visited[101][101]={0};
int n,cnt = 0;
int ax[4]={-1,0,1,0};
int ay[4]={0,1,0,-1};
void dfs1(int y, int x){
  int color;
  visited[y][x]=1;
  color = a[y][x];
  for(int i = 0;i<4;i++){
    int xx = ax[i]+x;
    int yy = ay[i]+y;
    if(xx<0||yy<0||xx>=n||yy>=n){
      continue;
    }
    if(visited[yy][xx]==0&&a[yy][xx]==color){
      dfs1(yy,xx);
    }
  }
}
int main(){
  cin>>n;
  vector <int> num;
  for(int i = 0;i<n;i++){
    string k;
    cin>>k;
    for(int j = 0;j<n;j++){
      if(k[j]=='R'){
        a[i][j]=1;
      }
      else if(k[j]=='B'){
        a[i][j]=2;
      }
      else if(k[j]=='G'){
        a[i][j]=3;
      }
    }
  }
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      if(visited[i][j]==0){
        dfs1(i,j);
        cnt++;
      }
    }
  }
  cout<<cnt<<" ";
  cnt = 0;
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      visited[i][j] = 0;
      if(a[i][j]==3){
        a[i][j] = 1;
      }
    }
  }
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      if(visited[i][j]==0){
        dfs1(i,j);
        cnt++;
      }
    }
  }
  cout<<cnt;
  return 0;
}
