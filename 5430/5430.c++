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
  int w;
  cin>>w;
  for(int i = 0;i<w;i++){
    deque<int> q;
    string s,x,temp;
    int a;
    cin>>s>>a>>x;
    for(int j = 0;j<x.length();j++){
      if(x[j]=='[') continue;
      if(x[j]>='0'&&x[j]<='9'){
        temp+=x[j];
      }
      if(x[j]==','||x[j]==']'){
        if(!temp.empty()){
          q.push_back(stoi(temp));
          temp.clear();
        }
      }
    }
    bool reverse = true;
    bool error = true;
    for(int j = 0;j<s.length();j++){
      if(s[j]=='R'){
        reverse=!reverse;
      }
      else{
        if(q.empty()){
          error = false;
          cout<<"error\n";
          break;
        }
        else{
          if(reverse){
            q.pop_front();
          }
          else{
            q.pop_back();
          }
        }
      }
    }
    if(error){
      if(reverse){
        cout<<"[";
        while(!q.empty()){
          cout<<q.front();
          q.pop_front();
          if(!q.empty()){
            cout<<",";
          }
        }
        cout<<"]";
        cout<<"\n";
      }
      else{
        cout<<"[";
        while(!q.empty()){
          cout<<q.back();
          q.pop_back();
          if(!q.empty()){
            cout<<",";
          }
        }
        cout<<"]";
        cout<<"\n";
      }
    }
  }
  return 0;
}
