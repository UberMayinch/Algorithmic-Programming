#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string S;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        cin >> S;
        for (int j = 0; j < S.size(); j++)
        {
            if (S[j] == '#')
            {
                grid[i][j] = -1;
            }
            else if (S[j] == '*')
                grid[i][j] = 0;
        }
    }

    int counter = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                queue<pii> q;
                q.push(mp(i, j));
                while (!q.empty())
                {
                    ll x = q.front().first;
                    ll y = q.front().second;
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        ll dx = x + dxy[i][0];
                        ll dy = y + dxy[i][1];
                        if (dx < n && dx >= 0 && dy < m && dy >= 0)
                        {
                            if (grid[dx][dy] == 0)
                            {
                                q.push(mp(dx, dy));
                                grid[dx][dy] = counter;
                            }
                        }
                    }
                }
                counter++;
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }

    cout << counter - 1 << endl;
}