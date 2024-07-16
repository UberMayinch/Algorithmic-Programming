#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                grid[i][j] = s[j];
            }
        }
        int x = -1, y = -1, count = 0;
        for (int i = 0; i < n && x == -1; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '#') {
                    x = j + 1;
                    y = i + 1;
                    while (i < n && grid[i][j] == '#') {
                        i++;
                        count++;
                    }
                    break;
                }
            }
        }
        if (x != -1) {
            cout << y + count / 2 << " " << x << endl;
        }
    }
    return 0;
}
