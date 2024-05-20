#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define push_back pb
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
    string s;
    cin >> s;
    vi dir(4);
    vi rem(4);
    for(int i=0;i<n;i++){
      if(s[i] == 'N'){
        dir[0]++;
      }
      else if(s[i] == 'S'){
        dir[1]++;
      }
      else if(s[i] == 'E'){
        dir[2]++;
      }
      else if(s[i] == 'W'){
        dir[3]++;
    }
    }
     for(int i=0;i<4;i++){
        rem[i]=dir[i]%2; 
        dir[i]=dir[i]/2;
      } 
          int no=0;
          int so=0;
          int e=0;
          int w=0;
    int flag=0;
    int set=0;
    if((rem[0] == rem[1]) && (rem[2] == rem[3]) && (n > 2)){
        for(int i=0;i<n;i++){
          if((s[i] == 'N') && (no == 0) && (dir[0])){
            cout << "R";
            no+=1;
          }
          else if((s[i] == 'N') && (no == 1)){
            cout << "H";
            no=0;
            dir[0]--;
          }
        else if((s[i] == 'S') && (so == 0) && (dir[1])){
            cout << "R";
            so+=1;
          }
          else if((s[i] == 'S') && (so == 1)){
            cout << "H";
            so=0;
            dir[1]--;
          }
        else if((s[i] == 'E') && (e == 0) && (dir[2])){
            cout << "R";
            e+=1;
          }
          else if((s[i] == 'E') && (e == 1)){
            cout << "H";
            e=0;
            dir[2]--;
          }
        else if((s[i] == 'W') && (w == 0) && (dir[3])){
            cout << "R";
            w+=1;
          }
          else if((s[i] == 'W') && (w == 1)){
            cout << "H";
            w=0;
            dir[3]--;
          }
         else {
          if(((s[i] == 'N') || (s[i] == 'S')) && (rem[0])){
            cout << "R";
          }
          if(((s[i] == 'W') || (s[i] =='E')) && (rem[2])){
            cout <<"H";
          }
          // if((set == 0)&&(flag == 0)){
          //   flag=1;
          //   cout << "H";
          // }
          // else if ((set == 0)&&(flag == 1)){
          //   flag=0;
          //   set=1;
          //   cout << "H"; 
          // }
          // else if((set == 1)&&(flag == 0)){
          //   flag=1;
          //   cout << "R";
          // }
          // else if((set == 1)&&(flag == 1)){
          //   flag=0;
          //   set=0;
          //   cout << "R";
          // }
        }
        }
      cout << endl;
      }
    else if((n == 2) && (s[1] == s[0])){
      cout << "RH" << endl;
    }
      else cout << "NO" << endl;
    }
}


