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

    int max_n = 200000;
    vector<int> pows(max_n + 1, 0);
    for (int i = 1; i <= max_n; ++i) {
        int power = 0;
        int val = 1;
        while (val <= i) {
            ++power;
            val *= 3;
        }
        pows[i] = power - 1;
    }

    vector<ll> prefix_sum(max_n + 1, 0);
    for (int i = 1; i <= max_n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + pows[i];
    }

    ll t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        
        ll sum = 2 * (1 + pows[l]);
        sum += prefix_sum[r] - prefix_sum[l];
        sum += (r - l); 
        
        cout << sum << endl;
    }

    return 0;
}
