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
  vi sq;
  for(int i=0;i<1000;i++){
    sq.pb((2*i+1)*(2*i+1));
  }
  while(t--) {
    int n;
    cin >> n;
    vi v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int sum = 0;
    int count =0;
    for(int i=0;i<n;i++){
        sum +=v[i];
        if (find(sq.begin(), sq.end(), sum) != sq.end()) {
            count++;
        }
    }
    cout << count << endl;
    
  }
}