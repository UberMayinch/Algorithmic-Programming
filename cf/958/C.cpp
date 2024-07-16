#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
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
    while (t--) {
        long long int n;
        cin >> n;
        long long int cp = n;
        vi ans;
        ans.pb(n);
        long long int sub = 1;
        while (cp) {
            if (cp % 2) {
                if(n - sub > 0)
                ans.pb(n - sub);
            }
            sub *= 2;
            cp /= 2;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto it : ans) {
            if(it > 0){
            cout << it << " ";}
        }
        cout << endl;
    }
}
