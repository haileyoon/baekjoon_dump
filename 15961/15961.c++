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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, d, k, c;
  vector<int> sushi;
  int num[3001]={0};
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
	    int p;
		cin >> p;
		sushi.push_back(p);
	}
	int l = 0;
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		if (num[sushi[i]]==0) {
			cnt++;
		}
		num[sushi[i]]++;
	}
	int ans = cnt;
	while (l <= n) {
		if (num[c]==0) {
			ans = max(ans, cnt+1);
		}
		else{
			ans = max(ans, cnt);
		}
		if (!num[sushi[(l + k) % n]]++) {
			cnt++;
		}
		if (--num[sushi[l]]==0) {
			cnt--;
		}
		l++;
	}
	cout << ans;
	return 0;
}
