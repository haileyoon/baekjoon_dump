#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <deque>
using namespace std;
char a[11][11];
int N, num = 0, cnt = 0;
string s;
vector<int> v(21);
vector<char> number;
vector<int> ans(11);
vector<vector<int>> ff;
void start() {
    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 11; j++){
            a[i][j] = ' ';
        }
    }
    for (int i = 0; i <= 20; i++){
        v[i] = i - 10;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i <= j){
                a[i][j] = s[num++];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) number.push_back(a[i][j]);
        }
    }
}

bool good(int index) {
    int sum = 0;
    for (int i = index; i >= 0; i--) {
        sum += ans[i];
        if (a[i][index] == '0') {
            if (sum != 0) return false;
        }
        else if (a[i][index] == '-') {
            if (sum >= 0) return false;
        }
        else if (a[i][index] == '+') {
            if (sum <= 0) return false;
        }
    }
    return true;
}

bool search(int index) {
    if (index == N) {
        return true;
    }
    if (number[index] == '-') {
        for (int i = 0; i <= 9; i++) {
            ans[index] = v[i];
            if (good(index) && search(index + 1)) return true;
        }
    }
    else if (number[index] == '0') {
        ans[index] = 0;
        return good(index) && search(index + 1);
    }
    else if (number[index] == '+') {
        for (int i = 11; i <= 20; i++) {
            ans[index] = v[i];
            if (good(index) && search(index + 1)) return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> s;
    start();
    search(0);
    for (int i = 0; i < N; i++) cout << ans[i] << " ";
}
