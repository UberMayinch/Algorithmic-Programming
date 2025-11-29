#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int counter=-1;
    int sum=0;
    int flag=0;
    vector <int> v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }   
    sort(v.begin(), v.end());
    bool turn = true;
    int win=2;
    if(v[0] > 1){
      win = 1;
    }

    for(int i=1;i<n;i++){
      if(v[i-1] - v[i] == 1){
        turn = !turn;
      }
      else if(v[i-1] - v[i] > 1){

        win = turn;
      }
    }

    // cout << count << endl;
    if(win == 1){
      cout << "Alice" << endl;
    }
    else if(win == 0){
      cout << "Bob" << endl;
    }
    else{
      cout << (turn ? "Alice" : "Bob") << endl;

    }
  }
}
