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
int point(char a){
  int num = a;
  if(num>=48&&num<=57){
      return a-'0';
  }
  else if(a=='-'){
    return 0;
  }
  else if(a=='S'){
    return 10;
  }
  else if(a=='P'){
    return 10;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  getline(cin,s);
  int score[25] = {0};
  int yes[25]={0};
  int frame = 1;
  int chance = -1;
  int cur = 0;
  for(int i = 0;i<s.size();i++){
    int x = point(s[i]);
    if(frame>20){
      score[frame] = x;
      frame++;
    }
    else if(chance==-1&&x==10){
      yes[frame] = 2;
      score[frame] = 10;
      frame++;
      score[frame] = 0;
      frame++;
    }
    else if(chance==1&&x==10){
      yes[frame] = 1;
      score[frame] = 10-score[frame-1];
      chance*=-1;
      frame++;
    }
    else{
      score[frame] = x;
      chance*=-1;
      frame++;
    }
  }
  for(int i = 1;i<=20;i++){
    cur+=score[i];
  }
  for(int i = 1;i<=18;i++){
    int ref = i;
    if(yes[i]==1){
      cur+=score[ref+1];
    }
    else if(yes[i]==2){
      ref+=2;
      cur+=score[ref];
      ref++;
      if(score[ref-1]==10){
        ref++;
      }
      cur+=score[ref];
    }
  }
  if(yes[19]==2){
    if(score[22]==10&&score[21]!=10){
      cur+=10;
    }
    else{
      cur+=score[21];
      cur+=score[22];
    }
  }
  if(yes[20]==1){
    cur+=score[21];
  }
  cout<<cur;
  return 0;
}
