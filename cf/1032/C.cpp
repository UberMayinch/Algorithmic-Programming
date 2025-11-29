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
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));

        int max_val = 0;
        pair<int, int> first_pos = {-1, -1};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                if (a[i][j] > max_val) {
                    max_val = a[i][j];
                    first_pos = {i, j};
                }
            }
        }

        unordered_set<int> diffRowCols;
        unordered_set<int> diffColRows;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == max_val) {
                    if (i != first_pos.first)
                        diffRowCols.insert(j);
                    if (j != first_pos.second)
                        diffColRows.insert(i);
                }
            }
        }
        // cout << diffColRows.size() << " " << diffRowCols.size() << endl;
        if (diffRowCols.size() <= 1 || diffColRows.size() <= 1) {
            cout << max_val-1 << endl;
        } else {
            cout << max_val << endl;
        }
    }
    return 0;
}
