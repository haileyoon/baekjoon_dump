#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;
int n;
int k;
vector<pair<int,int>> x[101];
int indegree[101]={0};
int ans[101]={0};
void find(){
    queue<int>q;
    int part[101][101];
    for(int i = 1;i<=n;i++){
        if(indegree[i]==0){
            part[i][i] = 1;
            q.push(i);
        }
    }
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i = 0;i<x[temp].size();i++){
            int after = x[temp][i].first;
            int num = x[temp][i].second;
            for(int j = 1;j<=n;j++){
                part[j][after]+=part[j][temp]*num;
            }
            indegree[after]--;
            if(indegree[after]==0){
                q.push(after);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        ans[i] = part[n][i];
    }
}
int main(){
    cin>>n>>k;
    for(int i = 0;i<k;i++){
        int a,b,c;
        cin>>a>>b>>c;
        x[a].push_back({b,c});
        indegree[b]++;
    }
    find();
    for(int i = 1;i<=n;i++){
        if(ans[i]!=0&&x[i].size()==0){
            cout<<i<<" "<<ans[i]<<"\n";
        }
    }
    return 0;
}
