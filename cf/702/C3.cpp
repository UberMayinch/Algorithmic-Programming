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


    unordered_set<ll> cubes;
    const ll LIMIT = 1e12;

    for (ll x = 1; x < 10000; x++) {
        for (ll y = 1; y < 10000; y++) {
            ll z = (x+y);
            ll b = x*y;
            ll value = z*z*z - 3*b*z;
            if (value > LIMIT) break;
            cubes.insert(value);
        }
    }

  for(auto it: cubes){
    cout << it << ",";
  }

    return 0;
}

