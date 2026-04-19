#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  string s;
  string t;
  int cnt = 0;
  
  cin >> s >> t;
  
  while(t.size() > s.size()){
    if(t[t.size()-1] == 'A'){
      t.pop_back();
    }
    else{
      t.pop_back();
      reverse(t.begin(), t.end());
    }
  }
  
  
  if(t==s){
    cout << 1;
  }
  else{
    cout << 0;
  }
}
