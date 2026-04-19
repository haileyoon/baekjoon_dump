#include <iostream>
#include <queue>
using namespace std;
struct Tomato {
    int x, y, day;
};
int main() {
    int M, N;
    cin >> M >> N;

    int box[1000][1000];
    queue<Tomato> q;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                q.push({i, j, 0});
            }
        }
    }

    int maxDay = 0;
    while (!q.empty()) {
        Tomato t = q.front();
        q.pop();
        maxDay = t.day;

        for (int i = 0; i < 4; ++i) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && box[nx][ny] == 0) {
                box[nx][ny] = 1;
                q.push({nx, ny, t.day + 1});
            }
        }
    }
    bool unripeTomatoes = false;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (box[i][j] == 0) {
                unripeTomatoes = true;
                break;
            }
        }
    }

    if (unripeTomatoes) {
        cout << -1 << endl;
    } else {
        cout << maxDay << endl;
    }

    return 0;
}
