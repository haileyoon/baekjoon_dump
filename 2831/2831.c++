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
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,cnt = 0;
  cin>>n;
  vector<int> bpos;
  vector<int> gpos;
  vector<int> bneg;
  vector<int> gneg;
  for(int i = 0;i<n;i++){
    int p;
    cin>>p;
    if(p>0)bpos.push_back(p);
    if(p<0)bneg.push_back(abs(p));
  }
  for(int i = 0;i<n;i++){
    int q;
    cin>>q;
    if(q>0)gpos.push_back(q);
    if(q<0)gneg.push_back(abs(q));
  }
  sort(bpos.begin(),bpos.end());
  sort(bneg.begin(),bneg.end());
  sort(gpos.begin(),gpos.end());
  sort(gneg.begin(),gneg.end());
  int a = 0,b = 0;
  while(a<bpos.size()&&b<gneg.size()){
    if(bpos[a]<gneg[b]){
      cnt++;
      a++;
    }
    b++;
  }
  a = 0;
  b = 0;
  while(a<bneg.size()&&b<gpos.size()){
    if(bneg[a]>gpos[b]){
      cnt++;
      b++;
    }
    a++;
  }
  cout<<cnt;
  return 0;
}
