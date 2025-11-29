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
    ll l, r;
    cin >> l >> r;
    ll end = 100000;
    ll start = 0;
    ll mid;

    while(start <= end){
      mid = (end+start)/ 2;
      if(mid*(mid+1)/2 >= r - l && mid*(mid-1)/2 <= r - l){
        if(mid*(mid+1)/2 == r-l){
          mid++;
        }
        break;   
      }
      else{
        if(mid*(mid+1)/2 > r - l){
          end = mid;
        }
        else if(mid*(mid+1)/2 < r-l){
          start = mid;
        }
      }
    }
    cout << mid << endl;
  }

}


