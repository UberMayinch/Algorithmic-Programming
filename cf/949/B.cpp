#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define mp make_pair
#define pii pair<int, int>
typedef vector<long long int> vi;
typedef long long int ll;

const ll MOD = 1e9 + 7;
vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        ll ans = n;
        ll big = n + m;
        ll small = max(0, n - m); 

        // Finding the most significant differing bit between big and ans
        ll pos_big = 0;
        bool found_big = false;
        for (int temp = ans, count = 0; temp > 0 || big > 0; temp >>= 1, big >>= 1, count++) {
            if ((temp & 1) == 0 && (big & 1) == 1) {
                pos_big = count;
                found_big = true;
            }
        }

        // Finding the most significant differing bit between small and ans
        ll pos_small = 0;
        bool found_small = false;
        for (int temp = ans, count = 0; temp > 0 || small > 0; temp >>= 1, small >>= 1, count++) {
            if ((temp & 1) == 0 && (small & 1) == 1) {
                pos_small = count;
                found_small = true;
            }
        }

        // Set the bits in ans according to the most significant differing bit
        if (found_big) {
            ans |= (1LL << (pos_big + 1)) - 1;
        }

        if (found_small) {
            ans |= (1LL << (pos_small + 1)) - 1;
        }

        cout << ans << endl;
    }
    return 0;
}
