#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
int n;
int a[11][11] = {0};
int num[11] = {0};
int type[11]={0};
void go(int x){
    int up = 1e9, low = 0,r = 0,l = 1e9;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(a[i][j]==x){
                l = min(l,j);
                r = max(r,j);
                up = min(up,i);
                low = max(low,i);
            }
        }
    }
    for(int i = up;i<=low;i++){
        for(int j = l;j<=r;j++){
            if(a[i][j]!=x){
                type[a[i][j]] = 0;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt = 0;
    cin>>n;
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        for(int j = 0;j<s.size();j++){
            a[i][j] = s[j]-'0';
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(a[i][j]>0&&num[a[i][j]]==0){
                num[a[i][j]] = 1;
                type[a[i][j]] = 1;
            }
        }
    }
    for(int i = 1;i<10;i++){
        if(num[i]){
            go(i);
        }
    }
    for(int i = 1;i<10;i++){
        if(type[i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
