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
int n;
vector<int>a[55];
int dfs(int k) {
	if (a[k].empty()) {
		return 1;
	}
	vector<int>b;
	for (int i = 0; i < a[k].size(); i++) {
		b.push_back(dfs(a[k][i]) + 1);
	}
	sort(b.begin(), b.end(), greater<int>());
	int ans = 0;
	for (int i = 0; i < b.size(); i++) {
		ans = max(ans, b[i] + i);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (i == 0) continue; 
		a[v[i]].push_back(i);
	}
	cout << dfs(0) - 1 << "\n";
}
