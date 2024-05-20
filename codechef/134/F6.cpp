#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9+7
#define pb push_back
#define mp make_pair

typedef vector<long long int> vi;
typedef long long int ll;

void add_neighbours(pair<pair<pair<int, int>, int>, int> ele, int n, int m, vector<vector<int>>& grid, queue<pair<pair<pair<int, int>, int>, int>>& q, vector<bool>& done, int& ans) {
    int i = ele.first.first.first;
    int j = ele.first.first.second;
    int turns = ele.first.second;

    if (i + 1 < n) {
        if (j + 1 < m) {
            if (grid[i + 1][j + 1] == 0) {
                q.push(mp(mp(mp(i + 1, j + 1), turns), ele.second));
            } else {
                q.push(mp(mp(mp(i + 1, j + 1), turns + 1), ele.second));
            }
        }
        if (j - 1 >= 0) {
            if (grid[i + 1][j - 1] == 0) {
                q.push(mp(mp(mp(i + 1, j - 1), turns), ele.second));
            } else {
                q.push(mp(mp(mp(i + 1, j - 1), turns + 1), ele.second));
            }
        }
    }
    if (i - 1 >= 0) {
        if (j + 1 < m) {
            if (grid[i - 1][j + 1] == 0) {
                q.push(mp(mp(mp(i - 1, j + 1), turns), ele.second));
            } else {
                q.push(mp(mp(mp(i - 1, j + 1), turns + 1), ele.second));
            }
        }
        if (j - 1 >= 0) {
            if (grid[i - 1][j - 1] == 0) {
                q.push(mp(mp(mp(i - 1, j - 1), turns), ele.second));
            } else {
                q.push(mp(mp(mp(i - 1, j - 1), turns + 1), ele.second));
            }
        }
    }

    if ((i == n - 1) || (i == 0) || (j == m - 1) || (j == 0)) {
        if (!done[i * m + j]) {
            ans = max(ans, turns);
            cout << ans << " " << i << " " << j << " " << endl;
            done[i * m + j] = true;
        }
    }
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> grid(n, vector<int>(m));
        queue<pair<pair<pair<int, int>, int>, int>> q;
        
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                grid[i][j] = s[j] - '0';
                if (grid[i][j] == 0) {
                    q.push(mp(mp(mp(i, j), 0), i * m + j));
                }
            }
        }
        
        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<bool> done(n * m, false);

        while (!q.empty()) {
            auto ele = q.front();
            q.pop();
            if (!visited[ele.first.first.first][ele.first.first.second]) {
                add_neighbours(ele, n, m, grid, q, done, ans);
                visited[ele.first.first.first][ele.first.first.second] = true;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
