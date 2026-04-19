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
  long long int n,k,cnt = 0;
  cin>>n>>k;
  long long int a[1001]={0},sum = 0;
  for(int i = 0;i<n;i++){
    int x;
    cin>>x;
    sum+=x;
    a[sum%k]++;
  }
  for(int i = 0;i<=1000;i++){
    cnt += (a[i]*(a[i]-1))/2;
  }
  cout<<cnt+a[0];
  return 0;
}
