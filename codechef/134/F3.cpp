#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9+7
#define pb push_back
#define mp make_pair

typedef vector<long long int> vi;
typedef long long int ll;

void add_neighbours(pair<pair<int, int>, int> ele, int n, int m, queue<pair<pair<int, int>, int>>& q) {
    int i = ele.first.first.first;
    int j = ele.first.first.second;
    int turns = ele.first.second;
    if (i + 1 < n) {
        if (j + 1 < m) {
            q.push(mp(mp(i + 1, j + 1), turns + 1));
        }
        if (j - 1 >= 0) {
            q.push(mp(mp(i + 1, j - 1), turns + 1));
        }
    }
    if (i - 1 >= 0) {
        if (j + 1 < m) {
            q.push(mp(mp(i - 1, j + 1), turns + 1));
        }
        if (j - 1 >= 0) {
            q.push(mp(mp(i - 1, j - 1), turns + 1));
        }
    }

    if ((i == n - 1) || (i == 0) || (j == m - 1) || (j == 0)) {
        done[ele.second] =1;
    } 
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> grid(n, vector<int>(m));
        queue<pair<pair<pair<int, int>>, int>, int>> q;
        
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                grid[i][j] = s[j] - '0';
                if (grid[i][j] == 0) {
                    q.push(mp(mp(mp(i, j), 0),i*j));
                }
            }
        }
        
        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        bool done[n*m];
        int turns=0;
        while (!q.empty()) {
            auto ele = q.front();
            q.pop();
            if (!visited[ele.first.first.first][ele.first.first.second]) {
                add_neighbours(ele, n, m, q, done);
                visited[ele.first.first.first][ele.first.first.second] = true;
                if(! done[ele.first.first.first*ele.first.first.second]){
                ans = max(ans, ele.first.second);
              }
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
