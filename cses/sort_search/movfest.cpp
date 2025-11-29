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

  int n;
  cin >> n;
  int end=0;
  int start=0;
  int count=0;
  for(int i=0;i<n;i++){
    int x,y;
    cin >> x >> y;
    if(y < end && x >= start){
      y = end;
    }
    if(x >= end){
      start = x;
      end = y;
      count++;
    }
    
  }
  cout << count << endl;
}


