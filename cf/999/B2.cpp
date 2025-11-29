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
        int n;
        cin >> n;
        vi v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        ll mx = -1;
        ll mx_i = -1;
        ll mn = (ll)1e9;
        ll mn_i = -1;

        for (int i = 0; i < n - 1; i++)
        {
            if (i < n - 1 && v[i] == v[i + 1])
            {
                mx = v[i];
                mx_i = i;
            }
        }
        // cout << mx_i << endl;

        if (mx_i != -1)
        {
            v.erase(v.begin() + mx_i);
            v.erase(v.begin() + mx_i);

            for (int i = 0; i < v.size() - 1; i++)
            {
                if (v[i + 1] - v[i] < mn)
                {
                    mn = v[i + 1] - v[i];
                    mn_i = i;
                }
            }

            if ((mn * mn) < 4 * mx * mx)
            {
                cout << v[mn_i] << " " << v[mn_i + 1] << " " << mx << " " << mx << " " << endl;
            }
            else
                cout << -1 << endl;
        }
        else
            cout << -1 << endl;
    }
}