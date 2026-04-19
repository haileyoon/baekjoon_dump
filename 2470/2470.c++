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
int main(){
  cin.tie(0);
  cout.tie(0);
  int n, ans = 2000000001;
  vector<int> a;
  cin>>n;
  for(int i = 0;i<n;i++){
    int p;
    cin>>p;
    a.push_back(p);
  }
  sort(a.begin(),a.end());
  long long x = -100000000000,y = 100000000000;
  int l = 0,h = n-1,sum;
  while (l < h) {
		sum = a[l]+a[h];
		if (ans > abs(sum)) {
			ans = abs(sum);
			x = a[l];
			y = a[h];
		}
		if (sum > 0)h--;
		else l++;
	}
	cout<<x<<" "<<y;
  return 0;
}
