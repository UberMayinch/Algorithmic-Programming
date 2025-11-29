#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // Initialize grid
        vector<vector<ll>> grid(n, vector<ll>(n, 0));

        int x = n / 2;
        int y = n / 2;
        ll val = 0;
        grid[x][y] = val++;

        const vector<pair<int,int>> dxy = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        int step = 1;
        
        while (val < (ll)n * n) {
            for (int dir = 0; dir < 4 && val < (ll)n * n; ++dir) {
                int dx = dxy[dir].first;
                int dy = dxy[dir].second;
                int legs = (dir % 2 == 0 ? step : step);
                for (int i = 0; i < legs && val < (ll)n * n; ++i) {
                    x += dx;
                    y += dy;
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        grid[x][y] = val++;
                    }
                }
                if (dir == 1 || dir == 3) {
                    ++step;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << grid[i][j] << (j + 1 < n ? ' ' : '\n');
            }
        }
    }
    return 0;
}
