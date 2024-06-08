#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

#define mp make_pair

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vi v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n, INT_MAX);

        pq.push(mp(0, 0));
        dist[0] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (int i = 0; i < n; i++) {
                if (i != u) {
                    int weight = abs(i - u) * max(v[i], v[u]);
                    if (weight + dist[u] < dist[i]) {
                        dist[i] = weight + dist[u];
                        pq.push(mp(dist[i], i));
                    }
                }
            }
        }

        cout << dist[n - 1] << endl;
    }

    return 0;
}
