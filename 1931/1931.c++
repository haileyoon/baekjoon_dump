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
struct meeting{
  long long start;
  long long end;
};
bool cmp(meeting x,meeting y){
  if(x.end!=y.end){
    return x.end<y.end;
  }
  else{
    return x.start<y.start;
  }
}
int main(){
  cin.tie(0);
  cout.tie(0);
  long long cnt = 0;
  int n;
  cin>>n;
  meeting a[n] = {0};
  for(int i = 0;i<n;i++){
    cin>>a[i].start>>a[i].end;
  }
  sort(&a[0],&a[n],cmp);
  long long curr = a[0].end;
  for(int i = 1;i<n;i++){
    if(curr<=a[i].start){
      curr = a[i].end;
      cnt++;
    }
  }
  cout<<cnt+1;
  return 0;
}
