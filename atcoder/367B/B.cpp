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

  string n;
  cin >> n;
  string s_new;
  for(int i=n.size()-1;i>=0;i--){
    if(n[i] == '0'){
      n[i]='\0';
    }
    else{
      break;
    }
  }
  for(int i=0;i<n.size();i++){
    if(n[i] == '.' && n[i+1] == '\0'){
      n[n.size()-1]='\0';
      break;
    }
  }
  cout << n;
}


