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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count=0;
    int repeat=1;
    if ((n > 2) && (s != "00")){
      for(int i=0;i<n;i++){
        if(s[i]=='1'){
          count ++;
        }
        if((s[i] == s[i+1]) && (i != n-1) && (s[i]=='1')){
          repeat=0;
        }
      }
      if(((count % 2) == 0) && (count > 2)){
        cout << "YES";
      }
      else if(count == 0){
        cout << "YES";
      }
      else if((count == 2) && (repeat == 1)){
        cout << "YES";
      }
      else{
        cout << "NO";
      }
      
    }
    else if((s=="00") || (s == "0")){
      cout << "YES";
    }
    else{
      cout << "NO";
    } 
    cout <<endl;
     }
  }


