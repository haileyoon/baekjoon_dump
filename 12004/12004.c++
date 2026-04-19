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
int visited[3001]={0};
int list[3001]={0};
int closed[3001]={0};
vector<int> a[3001];
void dfs(int x){
  visited[x] = 1;
  for(int i = 0;i<a[x].size();i++){
    if(!visited[a[x][i]]&&!closed[a[x][i]]) dfs(a[x][i]);
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,k;
  cin>>n>>k;
  for(int i = 0;i<k;i++){
    int p,q;
    cin>>p>>q;
    a[q].push_back(p);
    a[p].push_back(q);
  }
  string truth = "YES";
  dfs(1);
  for(int i = 1;i<=n;i++){
    if(!visited[i]){
      truth = "NO";
    }
  }
  cout<<truth<<"\n";
  truth = "YES";
  for(int i = 0;i<n;i++){
    cin>>list[i];
  }
  for(int i = 0;i<n-1;i++){
    for(int i = 0;i<3001;i++){
      visited[i] = 0;
    }
    closed[list[i]] = 1;
    dfs(list[n-1]);
    for(int i = 1;i<=n;i++){
      if(!visited[i]){
        if(!closed[i]){
          truth = "NO";
        }
      }
    }
    cout<<truth<<"\n";
    truth = "YES";
  }
  return 0;
}
