#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
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
    int a,b,c;
    cin >> a >> b >> c;
  int flag=0;
    while(b != c){
    b++;
    if(b == 24){
      b=0;
    }
    if(b == a){
      flag=1;
      cout <<"No"<< endl;
      break;
    }
  }
    if(!flag){
      cout << "Yes" << endl;
    }

}


