#include <iostream>
#include <vector>
using namespace std;

int n, k, cnt = 1;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int visited[101][101] = {0};
int lighted[101][101] = {0};
vector<pair<int, int>> a[101][101];

bool connected(int o, int p) {
    for (int i = 0; i < 4; i++) {
        int xx = p + dx[i];
        int yy = o + dy[i];
        if (xx > n || yy > n || xx < 1 || yy < 1)
            continue;
        if (visited[yy][xx]) {
            return true;
        }
    }
    return false;
}

void dfs(int o, int p) {
    if (o > n || p > n || o < 1 || p < 1 || visited[o][p] || !lighted[o][p]) {
        return;
    }
    if (!connected(o, p) && !(o == 1 && p == 1)) {
        return;
    }
    visited[o][p] = 1;
    for (int i = 0; i < 4; i++) {
        int xx = p + dx[i];
        int yy = o + dy[i];
        dfs(yy, xx);
    }
    for (int i = 0; i < a[o][p].size(); i++) {
        int xx = a[o][p][i].second;
        int yy = a[o][p][i].first;
        if (!lighted[yy][xx])
            cnt++;
        lighted[yy][xx] = 1;
        dfs(yy, xx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1].push_back({x2, y2});
    }
    lighted[1][1] = 1;
    dfs(1, 1);
    cout << cnt;
    return 0;
}
