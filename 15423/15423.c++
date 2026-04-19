#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
int optimal_solution(vector<int> & memo, const vector<int> & coins, int S) {
	if (S < 0) {
		return INF;
	}
	if (memo[S] > -1)
		return memo[S];

	int min_coins = optimal_solution(memo, coins, S - coins[0]) + 1;
	for (int i = 1; i < coins.size(); ++i) {
		min_coins = min(min_coins, optimal_solution(memo, coins, S - coins[i]) + 1);
	}

	return memo[S] = min_coins;
}

int greedy_solution(vector<int> & memo, const vector<int> & coins, int S) {
	if (memo[S] > -1)
		return memo[S];

	for (int i = coins.size() - 1; i > -1; --i) {
		if (S >= coins[i]) {
			//and repeat
			return memo[S] = greedy_solution(memo, coins, S - coins[i]) + 1;
		}
	}
	return 0;
}

int main() {
	int n;
	cin >> n;
	vector<int> coins(n);
	for (int i = 0; i < n; ++i) {
		cin >> coins[i];
	}
	vector<int> memo1(coins[n - 1] + coins[n - 2], -1);
	vector<int> memo2(coins[n - 1] + coins[n - 2], -1);

	memo1[0] = memo2[0] = 0;

	bool is_con = true;

	for (int i = 1; i < memo1.size(); ++i) {
		if (greedy_solution(memo2, coins, i) !=
			optimal_solution(memo1, coins, i)) {
			is_con = false;
			break;
		}
	}

	if (is_con)
		cout << "canonical" << endl;
	else
		cout << "non-canonical" << endl;

	return 0;
}
