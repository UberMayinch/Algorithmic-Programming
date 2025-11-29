#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s="";
    int flag=0;
    int guessed = 0;
    while(guessed < n){
      int sub = 0;
      if(!flag){
      cout << "? " << s + "0"<< endl;
      cin >> sub;
      if(sub){
          s += "0";
          guessed++;
          continue;
      }
      else{
      cout << "? " << s +"1" << endl;
          cin >> sub;
        if(sub){
            s += "1";
          guessed++;
            continue;
        }
      
      else{
        flag =1;
      }
        }
      }
    else if(flag){
      cout << "? " << "0" + s << endl;
      cin >> sub;
      if(sub){
          s = "0"+s;
          guessed++;
        }
      else{
          s = "1"+s;
          guessed++;
        }
        continue;
    }
    }
    cout << "! " << s << endl;
  }

}


