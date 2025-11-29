#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<ll> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        // To store the ranges of points covered by different segment counts
        map<ll, ll> segment_count;

        // Step 1: Calculate the number of points between consecutive points
        vector<ll> lengths;
        for (int i = 0; i < n - 1; i++) {
            lengths.push_back(x[i + 1] - x[i] - 1);
        }

        // Step 2: Use the lengths to populate the segment_count map
        ll total_pairs = (n * (n - 1)) / 2;  // Total number of segments

        // We will sweep over the segment lengths
        for (ll len : lengths) {
            if (len > 0) {
                segment_count[1] += len;
                segment_count[len + 1] -= len;
            }
        }

        // Now we accumulate the counts in sorted order
        vector<pair<ll, ll>> sorted_segments(segment_count.begin(), segment_count.end());
        sort(sorted_segments.begin(), sorted_segments.end());

        // Step 3: Calculate prefix sums to determine how many points are covered exactly k times
        ll prev_count = 0, prev_k = 0;
        map<ll, ll> exact_segment_coverage;
        for (auto &[k, change] : sorted_segments) {
            exact_segment_coverage[prev_k] += (k - prev_k) * prev_count;
            prev_count += change;
            prev_k = k;
        }

        // Step 4: Answer the queries
        for (int i = 0; i < q; i++) {
            ll k;
            cin >> k;
            cout << exact_segment_coverage[k] << " ";
        }
        cout << endl;
    }
}
