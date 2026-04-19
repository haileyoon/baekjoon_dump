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
int a[1001][1001]={0};
int visited[1001][1001]={0};
int n,cnt = 0,per = 0;
int ax[4]={-1,0,1,0};
int ay[4]={0,1,0,-1};
void dfs(int y, int x){
  visited[y][x]=1;
  a[y][x] = 1;
  cnt++;
  for(int i = 0;i<4;i++){
    int xx = ax[i]+x;
    int yy = ay[i]+y;
    if(xx<0||yy<0||xx>=n||yy>=n){
      if(xx<0||xx>=n){
        per++;
        if(xx<0&&xx>=n){
          per++;
        }
      }
      if(yy<0||yy>=n){
        per++;
        if(yy<0&&yy>=n){
          per++;
        }
      }
      continue;
    }
    if(visited[yy][xx]==0&&a[yy][xx]==0){
      per++;
    }
  }
  for(int i = 0;i<4;i++){
    int xx = ax[i]+x;
    int yy = ay[i]+y;
    if(xx<0||yy<0||xx>=n||yy>=n){
      continue;
    }
    if(visited[yy][xx]==0&&a[yy][xx]==1){
      dfs(yy,xx);
    }
  }
}
int main(){
  int area = 0,perimeter = 0;
  cin>>n;
  vector <int> num;
  for(int i = 0;i<n;i++){
    string k;
    cin>>k;
    for(int j = 0;j<n;j++){
      if(k[j]=='.'){
        a[i][j] = 0;
      }
      else if(k[j]=='#'){
        a[i][j] = 1;
      }
    }
  }
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      if(visited[i][j]==0&&a[i][j]==1){
        per = 0;
        cnt = 0;
        dfs(i,j);
        if(cnt>area){
          area = cnt;
          perimeter = per;
        }
        else if(cnt == area){
          if(per<perimeter){
            perimeter = per;
          }
        }
      }
    }
  }
  cout<<area<<" "<<perimeter;
  return 0;
}
