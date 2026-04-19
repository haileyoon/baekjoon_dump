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
bool check = true;
int n,k,cnt = 0;
vector<int> s[100001],d[100001];
int graph[100001]={0};
void connect(int w,int q){
  graph[w] = q;
  for(int i = 0;i<s[w].size();i++){
    if(graph[s[w][i]]==0) connect(s[w][i],q);
    if(graph[s[w][i]]==3-q) check = false;
  }
  for(int i = 0;i<d[w].size();i++){
    if(graph[d[w][i]]==0) connect(d[w][i],3-q);
    if(graph[d[w][i]]==q)check = false;
  }
}
int main(){
  cin.tie(0);
  cout.tie(0);
  string r;
  cin>>n>>k;
  int num = 1;
  for(int i = 0;i<k;i++){
    char c;
    int q,w;
    cin>>c>>q>>w;
    if(c=='D'){
      d[q].push_back(w);
      d[w].push_back(q);
    }
    else if(c=='S'){
      s[q].push_back(w);
      s[w].push_back(q);
    }
  }
  for(int i = 1;i<=n;i++){
    if(!graph[i]){
      connect(i,1);
      cnt++;
    }
  }
  if(check){
    r = '1';
    for(int i = 0;i<cnt;i++){
      r+='0';
    }
    cout<<r;
  }
  else cout<<'0';
  return 0;
}
