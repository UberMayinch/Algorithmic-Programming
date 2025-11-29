#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<vector<ll>> grid(n, vector<ll>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        vi sum_r(n);
        vi sum_c(m);
        for (int i = 0; i < n; i++)
        {
            sum_r[i] = accumulate(grid[i].begin(), grid[i].end(), 0LL);
        }
        for (int j = 0; j < m; j++)
        {
            sum_c[j] = 0;
            for (int i = 0; i < n; i++)
            {
                sum_c[j] += grid[i][j];
            }
        }
        int row = 0;
        int col = 0;
        for (int idx = 0; idx < s.size(); idx++)
        {
            if (s[idx] == 'D')
            {
                grid[row][col] = -sum_r[row];
                sum_c[col] -= sum_r[row];
                row++;
            }
            else if (s[idx] == 'R')
            {
                grid[row][col] = -sum_c[col];
                sum_r[row] -= sum_c[col];
                col++;
            }
        }
        grid[n-1][m-1]=-(sum_r[n-1]);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
    }
}