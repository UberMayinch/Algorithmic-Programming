#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    if(n == 6){
        cout << "1 1 2 3 1 2" << endl;
    }
    if(n == 7){
        cout << "1 1 2 3 1 2 2" << endl;
    }
    if(n == 8){
        cout << "1 1 2 3 1 7 2 2" << endl;
    }
    else if(n >= 9 && n < 15){
        vi ans = {2, 3, 3, 2, 1, 3, 2, 2, 3};
        for(int i=9;i<n;i++){
            ans.push_back(i+1);
        }
        for(auto it: ans){
            cout << it << " ";
        }
        cout << endl;
    }
    else if(n >= 15){
        vi ans = {2, 3, 3, 3, 2, 5, 3, 1, 2, 5, 3 ,2, 2, 2, 3};
        for(int i=15;i<n;i++){
            ans.push_back(i+1);
        }
        for(auto it: ans){
            cout << it << " ";
        }
        cout << endl;
    }
    
  }
}