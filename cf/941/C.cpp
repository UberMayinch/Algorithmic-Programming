#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int turn=1;
    int counter=-1;
    int sum=0;
    int flag=0;
    vector <int> v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }   
    sort(v.begin(), v.end());
    int idx=0;
    while((idx < n) && (v[idx]-sum >0)){
      if((v[idx] - sum > 1)&&(flag != 1)){
        counter = turn;
        flag=1;
        // cout << counter << " " << v[0]-sum << endl;
        }
      turn=1-turn;
      sum +=v[idx]-sum;
      idx++;
      // cout << sum << " " << turn;
    }
    if(counter == 0){
      cout << "Bob";
    }
    else if(counter == 1){
      cout << "Alice";
    }
    else if(turn == 1){
      cout << "Bob";
    }
    else if(turn == 0){
      cout << "Alice";
    }
  cout << endl;
  }
}
