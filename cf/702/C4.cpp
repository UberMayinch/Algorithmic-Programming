#include <bits/stdc++.h>
using namespace std;

#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;

    set<ll> cubes;
    for (ll i = 1; i <= 10000; ++i) {
        cubes.insert(i * i * i);
    }

    while (t--) {
        ll n;
        cin >> n;
        bool flag = false;

        for (auto it : cubes) {
            if (it >= n) break;
            if (cubes.find(n - it) != cubes.end()) {
                flag = true;
                break;
            }
        }

        if (flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
