#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;

#define pushback PB

void solve(){

}

int main(){
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    if (stoi(s.substr(0, 2)) > 12){
        cout << setfill('0') << setw(2) << stoi(s.substr(0,2)) - 12;
        cout << ":" << s.substr(3, 5) << " PM";
        }
    else if(stoi(s.substr(0,2))== 12){
      cout << s << " PM";
    }
    else if(stoi(s.substr(0,2)) == 0){
        cout << setfill('0') << setw(2) << stoi(s.substr(0,2))+12;
        cout << ":" << s.substr(3, 5) << " AM";
    }
    else {
    cout << s << " AM";
    }
    cout << endl;
  }

}

