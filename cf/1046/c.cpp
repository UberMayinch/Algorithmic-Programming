
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

struct Interval {
    int start, end, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        vector<vector<int>> pos(n+1);
        for (int i = 1; i <= n; ++i) pos[a[i]].push_back(i);

        vector<Interval> intervals;
        for (int v = 1; v <= n; ++v) {
            int cnt = (int)pos[v].size();
            if (cnt < v) continue;
            for (int j = 0; j + v - 1 < cnt; ++j) {
                int s = pos[v][j];
                int e = pos[v][j+v-1];
                intervals.push_back({s, e, v});
            }
        }

        // for(auto it: intervals){
        //     cout << it.start << " " << it.end << " " << it.w << endl;
        // }

        sort(intervals.begin(), intervals.end(), [](auto &A, auto &B) {
            if (A.end != B.end) return A.end < B.end;
            return A.start < B.start;
        });

        int m = (int)intervals.size();
        vector<int> ends(m);
        for (int i = 0; i < m; ++i) ends[i] = intervals[i].end;

        vector<ll> dp(m+1, 0); 
        for (int i = 1; i <= m; ++i) {
            int s = intervals[i-1].start;
            int w = intervals[i-1].w;
            int prev = (int)(upper_bound(ends.begin(), ends.begin() + (i-1), s - 1) - ends.begin());
            // cout << prev << " ";
            dp[i] = max(dp[i-1], dp[prev] + w);
        }

        cout << dp[m] << endl;
    }
    return 0;
}