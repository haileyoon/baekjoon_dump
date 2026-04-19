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
int main(){
  long long int q,cnt = 0,num,ans = 0;
  cin>>q;
  long long int a[q+1]={0},b[q+1]={0};
  for(int i = 1;i<=q;i++){
    cin>>num;
    cnt +=num;
    a[i] = cnt%7;
    if(a[i]==0){
      long long int k = i;
      ans = max(ans,k);
    }
    if(b[a[i]]!=0){
      ans = max(ans,i - b[a[i]]);
    }
    else{
      b[a[i]]=i;
    }
  }
  cout<<ans;
  return 0;
}
