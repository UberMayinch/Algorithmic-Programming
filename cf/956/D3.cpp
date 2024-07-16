#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool check_permutation(const vi& apref, const vi& bpref, const vi& cpref, int n, vi& ans, int sum) {
    for (int i = 1; i <= n; i++) {
        if (apref[i] >= sum) {
            ans[0] = 1;
            ans[1] = i;
            break;
        }
    }
    if (ans[1] != -1) {
        for (int i = ans[1] + 1; i <= n; i++) { 
            if (bpref[i] - bpref[ans[1]] >= sum) {
                ans[2] = ans[1] + 1;
                ans[3] = i;
                break;
            }
        }
    }
    if (ans[3] != -1) {
        for (int i = ans[3] + 1; i <= n; i++) { 
            if (cpref[i] - cpref[ans[3]] >= sum) {
                ans[4] = ans[3] + 1;
                ans[5] = i;
                break;
            }
        }
    }
    return ans[5] != -1 && ans[0] != -1 && ans[1] != -1 && ans[2] != -1 && ans[3] != -1 && ans[4] != -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n), b(n), c(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        vi apref(n + 1, 0), bpref(n + 1, 0), cpref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            apref[i + 1] = apref[i] + a[i];
            bpref[i + 1] = bpref[i] + b[i];
            cpref[i + 1] = cpref[i] + c[i];
        }

        int sum = (accumulate(a.begin(), a.end(), 0LL) +2) / 3;
        vi ans(6, -1);
        bool found = false;

        vector<tuple<vi, vi, vi>> permutations = {
            {apref, bpref, cpref},
            {apref, cpref, bpref},
            {bpref, apref, cpref},
            {bpref, cpref, apref},
            {cpref, apref, bpref},
            {cpref, bpref, apref}
        };

        tuple<vi, vi, vi> permutation;
        for (auto& p : permutations) {
            fill(ans.begin(), ans.end(), -1);
            if (check_permutation(get<0>(p), get<1>(p), get<2>(p), n, ans, sum)) {
                found = true;
                permutation = p;
                break;
            }
        }

        if (found) {
            if (permutation == make_tuple(apref, bpref, cpref)) {
                cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << " " << ans[5];
            } else if (permutation == make_tuple(apref, cpref, bpref)) {
                cout << ans[0] << " " << ans[1] << " " << ans[4] << " " << ans[5] << " " << ans[2] << " " << ans[3];
            } else if (permutation == make_tuple(bpref, apref, cpref)) {
                cout << ans[2] << " " << ans[3] << " " << ans[0] << " " << ans[1] << " " << ans[4] << " " << ans[5];
            } else if (permutation == make_tuple(bpref, cpref, apref)) {
                cout << ans[2] << " " << ans[3] << " " << ans[4] << " " << ans[5] << " " << ans[0] << " " << ans[1];
            } else if (permutation == make_tuple(cpref, apref, bpref)) {
                cout << ans[4] << " " << ans[5] << " " << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3];
            } else if (permutation == make_tuple(cpref, bpref, apref)) {
                cout << ans[4] << " " << ans[5] << " " << ans[2] << " " << ans[3] << " " << ans[0] << " " << ans[1];
            }
        } else {
            cout << "-1";
        }
        cout << endl;
    }
}
