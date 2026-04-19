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
  int number;
  int arrive;
  int eat;
};
bool cmp(cow x, cow y){
  if(x.arrive!=y.arrive){
    return x.arrive<y.arrive;
  }
  else return x.number<y.number;
}
bool xyz(cow x, cow y){
  return x.number>y.number;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,ans = 0;
  cin>>n;
  priority_queue<cow,vector<cow>,decltype(&xyz)> waiting(&xyz);
  cow a[n]={0};
  for(int i = 0;i<n;i++){
    cin>>a[i].arrive>>a[i].eat;
    a[i].number = i+1;
  }
  sort(&a[0],&a[n],cmp);
  int curr = 0;
  int i = 1;
  curr = a[0].arrive+a[0].eat;
  while(i<n||waiting.size()>0){
    while(a[i].arrive<curr&&i<n){
      waiting.push(a[i]);
      i++;
    }
    if(waiting.size()==0&&i<n){
      curr+=(a[i].arrive-curr)+a[i].eat;
      i++;
    }
    if(waiting.size()>0){
      ans = max(ans,curr-waiting.top().arrive);
      curr+=waiting.top().eat;
      waiting.pop();
    }
  }
  cout<<ans;
  return 0;
}
